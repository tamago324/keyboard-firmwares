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

#pragma once

#include "quantum.h"

enum custom_keycodes {
    // 垂直 (縦) スクロール
    DRAG_SCROLL_VERTICAL = SAFE_RANGE,
    // 縦スクロールのトグル
    SCRL_V_TG,
    // 縦スクロールON
    SCRL_V_ON,
    // 水平 (横) スクロール
    DRAG_SCROLL_HORIZONTAL,
    // BTN1 or スクロールOFF
    BTN1_OR_SCRL_OFF,
    MY_SAFE_RANGE,
};

void set_scroll_horizontal(bool on);