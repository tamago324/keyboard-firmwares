#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_BTN1, KC_BTN2, _______
    )
};


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    return mouse_report; 
}