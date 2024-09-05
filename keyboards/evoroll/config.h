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

// UART の設定 (左右通信の設定)
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP12
#define SERIAL_USART_RX_PIN GP13

// SPI の設定
#define SPI_DRIVER SPID1           // SPID0 or SPID1
#define SPI_SCK_PIN GP14           // SCK (SCLK)
#define SPI_MOSI_PIN GP15          // MOSI (TX)
#define SPI_MISO_PIN GP8           // MISO (RX)
#define POINTING_DEVICE_CS_PIN GP9 // NCS (Chip Select)

// // MOTION_PIN の設定 (スレーブ側にトラックボールがあるときには意味がないため、設定していない)
// #define POINTING_DEVICE_MOTION_PIN GP11
// #define POINTING_DEVICE_MOTION_PIN_ACTIVE_LOW

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

// X軸を反転する
#define POINTING_DEVICE_INVERT_X
// -32767~32767 の範囲にする (デフォルトは -127~127)
#define MOUSE_EXTENDED_REPOROT

#define PMW33XX_LIFTOFF_DISTANCE 0x00

// 変更したら、スレーブ側にも書き込む必要がある
#define ROTATIONAL_TRANSFORM_ANGLE 0

// #define MASTER_RIGHT