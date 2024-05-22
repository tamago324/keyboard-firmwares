#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SPECIAL,
  _WIN,
  _LED,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  JU_SCLN,
  JU_QUOT,
  ALT_TAB,
  ALT_S_TAB,
  SPECIAL,
  LED,
};

enum combo_events {
  CMB_EQ_LEFT_ARROW,
  CMB_MINUS_LEFT_ARROW,
  CMB_MINUS_MINUS,
};


// =>
const uint16_t PROGMEM comb_keys_eq_left_arrow[] = {JP_EQL, JP_LBRC, COMBO_END};
// ->
const uint16_t PROGMEM comb_keys_minus_left_arrow[] = {JP_MINS, JP_LPRN, COMBO_END};
// --
const uint16_t PROGMEM comb_keys_minus_minus[] = {JP_MINS, JP_LBRC, COMBO_END};
// // -
// const uint16_t PROGMEM comb_keys_minus[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
  [CMB_EQ_LEFT_ARROW] = COMBO_ACTION(comb_keys_eq_left_arrow),
  [CMB_MINUS_LEFT_ARROW] = COMBO_ACTION(comb_keys_minus_left_arrow),
  [CMB_MINUS_MINUS] = COMBO_ACTION(comb_keys_minus_minus),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {

    case CMB_EQ_LEFT_ARROW:
      if (pressed) {
        tap_code16(JP_EQL);
        tap_code16(S(KC_DOT));
      }
      break;

    case CMB_MINUS_LEFT_ARROW:
      if (pressed) {
        tap_code16(JP_MINS);
        tap_code16(S(KC_DOT));
      }
      break;

    case CMB_MINUS_MINUS:
      if (pressed) {
        tap_code16(JP_MINS);
        tap_code16(JP_MINS);
      }
      break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
         KC_TAB,  KC_W,    KC_E, KC_R,        KC_T,        _______, _______, _______,             KC_Y, KC_U,  KC_I,    KC_O,    KC_BSPC,
  LCTL_T(KC_A),   KC_S,    KC_D, KC_F,        KC_G,        _______, _______, _______, _______,       KC_H, KC_J,  KC_K,    KC_L,    KC_P,
  LSFT_T(KC_Z),   KC_X,    KC_C, ALT_T(KC_V), KC_B,        _______, _______, _______, _______,     KC_N, KC_M,  KC_COMM, KC_DOT,  ALT_T(KC_Q),
                        _______, LOWER,  LCTL_T(KC_SPACE), _______, _______, _______,           SFT_T(KC_ENT), RAISE, LED
  ),
  [_LOWER] = LAYOUT(
      XXXXXXX, JP_AT,   KC_HASH, KC_DLR,  JP_CIRC,      _______, _______, _______,             JP_ASTR, JP_AMPR, JP_LPRN, JP_RPRN, S(KC_SLSH),
      KC_LCTL, KC_ESC, KC_BSPC, KC_ENT, KC_DELETE,      _______, _______, _______, _______,  KC_SLSH, JP_MINS,  JP_LBRC, JP_RBRC, XXXXXXX,
      OSL(_WIN), KC_TAB, ALT_S_TAB, ALT_TAB,  KC_EXLM,  _______, _______, _______, _______, JP_UNDS, JP_EQL, JP_LCBR, JP_RCBR, XXXXXXX,
                       _______,  _______, _______,      _______, _______, _______,                      SFT_T(LALT(KC_ENT)), _______, _______
  ),
  [_RAISE] = LAYOUT(
      XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX,               _______, _______, _______,             XXXXXXX,  XXXXXXX, JU_QUOT, JU_QUOT, KC_DELETE,
      KC_LSFT, KC_1, KC_2, KC_3, JP_COLN,               _______, _______, _______, _______,    KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, KC_DOT,
      KC_LSFT, KC_7, KC_8, KC_9, JU_SCLN,               _______, _______, _______, _______,    KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,  KC_COMM,
                       _______,  _______, CTL_T(KC_0),  _______, _______, _______,                   _______, _______, _______
  ),
  [_ADJUST] =  LAYOUT(
      XXXXXXX, KC_F2, KC_PERC, XXXXXXX, XXXXXXX,         _______, _______, _______,            XXXXXXX, XXXXXXX, JP_DQUO, JP_DQUO, XXXXXXX,
      KC_LCTL, JP_TILD, JP_PIPE, JP_BSLS, XXXXXXX,       _______, _______, _______, _______,   C(KC_PGUP), C(KC_DOWN), C(KC_UP), C(KC_PGDN), XXXXXXX,
      XXXXXXX, C(KC_SPACE), XXXXXXX, JP_GRV,  XXXXXXX,   _______, _______, _______, _______,    KC_F7, JP_PLUS,  KC_F10, XXXXXXX, XXXXXXX,
                     _______,  _______, _______,      _______, _______, _______,                _______, _______, _______
  ),
  [_SPECIAL] = LAYOUT(
    XXXXXXX, KC_F4, KC_F5, KC_F6, XXXXXXX,         _______, _______, _______,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    KC_LCTL, KC_F1, KC_F2, KC_F3, KC_F11,          _______, _______, _______, _______,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, KC_F7, KC_F8, KC_F9, XXXXXXX,         _______, _______, _______, _______,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                  _______, XXXXXXX, XXXXXXX,    _______, _______, _______,                     _______, _______, _______
  ),
  [_WIN] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     _______, _______, _______,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_BTN4, G(KC_D), KC_BTN5, KC_F12,      _______, _______, _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, G(KC_L), XXXXXXX,
    XXXXXXX,  KC_LGUI, SWIN(KC_S), G(KC_V), XXXXXXX, _______, _______, _______, _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, XXXXXXX,      _______, _______, _______,                    G(KC_ENT), _______, _______
  ),
  [_LED] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_M_P,  RGB_M_B, RGB_M_R,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_M_SW, RGB_M_K, RGB_M_TW, RGB_HUD,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    _______,  _______, RGB_TOG,  RGB_HUI,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX,               RGB_MOD, RGB_RMOD, _______,             XXXXXXX, XXXXXXX, _______
  ),
};

