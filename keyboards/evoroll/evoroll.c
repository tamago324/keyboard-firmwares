/* Copyright 2022 tamago324
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "evoroll.h"

#include "pointing_device.h"
// #include "sensors/pmw3360.h"
// #include "sensors/pmw33xx_common.h"

user_config_t user_config;

// GameBall は 400/800/1200/2000/3000
uint16_t cpi_options[] = {200, 300, 400};
#define CPI_OPTIONS_SIZE (sizeof(cpi_options) / sizeof(uint16_t))
#define CPI_DEFAULT 1

// // 角度調整
// int8_t angles[] = {25, 30, 35};
// #define ANGLE_SIZE (sizeof(angles) / sizeof(int8_t))
// #define ANGLE_DEFAULT 0

// void set_angle(int8_t data) {
//     pmw33xx_write(0, REG_Angle_Tune, CONSTRAIN(data, -127, 127));
// }

// EEPROM がリセットされたら、デフォルト値を書き込む
void eeconfig_init_kb(void) {
    // user_config.angle_idx = ANGLE_DEFAULT;
    user_config.cpi_idx = CPI_DEFAULT;

    eeconfig_update_kb(user_config.raw);
    eeconfig_init_user();
}

// matrix_init_kb はポインティングデバイスの初期化の前に呼び出される
void matrix_init_kb(void) {
    user_config.raw = eeconfig_read_kb();

    // 保存されている情報と合わなかったら初期化する
    // if (user_config.cpi_idx > CPI_OPTIONS_SIZE || user_config.angle_idx > ANGLE_SIZE) {
    if (user_config.cpi_idx > CPI_OPTIONS_SIZE) {
        eeconfig_init_kb();
    }

    matrix_init_user();
}

void pointing_device_init_kb(void) {
    pointing_device_set_cpi(cpi_options[user_config.cpi_idx]);
    // set_angle(angles[user_config.angle_idx]);

    user_config.raw = eeconfig_read_kb();
    eeconfig_update_kb(user_config.raw);
}

/* スクロール */
enum ScrollMode { HORIZONTAL, VERTICAL };
struct ScrollState {
    bool            enabled;
    enum ScrollMode mode;
};

struct ScrollState scroll_state;

// スクロール速度を調整
#define SCROLL_DIVISOR_H 16.0;
#define SCROLL_DIVISOR_V 14.0;

// 累積スクロール値
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    // スクロール
    if (scroll_state.enabled) {
        switch (scroll_state.mode) {
            case HORIZONTAL:
                scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
                // 右に転がすと、右にスクロールする
                mouse_report.h = ((int8_t)scroll_accumulated_h);
                scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
                mouse_report.v = 0;
                break;

            case VERTICAL:
                scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;
                // 上に転がすと上にスクロールするようにしている
                mouse_report.v = -((int8_t)scroll_accumulated_v);
                scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
                mouse_report.h = 0;
                break;

            default:
                break;
        }

        // カーソルが動かないようにする
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

void set_scroll_horizontal(bool on) {
    scroll_state.enabled = on;
    scroll_state.mode    = HORIZONTAL;
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case DRAG_SCROLL_HORIZONTAL:
            set_scroll_horizontal(record->event.pressed);
            break;

        case DRAG_SCROLL_VERTICAL:
            scroll_state.enabled = record->event.pressed;
            scroll_state.mode    = VERTICAL;
            break;

        case CPI_UP:
            if (record->event.pressed) {
                user_config.cpi_idx = (user_config.cpi_idx + 1) % CPI_OPTIONS_SIZE;
                eeconfig_update_kb(user_config.raw);
                pointing_device_set_cpi(cpi_options[user_config.cpi_idx]);
            }
            break;

            // case ANGLE_UP:
            //     if (record->event.pressed) {
            //         user_config.angle_idx = (user_config.angle_idx + 1) % ANGLE_SIZE;
            //         eeconfig_update_kb(user_config.raw);
            //         set_angle(angles[user_config.angle_idx]);
            //     }
            //     break;

        default:
            break;
    }

    return true;
}
