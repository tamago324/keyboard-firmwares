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
#define SPI_DRIVER SPID0               // SPID0 or SPID1
#define SPI_SCK_PIN GP2                // SCK
#define SPI_MOSI_PIN GP3               // MOSI (TX)
#define SPI_MISO_PIN GP0               // MISO (RX)
#define CIRQUE_PINNACLE_SPI_CS_PIN GP1 // SS (CSn)

#define CIRQUE_PINNACLE_DIAMETER_MM 40                                        // トラックパッドの直径
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X // トラックパッドの感度 (デフォルト: EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X)

// 相対モード
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
// タップで左クリックを有効
#define CIRQUE_PINNACLE_TAP_ENABLE
// 右隅をタップすると右クリックになる
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
// 円形スクロール
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

// -- from polykybd (https://github.dev/thpoll83/qmk_firmware/tree/0e7205e1a76f487ed9e82c414f0a3fc453c16aee/keyboards/handwired/polykybd/split72/rp2040pico) --
// センサーのポーリングを制限 (デフォルト 10)
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

#define CIRQUE_PINNACLE_SPI_DIVISOR (CPU_CLOCK / 10000000) // rp1040 runs at 133Mhz, SPI at 10Mhz

#define CIRQUE_PINNACLE_CLOCK_SPEED 10000000