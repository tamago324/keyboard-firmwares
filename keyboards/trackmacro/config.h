/*
Copyright 2022 tamago324

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define DEBOUNCE 50

// SPI の設定
#define SPI_DRIVER SPID1    // SPID0 or SPID1
#define SPI_SCK_PIN GP14     // SCK (SCLK)
#define SPI_MOSI_PIN GP15    // MOSI (TX)
#define SPI_MISO_PIN GP12    // MISO (RX)
#define POINTING_DEVICE_CS_PIN GP13 // NCS (Chip Select)

// // MOTION_PIN の設定
// #define POINTING_DEVICE_MOTION_PIN GP11
// #define POINTING_DEVICE_MOTION_PIN_ACTIVE_LOW

// X軸を反転する
#define POINTING_DEVICE_INVERT_X
// -32767~32767 の範囲にする (デフォルトは -127~127)
#define MOUSE_EXTENDED_REPOROT