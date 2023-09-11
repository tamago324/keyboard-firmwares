#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
          KC_A
    )
};

void keyboard_pre_init_user(void) {
// void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     dprint("pointing_device_task_user called\n");
//     dprintf("X: %d, Y: %d, Buttons: %d\n", mouse_report.x, mouse_report.y, mouse_report.buttons);
//     return mouse_report;
// }


void pointing_device_init_user(void) {
  dprint("pointing_device_init_user called\n");
}