// // RGBLayer setting
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_RED});
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_BLUE});
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_GREEN});
// const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_CYAN});
// const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_ORANGE});
// const rgblight_segment_t PROGMEM my_layerCL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_YELLOW});
// const rgblight_segment_t PROGMEM my_layerNL_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_MAGENTA});

// const rgblight_segment_t * const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_layerNL_layer,
//     my_layerCL_layer,
//     my_layer5_layer,
//     my_layer4_layer,
//     my_layer3_layer,
//     my_layer2_layer,
//     my_layer1_layer
// );

// void keyboard_post_init_user(void) {
//     rgblight_layers = my_rgb_layers;

//     // vial tap dance
//     vial_tap_dance_entry_t td0 = { KC_Q,    KC_LCTL, KC_ESC,  KC_Q,    180}; dynamic_keymap_set_tap_dance(0, &td0);
//     vial_tap_dance_entry_t td1 = { KC_COMM, KC_RCTL, KC_SCLN, KC_SCLN, 180}; dynamic_keymap_set_tap_dance(1, &td1);
//     vial_tap_dance_entry_t td2 = { KC_DOT,  KC_RALT, KC_COLN, KC_COLN, 180}; dynamic_keymap_set_tap_dance(2, &td2);
//     vial_tap_dance_entry_t td3 = { KC_DOT,  MO(1),   KC_COLN, KC_COLN, 180}; dynamic_keymap_set_tap_dance(3, &td3);
//     vial_tap_dance_entry_t td4 = { KC_PLUS, MO(2),   KC_PAST, KC_PAST, 180}; dynamic_keymap_set_tap_dance(4, &td4);
//     vial_tap_dance_entry_t td5 = { KC_PMNS, MO(3),   KC_PSLS, KC_PSLS, 180}; dynamic_keymap_set_tap_dance(5, &td5);        
// };

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

// // LayerIndicator & numpad layer idletime
// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(7, layer_state_cmp(state, 1));
//     rgblight_set_layer_state(6, layer_state_cmp(state, 2));
//     rgblight_set_layer_state(5, layer_state_cmp(state, 3));
//     rgblight_set_layer_state(4, layer_state_cmp(state, 4));
//     rgblight_set_layer_state(3, layer_state_cmp(state, 5));
//     rgblight_set_layer_state(2, layer_state_cmp(state, 6));
    
