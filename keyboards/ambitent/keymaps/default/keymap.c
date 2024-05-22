#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

/* keymap */
#define L1_ENT LT(1,KC_ENT)
#define L2_TAB LT(2,KC_TAB)
#define L3_SPC LT(3,KC_SPC)
#define MS_SLSH MT(MOD_RSFT,KC_SLSH)
#define MC_MINS MT(MOD_RCTL,KC_MINS)
#define S_SCLN S(KC_SCLN)
#define S_MINS S(KC_MINS) 
#define MS_Z MT(MOD_LSFT,KC_Z)
#define MA_CAPS MT(MOD_LALT,KC_CAPS)
#define MG_DEL MT(MOD_LGUI,KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TD(0),   KC_W,    KC_E,    KC_R,    KC_T,           KC_QUOT, KC_RBRC, KC_END,                  KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_LBRC, KC_APP,  KC_PGUP, KC_RGHT,        KC_H,   KC_J,    KC_K,     KC_L,    MC_MINS,
        MS_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_HOME, KC_PGDN, KC_ENT,  KC_UP,          KC_N,   KC_M,    TD(1),    TD(2),   MS_SLSH,
                          MA_CAPS, L3_SPC,  MG_DEL,                  KC_LEFT, KC_DOWN, KC_CALC,        KC_BSPC,L1_ENT,  L2_TAB
    ),      
    [1] = LAYOUT(       
        S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),        KC_PGUP, KC_RGHT, KC_PGDN,                 S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_UP,   KC_ENT,  KC_DOWN, KC_BSPC,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        _______, _______, S_MINS,  S_SCLN,  KC_EQL,         KC_HOME, KC_LEFT, KC_END,  KC_ENT,         KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______,
                          _______, _______, _______,                 KC_APP,  KC_LALT, _______,        _______, _______, _______
    ),      
    [2] = LAYOUT(       
        _______, _______, _______, _______, _______,        RGB_M_P, RGB_M_B, RGB_M_R,                 _______, _______, KC_INT3, _______, _______,
        _______, _______, _______, _______, _______,        RGB_M_SW,RGB_M_K, RGB_M_TW,RGB_HUD,        KC_LBRC, KC_RBRC, _______, _______, _______,
        KC_LSFT, KC_CAPS, _______, _______, _______,        _______, _______, RGB_TOG, RGB_HUI,        _______, KC_APP,  KC_SLSH, _______, _______,
                          _______, _______, _______,                 RGB_MOD, RGB_RMOD,QK_BOOT,        _______, _______, _______
    ),              
    [3] = LAYOUT(       
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          _______, _______, KC_RBRC,                 _______, KC_PGUP, KC_UP,   KC_PGDN, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,         _______, _______, _______, S(KC_0),        KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        KC_LSFT, KC_F11,  KC_PSCR, KC_SCRL, KC_PAUS,        KC_LBRC, _______, _______, _______,        KC_END,  _______, _______, KC_SCLN, KC_QUOT,
                          _______, _______, _______,                 S(KC_9), _______, _______,        _______, _______, _______
    ),      
    [4] = LAYOUT(       
        _______, _______, _______, _______, _______,        KC_BTN2, KC_MS_R, _______,                 _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,        KC_MS_U, KC_MS_D, _______, KC_BTN3,        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,        KC_WBAK, KC_MS_L, KC_WFWD, KC_BTN1,        _______, _______, _______, _______, _______,
                          _______, _______, _______,                 KC_WH_U, KC_WH_D, _______,        _______, _______, _______
    ),      
    [5] = LAYOUT(       
        _______, _______, _______, _______, _______,        KC_P7,   KC_P8,   KC_P9,                   _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,        KC_P4,   KC_P5,   KC_P6,   TD(5),          _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,        KC_P1,   KC_P2,   KC_P3,   TD(4),          _______, _______, _______, _______, _______,
                          _______, _______, _______,                 KC_P0,   TD(3),   KC_CALC,        _______, _______, _______
    )
};

// RGBLayer setting
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_RED});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_BLUE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_GREEN});
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_CYAN});
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_ORANGE});
const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_YELLOW});
const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_MAGENTA});

const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layerNL_layer,
    my_layerCL_layer,
    my_layer5_layer,
    my_layer4_layer,
    my_layer3_layer,
    my_layer2_layer,
    my_layer1_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;

    // vial tap dance
    vial_tap_dance_entry_t td0 = { KC_Q,    KC_LCTL, KC_ESC,  KC_Q,    180}; dynamic_keymap_set_tap_dance(0, &td0);
    vial_tap_dance_entry_t td1 = { KC_COMM, KC_RCTL, KC_SCLN, KC_SCLN, 180}; dynamic_keymap_set_tap_dance(1, &td1);
    vial_tap_dance_entry_t td2 = { KC_DOT,  KC_RALT, KC_COLN, KC_COLN, 180}; dynamic_keymap_set_tap_dance(2, &td2);
    vial_tap_dance_entry_t td3 = { KC_DOT,  MO(1),   KC_COLN, KC_COLN, 180}; dynamic_keymap_set_tap_dance(3, &td3);
    vial_tap_dance_entry_t td4 = { KC_PLUS, MO(2),   KC_PAST, KC_PAST, 180}; dynamic_keymap_set_tap_dance(4, &td4);
    vial_tap_dance_entry_t td5 = { KC_PMNS, MO(3),   KC_PSLS, KC_PSLS, 180}; dynamic_keymap_set_tap_dance(5, &td5);        
};

//numpad layer idletime
#define NUMPAD_IDLE_TIME 30000
static bool numpad_active = false;
static uint16_t idle_timer = 0;

void numpad_task(void) {
    if (numpad_active && timer_expired(timer_read(), idle_timer)) {
        layer_clear();
        numpad_active = false;
    }
}

void numpad_reset_idle_timer(int numpad_idle_time) {
    idle_timer = timer_read() + numpad_idle_time;
}

// LayerIndicator & numpad layer idletime
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(6, layer_state_cmp(state, 1));
    rgblight_set_layer_state(5, layer_state_cmp(state, 2));
    rgblight_set_layer_state(4, layer_state_cmp(state, 3));
    rgblight_set_layer_state(3, layer_state_cmp(state, 4));
    rgblight_set_layer_state(2, layer_state_cmp(state, 5));
    
    switch (get_highest_layer(state)) {
    case 4:
        if (!numpad_active) {
            numpad_reset_idle_timer(NUMPAD_IDLE_TIME);
        }
        numpad_active = true;        
        break;
    case 5:
        if (!numpad_active) {
            numpad_reset_idle_timer(NUMPAD_IDLE_TIME);
        }
        numpad_active = true;
        break;
    default: //  for any other layers, or the default layer
        numpad_active = false;
        break;
    }

    return state;
};

// LockIndicator
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        rgblight_set_layer_state(0, !led_state.num_lock);
        rgblight_set_layer_state(1, led_state.caps_lock);
    }
    return res;
};

// CAPS WORD Indicator
void caps_word_set_user(bool active) {
    if (active) {
        rgblight_set_layer_state(1, active);
    } else {
        rgblight_set_layer_state(1, active);
    }
}

// ENCODER
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(TO(4), TO(5))},
    [1] = { ENCODER_CCW_CW(G(KC_TAB), LSG(KC_TAB))},
    [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [3] = { ENCODER_CCW_CW(A(KC_TAB), LSA(KC_TAB))},
    [4] = { ENCODER_CCW_CW(_______, TO(0))},
    [5] = { ENCODER_CCW_CW(TO(0), _______)},

};
#endif

// LED setting Fanction
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && numpad_active) {
        if (keycode >= KC_A && keycode <= KC_Z) {
            numpad_reset_idle_timer(0);
        } else {
            numpad_reset_idle_timer(NUMPAD_IDLE_TIME);
        }
      } 
    return true;
};