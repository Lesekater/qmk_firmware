/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// inspired by https://github.com/getreuer/qmk-keymap/blob/main/config_getreuer.h

#pragma once

// Select hand configuration
#if !defined(MASTER_RIGHT) && !defined(MASTER_LEFT)
    #define MASTER_RIGHT
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

// Tap-hold configuration for home row mods.
//#define TAPPING_TERM 240
//#define TAPPING_TERM_PER_KEY
//#define FLOW_TAP_TERM 100
//#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define SPECULATIVE_HOLD
#define SPECULATIVE_HOLD_ONE_KEY
#define SPECULATIVE_HOLD_FLOW_TERM 200
//#define QUICK_TAP_TERM_PER_KEY

#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RCTL
#define MODS_TO_NEUTRALIZE \
  { MOD_BIT(KC_LALT), MOD_BIT(KC_LGUI), MOD_BIT(KC_RGUI) }

// When idle, turn off Caps Word after 5 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 5000

// When idle, turn off Layer Lock after 60 seconds.
#define LAYER_LOCK_IDLE_TIMEOUT 60000

// When idle, turn off Sentence Case after 2 seconds.
#define SENTENCE_CASE_TIMEOUT 2000

// Use double tap for tap-toggle layer keys
#define TAPPING_TOGGLE 2

// Caps word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// RGB Light
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//  #define RGBLIGHT_EFFECT_RGB_TEST
//  #define RGBLIGHT_EFFECT_ALTERNATING
//  #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

// Vial identity and unlock combo. VIAL_INSECURE lives in the shared userspace
// config (users/holykeebs/config.h), so it is intentionally not repeated here.
// The unlock combo is unused while VIAL_INSECURE is set, but kept so re-securing
// later doesn't require re-picking keys: the two outermost top keys, matrix
// [0,0] (top-left of the left half) and [4,0] (top-right of the right half).
#define VIAL_KEYBOARD_UID {0xAF, 0x62, 0x22, 0xE9, 0x5D, 0x88, 0xE0, 0x87}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }
