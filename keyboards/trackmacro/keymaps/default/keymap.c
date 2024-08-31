#include QMK_KEYBOARD_H
#include "progmem.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        DRAG_SCROLL_VERTICAL, ANGLE_UP, KC_A
    )
};
// clang-format on

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {}
