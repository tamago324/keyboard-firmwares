#pragma once

// SFT_T(KC_SPACE) としていたときに、 Space → Space長押し としたときに、 Spaceが連続で入力されてしまう問題の対処法
// https://docs.qmk.fm/#/ja/tap_hold?id=%e3%82%bf%e3%83%83%e3%83%94%e3%83%b3%e3%82%b0%e5%bc%b7%e5%88%b6%e3%83%9b%e3%83%bc%e3%83%ab%e3%83%89
// https://qiita.com/uodna/items/6d23581d26c1adb23377
#define TAPPING_FORCE_HOLD

// キーごとに タップとホールドの時間を設定する
//#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 145

// キーごとに TAPPING_TERM を設定できるようにする
#define TAPPING_TERM_PER_KEY

#define COMBO_TERM 100

// サイズを小さくするためのもの https://zenn.dev/koron/articles/98324ab760e83a
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

/* #undef NO_ACTION_ONESHOT // ワンショットキーの無効化 */

#define LAYER_STATE_8BIT    // レイヤーの上限を8にする

// Shift が抜ける問題への対処法の1つらしい
#define USB_POLLING_INTERVAL_MS 10