//     switch (get_highest_layer(state)) {
//     case 4:
//         if (!numpad_active) {
//             numpad_reset_idle_timer(NUMPAD_IDLE_TIME);
//         }
//         numpad_active = true;        
//         break;
//     case 5:
//         if (!numpad_active) {
//             numpad_reset_idle_timer(NUMPAD_IDLE_TIME);
//         }
//         numpad_active = true;
//         break;
//     default: //  for any other layers, or the default layer
//         numpad_active = false;
//         break;
//     }

//     return state;
// };

// // LockIndicator
// bool led_update_kb(led_t led_state) {
//     bool res = led_update_user(led_state);
//     if(res) {
//         rgblight_set_layer_state(0, !led_state.num_lock);
//         rgblight_set_layer_state(1, led_state.caps_lock);
//     }
//     return res;
// };

// // CAPS WORD Indicator
// void caps_word_set_user(bool active) {
//     if (active) {
//         rgblight_set_layer_state(1, active);
//     } else {
//         rgblight_set_layer_state(1, active);
//     }
// }

// ENCODER
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(TO(4), TO(5))},
    [1] = { ENCODER_CCW_CW(G(KC_TAB), LSG(KC_TAB))},
    [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [3] = { ENCODER_CCW_CW(A(KC_TAB), LSA(KC_TAB))},
    [4] = { ENCODER_CCW_CW(_______, TO(0))},
    [5] = { ENCODER_CCW_CW(TO(0), _______)},
    [6] = { ENCODER_CCW_CW(TO(0), _______)},
};
#endif

