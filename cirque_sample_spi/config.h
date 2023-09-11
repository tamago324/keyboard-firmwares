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

// I2C の設定
#define I2C_DRIVER I2CD0
#define I2C0_SCL_PIN GP9
#define I2C0_SDA_PIN GP8

// 任意だけど設定しておく
#define CIRQUE_PINNACLE_DIAMETER_MM 40 // トラックパッドの直径
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X	// トラックパッドの感度 (デフォルト: EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X)

// 相対モード
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
// タップで左クリックを有効
#define CIRQUE_PINNACLE_TAP_ENABLE
// 右隅をタップすると右クリックになる
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
// 円形スクロール
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE