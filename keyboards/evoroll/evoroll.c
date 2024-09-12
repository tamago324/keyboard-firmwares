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
/* スクロール */
enum ScrollMode { HORIZONTAL, VERTICAL };
struct ScrollState {
    bool            enabled;
    enum ScrollMode mode;
};

struct ScrollState scroll_state;

// スクロール速度を調整
#define SCROLL_DIVISOR_H 20.0;
#define SCROLL_DIVISOR_V 20.0;

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

void toggle_scroll_vertical(void) {
    scroll_state.enabled = !scroll_state.enabled;
    scroll_state.mode    = VERTICAL;
}

void enable_scroll_vertical(void) {
    scroll_state.enabled = true;
    scroll_state.mode    = VERTICAL;
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    // スクロールモード中には文字入力はできないようにする
    if (scroll_state.enabled && IS_BASIC_KEYCODE(keycode)) {
        return false;
    }

    if (!process_record_user(keycode, record)) {
        return false;
    }

    switch (keycode) {
        // from: https://github.com/Yowkees/keyball/blob/ab40534f168bdc0d6baa69dabed4c82dfd4aaccc/qmk_firmware/keyboards/keyball/lib/keyball/keyball.c#L659
        // process KC_MS_BTN1~8 by myself
        // See process_action() in quantum/action.c for details.
        case KC_MS_BTN1 ... KC_MS_BTN8: {
            extern void register_mouse(uint8_t mouse_keycode, bool pressed);
            register_mouse(keycode, record->event.pressed);
            return false;
        }

        case BTN1_OR_SCRL_OFF:
            // auto mouse layer への移行
            // https://github.com/qmk/qmk_firmware/blob/b7729fa019833573b82d0742d9879388bfb6913c/quantum/pointing_device/pointing_device_auto_mouse.c#L406-L408
            auto_mouse_keyevent(record->event.pressed);

            // スクロールモードなら、OFFにする
            if (scroll_state.enabled) {
                scroll_state.enabled = false;
                return false;
            }

            // BTN1
            extern void register_mouse(uint8_t mouse_keycode, bool pressed);
            register_mouse(KC_MS_BTN1, record->event.pressed);
            return false;

        case DRAG_SCROLL_HORIZONTAL:
            set_scroll_horizontal(record->event.pressed);
            break;

        case DRAG_SCROLL_VERTICAL:
            scroll_state.enabled = record->event.pressed;
            scroll_state.mode    = VERTICAL;
            break;

        case SCRL_V_TG:
            if (record->event.pressed) {
                toggle_scroll_vertical();
            }
            return false;
            
        case SCRL_V_ON:
            if (record->event.pressed) {
                enable_scroll_vertical();
            }
            return false;

        default:
            break;
    }

    return true;
}
