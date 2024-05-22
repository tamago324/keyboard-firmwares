#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define WS2812_PIO_USE_PIO1
#define WS2812_DI_PIN GP29

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define ENCODER_DEFAULT_POS 0x3

#define MOUSEKEY_INERTIA

#define RGBLIGHT_LED_MAP {17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0}