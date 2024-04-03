/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID { 0xFC, 0xCF, 0xA6, 0xCF, 0x1B, 0x18, 0x4A, 0xAF }
// Q と E を同時押しで unlock
// https://get.vial.today/docs/porting-to-vial.html#6-set-up-a-secure-unlock-combination
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

// レイヤーの上限を8にする
#define LAYER_STATE_8BIT

#define DYNAMIC_KEYMAP_LAYER_COUNT 8