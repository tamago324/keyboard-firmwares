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

typedef union {
    uint64_t raw;
    struct {
        uint8_t angle_idx;
        uint8_t cpi_idx;
    };
} user_config_t;

extern user_config_t user_config;

enum custom_keycodes {
    // 垂直 (縦) スクロール
    DRAG_SCROLL_VERTICAL = SAFE_RANGE,
    // 水平 (横) スクロール
    DRAG_SCROLL_HORIZONTAL,
    ANGLE_UP,
    CPI_UP,
    MY_SAFE_RANGE,
};