// // LED setting Fanction
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed && numpad_active) {
//         if (keycode >= KC_A && keycode <= KC_Z) {
//             numpad_reset_idle_timer(0);
//         } else {
//             numpad_reset_idle_timer(NUMPAD_IDLE_TIME);
//         }
//       } 
//     return true;
// };

static bool lower_pressed = false;
static bool raise_pressed = false;
static bool zshift_pressed = false;
static bool alt_tab_pressed = false;
static bool alt_shift_tab_pressed = false;

// lower を長押ししたら単推しとしてみなさないようにするためのタイマー
static uint16_t lower_pressed_time = 0;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // 日本語配列の制御のためのもの
  // https://scrapbox.io/self-made-kbds-ja/QMK_Firmware_%E3%81%A7_JP_%E9%85%8D%E5%88%97%E3%81%AE%E3%82%AD%E3%83%BC%E3%83%9C%E3%83%BC%E3%83%89%E3%82%92%E4%BD%9C%E3%82%8B
  // https://discord.com/channels/376937950409392130/448305600372408326/576610674617221120
  // https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergo42/keymaps/hdbx/keymap.c
  static bool lshift = false;

  // LED setting Fanction
  if (record->event.pressed && numpad_active) {
      if (keycode >= KC_A && keycode <= KC_Z) {
          numpad_reset_idle_timer(0);
      } else {
          numpad_reset_idle_timer(NUMPAD_IDLE_TIME);
      }
    } 

  // lower で無変換、raise で変換
  // https://okapies.hateblo.jp/entry/2019/02/02/133953
  // https://gist.github.com/okapies/5d13a174cbb13ce34dbd9faede9d0b71#file-keymap-c-L99-L164
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        // LOWER を押した時間を保持しておく
        lower_pressed_time = record->event.time;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (alt_tab_pressed || alt_shift_tab_pressed) {
          // もし、Lower を離したときに、ALT が押しっぱになっていたら、離す
          unregister_code(KC_LALT);
          alt_tab_pressed = false;
          alt_shift_tab_pressed = false;
          // また、無変換は送信しない
          return false;
        }

        if (lower_pressed && TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM) {
          // もし、長押しをしていなければ、無変換を送信する
            tap_code(KC_INT5);
        }
        lower_pressed = false;
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        // update_tri_layer(_RAISE, _L1, _ALT_NUM);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        // update_tri_layer(_RAISE, _L1, _ALT_NUM);

        if (raise_pressed && TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM) {
            // https://docs.qmk.fm/#/ja/feature_macros?id=register_codeltkcgt
            // キーダウンイベント
            tap_code(KC_INT4);
            raise_pressed = false;
        }
      }

      return false;
      break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

    case SPECIAL:
      if (record->event.pressed) {
        layer_on(_SPECIAL);
      } else {
        layer_off(_SPECIAL);
      }

      return false;
      break;

    case LED:
      if (record->event.pressed) {
        layer_on(_LED);
      } else {
        layer_off(_LED);
      }
      return false;
      break;

    case JU_QUOT:
      // 単体で ' でShift通すと "
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        if (lshift) {
          // https://docs.qmk.fm/#/ja/feature_macros?id=register_code16ltkcgt%e3%80%81unregister_code16ltkcgt%e3%80%81tap_code16ltkcgt
          // ここ、tap_code16 とかでもいいのかな？
          if (lshift) unregister_code(KC_LSFT);
          register_code(KC_LSFT);
          register_code(KC_2);
          unregister_code(KC_2);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_7);
          unregister_code(KC_7);
          unregister_code(KC_LSFT);
        }
      }
      lower_pressed = false;
      raise_pressed = false;
      return false;
      break;

    case JU_SCLN:
      // 単体で ; でShift通すと :
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        if (lshift) {
          if (lshift) unregister_code(KC_LSFT);
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          if (lshift) register_code(KC_LSFT);
        } else {
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
        }
      }
      lower_pressed = false;
      raise_pressed = false;
      return false;
      break;

    case LSFT_T(KC_Z):
      if (record->event.pressed) {
        zshift_pressed = true;

        // LOWER でもRAISEでもない文字だった場合、戻しておく
        lower_pressed = false;
        raise_pressed = false;
      } else {
        zshift_pressed = false;
      }
      break;

    case KC_E:
    // case KC_O:
    // case KC_U:
    // case KC_I:
      // z と同時に押したら、zX にする
      if (record->event.pressed) {
          if (zshift_pressed) {
            lower_pressed = false;
            raise_pressed = false;
            zshift_pressed = false;

            // もし、Shift が押されていると認識したら、はなして Z を送信する (Z を2回送信しないようにするための処理)
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            if (lshift) {
              unregister_code(KC_LSFT);
              tap_code(KC_Z);
            }
            tap_code(keycode);
            return false;
          }
      }
      break;

    case ALT_TAB:
      if (record->event.pressed) {
        // 初めて押したら、Altを押し続ける
        // また、TAB も送信する
        if (!alt_tab_pressed || !alt_shift_tab_pressed) {
          lower_pressed = false;
          raise_pressed = false;
          zshift_pressed = false;

          alt_tab_pressed = true;

          // ALT を押し続ける
          register_code(KC_LALT);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;

    case ALT_S_TAB:
      if (record->event.pressed) {
        // 初めて押したら、Altを押し続ける
        // また、TAB も送信する
        if (!alt_tab_pressed || !alt_shift_tab_pressed) {
          lower_pressed = false;
          raise_pressed = false;
          zshift_pressed = false;

          alt_shift_tab_pressed = true;

          // ALT を押し続ける
          register_code(KC_LALT);
        }
        register_code16(S(KC_TAB));
      } else {
        unregister_code16(S(KC_TAB));
      }
      break;

    default:
      if (record->event.pressed) {
          // LOWER でもRAISEでもない文字だった場合、戻しておく
        lower_pressed = false;
        raise_pressed = false;
        zshift_pressed = false;
      }

      break;
  }

  return true;
}

// https://docs.qmk.fm/#/tap_hold?id=tapping-term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_Z):
            return TAPPING_TERM + 30;
            break;
        case SFT_T(KC_ENT):
            return TAPPING_TERM - 20;
            break;
        case ALT_T(KC_V):
            return TAPPING_TERM + 30;
            break;
        case LCTL_T(KC_SPACE):
            return TAPPING_TERM + 20;
            break;
        case LCTL_T(KC_A):
            return TAPPING_TERM + 50;
            break;
        case CTL_T(KC_0):
            return TAPPING_TERM + 10;
            break;
        default:
            return TAPPING_TERM;
            break;
    }
}

