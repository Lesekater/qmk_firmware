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

#include QMK_KEYBOARD_H
#include "users/holykeebs/holykeebs.h"
#include "keymap_german.h"

#define QK_C_EEPROM QK_CLEAR_EEPROM

enum keycode_aliases {
  // LEFT Short aliases for home row mods
  HRM_A = LCTL_T(KC_A),
  HRM_S = LALT_T(KC_S),
  HRM_D = LGUI_T(KC_D),
  HRM_F = LSFT_T(KC_F),
  // LEFT Additional mod tap-hold keys.
  //HRM_G = LCTL_T(KC_G),
  //HRM_X = LGUI_T(KC_X),

  // RIGHT Short aliases for home row mods
  HRM_J = RSFT_T(KC_J),
  HRM_K = RGUI_T(KC_K),
  HRM_L = ALGR_T(KC_L),
  HRM_Ö = RCTL_T(KC_SCLN), //Ö
  // RIGHT Additional mod tap-hold keys.
  //HRM_H = RCTL_T(KC_H),
  //HRM_DOT = LT(WIN, KC_DOT),
  //HRM_QUO = RGUI_T(KC_QUOT),

  //EXT_COL = LT(EXT, KC_SCLN),
  //NAV_SLS = LSFT_T(KC_SLSH),
  //NAV_EQL = LT(0, KC_EQL),
};

// TEMPORARY A ON MOD (A key broken)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+------------|
       KC_ESC,    HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,                         KC_H,    HRM_J,   HRM_K,   HRM_L,  HRM_Ö, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_NUHS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+------------|
                                           TT(4) , TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),

  // "lower" Layer - NUM
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   HRM_A,   HRM_S,   HRM_D,   HRM_F,     KC_G,                         KC_H,    KC_4,    KC_5,    KC_6,  HRM_Ö, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                    XXXXXXX,    KC_1,   KC_2,     KC_3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______,   KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  // "upper" Layer - SYM
  [2] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------.             ,------------------------------------------------------------.
      _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),     LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______, // Shift + 1-0
  //|--------+--------+--------+--------+--------+---------------|             |--------+--------+--------+--------+--------+---------------|
      _______, ALGR(KC_1), ALGR(KC_2), ALGR(KC_3), ALGR(KC_4), ALGR(KC_5),     ALGR(KC_6), ALGR(KC_7), ALGR(KC_8), ALGR(KC_9), ALGR(KC_0), _______, // Shift + 1-0
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+---------------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------.                   ,-----------------------------------------------------------------------------.
          QK_BOOT,     HK_DUMP,     HK_SAVE,     HK_RESET,     XXXXXXX, HK_C_SCROLL,                         XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     QK_BOOT,
  //|------------+------------+------------+-------------+------------+------------|                   |------------+------------+------------+------------+------------+------------|
      QK_C_EEPROM,  HK_P_SET_D,  HK_P_SET_S, HK_P_SET_THR,     XXXXXXX, HK_S_MODE_T,                         KC_LEFT,    KC_DOWN,        KC_UP,    KC_RIGHT,     XXXXXXX, QK_C_EEPROM,
  //|------------+------------+------------+-------------+------------+------------|                   |------------+------------+------------+------------+------------+------------|
          KC_LSFT,      KC_F13,      KC_F14,      XXXXXXX,     XXXXXXX, HK_D_MODE_T,                         XXXXXXX,     XXXXXXX,     XXXXXXX,       XXXXXXX,     XXXXXXX,     XXXXXXX,
  //|------------+------------+------------+-------------+------------+------------+--------| |--------+------------+------------+------------+------------+------------+------------|
                                                               KC_LGUI,     _______,  KC_SPC,    KC_ENT,     _______,     KC_RALT
                                                       //`----------------------------------' `----------------------------------'
  ),

  // MOUSE
  [4] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------.             ,------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+---------------|             |--------+--------+--------+--------+--------+---------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      QK_MOUSE_CURSOR_LEFT, QK_MOUSE_CURSOR_DOWN, QK_MOUSE_CURSOR_UP, QK_MOUSE_CURSOR_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+---------------|
                               _______, _______,  QK_MOUSE_BUTTON_2,     QK_MOUSE_BUTTON_1, MS_WHLU, MS_WHLD
                                      //`--------------------------'  `--------------------------'
  ),
};

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk./features/combo)
///////////////////////////////////////////////////////////////////////////////
const uint16_t bckspc_combo[] PROGMEM = {KC_I, KC_O, KC_P, COMBO_END};
//const uint16_t j_k_combo[] PROGMEM = {KC_J, KC_K, COMBO_END};
//const uint16_t comm_dot_combo[] PROGMEM = {KC_COMM, HRM_DOT, COMBO_END};
//const uint16_t f_n_combo[] PROGMEM = {KC_F, HRM_N, COMBO_END};

combo_t key_combos[] = {
    COMBO(bckspc_combo, KC_BSPC),          // I and O and P => backspace.
//    COMBO(j_k_combo, KC_BSLS),           // J and K => backslash
//    COMBO(comm_dot_combo, KC_SCLN),      // , and . => ;
//    COMBO(f_n_combo, OSL(FUN)),          // F and N => FUN layer
};

///////////////////////////////////////////////////////////////////////////////
// Flow Tap (https://docs.qmk.fm/tap_hold#flow-tap)
///////////////////////////////////////////////////////////////////////////////
/*#ifdef FLOW_TAP_TERM
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
  // Only apply Flow Tap when following a letter key, and not hotkeys.
  if (get_tap_keycode(prev_keycode) <= KC_Z &&
      (get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) == 0) {
    switch (keycode) {
      case HRM_A:
      case HRM_S:
      case HRM_D:
      case HRM_F:
      case HRM_J:
      case HRM_K:
      case HRM_L:
      case HRM_Ö:
        return FLOW_TAP_TERM;

      //case HRM_G:
      //case HRM_H:
      //  return FLOW_TAP_TERM - 25;
    }
  }

  return 0;  // Disable Flow Tap otherwise.
}
#endif  // FLOW_TAP_TERM */

///////////////////////////////////////////////////////////////////////////////
// Flow Tap (https://docs.qmk.fm/tap_hold#chordal-hold)
///////////////////////////////////////////////////////////////////////////////
/*#ifdef CHORDAL_HOLD
bool get_chordal_hold(
        uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
        uint16_t other_keycode, keyrecord_t* other_record) {
  switch (tap_hold_keycode) {
    case NAV_SLS:
      return true;

    case HRM_D:
      if (other_keycode == KC_M ||
          other_keycode == KC_L ||
          other_keycode == KC_Y ||
          other_keycode == KC_K ||
          other_keycode == KC_J) { return true; }
      break;

    case HRM_N:  // Allow one-handed N + Repeat chord to type "0" on num layer.
      if (other_keycode == QK_REP) { return true; }
      break;

    case HRM_DOT:
      if (other_keycode == HRM_H ||
          other_keycode == KC_COMM) { return true; }
  }
  return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD */

///////////////////////////////////////////////////////////////////////////////
// Speculative Hold
///////////////////////////////////////////////////////////////////////////////
#ifdef SPECULATIVE_HOLD
bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
  return true;  // Enable for all mods.
}
#endif  // SPECULATIVE_HOLD

/////////////////////////////////////////////////////////////////////////////////
// Caps word (https://docs.qmk.fm/features/caps_word)
///////////////////////////////////////////////////////////////////////////////
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT_LSHIFT);  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_COLN:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE
