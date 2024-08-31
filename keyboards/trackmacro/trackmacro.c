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

#include "trackmacro.h"
#include "pointing_device.h"

user_config_t user_config;

// uint16_t angles[] = {-40, -30, -20, -10, 0, 10, 20, 30, 40};
// #define ANGLE_SIZE (sizeof(angles) / sizeof(uint16_t))
// #define ANGLE_DEFAULT 4

// GameBall は 400/800/1200/2000/3000
uint16_t cpi_options[] = {100, 200, 300, 400};
#define CPI_OPTIONS_SIZE (sizeof(cpi_options) / sizeof(uint16_t))
#define CPI_DEFAULT 1

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
    if (user_config.cpi_idx > CPI_OPTIONS_SIZE) {
        eeconfig_init_kb();
    }

    matrix_init_user();
}

void pointing_device_init_kb(void) {
    pointing_device_set_cpi(cpi_options[user_config.cpi_idx]);
    user_config.raw = eeconfig_read_kb();
    eeconfig_update_kb(user_config.raw);
}

/* スクロール */
bool scroll_mode = false;

bool get_scroll_mode(void) {
    return scroll_mode;
}

void set_scroll_mode(bool mode) {
    scroll_mode = mode;
}

// スクロール速度を調整
#define SCROLL_DIVISOR_H 12.0;
#define SCROLL_DIVISOR_V 12.0;

// 累積スクロール値
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    // 垂直スクロール
    if (scroll_mode) {
        // マウスの動きと除数に基づいてスクロールを計算する
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // 累積スクロール値の整数部分をマウスレポートに設定
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // 整数部分を減産して累積スクロール値を更新
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // カーソルが動かないようにする
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case DRAG_SCROLL:
            set_scroll_mode(record->event.pressed);
            break;
        default:
            break;
    }

    if (keycode == CPI_UP && record->event.pressed) {
        user_config.cpi_idx = (user_config.cpi_idx + 1) % CPI_OPTIONS_SIZE;
        eeconfig_update_kb(user_config.raw);
        pointing_device_set_cpi(cpi_options[user_config.cpi_idx]);
    }

    return true;
}