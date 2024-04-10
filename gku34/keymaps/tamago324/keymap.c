/* Copyright 2022 tamago324
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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

// LCTL_T(KC_A) は Lower レイヤーのためのもの
// Lower の Ctrl をおそうとして、a が入力されるのを防ぐため
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
         KC_TAB,  KC_W,    KC_E, KC_R,        KC_T,    KC_Y, KC_U,  KC_I,    KC_O,    KC_BSPC,
  LCTL_T(KC_A),   KC_S,    KC_D, KC_F,        KC_G,    KC_H, KC_J,  KC_K,    KC_L,    KC_P,
  LSFT_T(KC_Z),   KC_X,    KC_C, ALT_T(KC_V), KC_B,    KC_N, KC_M,  KC_COMM, KC_DOT,  ALT_T(KC_Q),
                                  LOWER,  LCTL_T(KC_SPACE),          SFT_T(KC_ENT), RAISE
  ),
  [_LOWER] = LAYOUT(
      XXXXXXX, JP_AT,   KC_HASH, KC_DLR,  JP_CIRC,          JP_ASTR, JP_AMPR, JP_LPRN, JP_RPRN, S(KC_SLSH),
      KC_LCTL, KC_ESC, KC_BSPC, KC_ENT, KC_DELETE,        KC_SLSH, JP_MINS,  JP_LBRC, JP_RBRC, XXXXXXX,
      OSL(_WIN), KC_TAB, ALT_S_TAB, ALT_TAB,  KC_EXLM,   JP_UNDS, JP_EQL, JP_LCBR, JP_RCBR, XXXXXXX,
                                 _______, _______,                   SFT_T(LALT(KC_ENT)), _______
  ),
  [_RAISE] = LAYOUT(
      XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX,             XXXXXXX,  XXXXXXX, JU_QUOT, JU_QUOT, KC_DELETE,
      KC_LSFT, KC_1, KC_2, KC_3, JP_COLN,             KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, KC_DOT,
      KC_LSFT, KC_7, KC_8, KC_9, JU_SCLN,             KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,  KC_COMM,
                                 _______, CTL_T(KC_0),            _______, _______
  ),
  [_ADJUST] =  LAYOUT(
      XXXXXXX, KC_F2, KC_PERC, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, JP_DQUO, JP_DQUO, XXXXXXX,
      KC_LCTL, JP_TILD, JP_PIPE, JP_BSLS, XXXXXXX,    C(KC_PGUP), C(KC_DOWN), C(KC_UP), C(KC_PGDN), XXXXXXX,
      XXXXXXX, C(KC_SPACE), XXXXXXX, JP_GRV,  XXXXXXX,     KC_F7, JP_PLUS,  KC_F10, XXXXXXX, XXXXXXX,
                                  _______, _______,             _______, _______
  ),
  [_SPECIAL] = LAYOUT(
    XXXXXXX, KC_F4, KC_F5, KC_F6, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    KC_LCTL, KC_F1, KC_F2, KC_F3, KC_F11,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, KC_F7, KC_F8, KC_F9, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                              XXXXXXX, XXXXXXX,                _______, _______
  ),
  [_WIN] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_BTN4, G(KC_D), KC_BTN5, KC_F12,        XXXXXXX, XXXXXXX, XXXXXXX, G(KC_L), XXXXXXX,
    XXXXXXX,  KC_LGUI, SWIN(KC_S), G(KC_V), XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              _______, XXXXXXX,                 G(KC_ENT), _______
  ),
};

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
