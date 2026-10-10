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
#include "users/holykeebs/bongocat.h"
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

// Layer Declarations
enum {
    BASE   = 0,
    NUM    = 1,
    SYM    = 2,
    ADJUST = 3,
    MOUSE  = 4,
    MUGGLE = 5,
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+------------|
       KC_ESC,    HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,                         KC_H,    HRM_J,   HRM_K,   HRM_L,  HRM_Ö, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_NUHS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+------------|
                                           TT(MOUSE) , TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),

  // "lower" Layer - NUM
  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   HRM_A,   HRM_S,   HRM_D,   HRM_F,     KC_G,                         KC_H,    KC_4,    KC_5,    KC_6,   HRM_Ö, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX,    KC_1,   KC_2,     KC_3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______,   KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  // "upper" Layer - SYM
  [SYM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------.             ,------------------------------------------------------------.
      _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),     LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS),   // Shift + 1-ß
  //|--------+--------+--------+--------+--------+---------------|             |---------            +--------+--------+--------+--------+---------------|
      _______, ALGR(KC_1), ALGR(KC_2), ALGR(KC_3), ALGR(KC_4), ALGR(KC_5),     ALGR(KC_6), ALGR(KC_7), ALGR(KC_8), ALGR(KC_9), ALGR(KC_0), ALGR(KC_MINS),   // AltGR + 1-ß
  //|--------+--------+--------+--------+--------+--------|                    |---------+--------    +--------+--------+--------+---------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX,    XXXXXXX,    XXXXXXX,     KC_EQL,    KC_RBRC,       KC_NUHS,   // ` ~ #
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+---------+--------+--------+--------+--------+---------------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [ADJUST] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------.                   ,-----------------------------------------------------------------------------.
          QK_BOOT,     HK_DUMP,     HK_SAVE,     HK_RESET,     XXXXXXX, HK_C_SCROLL,                         XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     QK_BOOT,
  //|------------+------------+------------+-------------+------------+------------|                   |------------+------------+------------+------------+------------+------------|
      QK_C_EEPROM,  HK_P_SET_D,  HK_P_SET_S, HK_P_SET_THR,     XXXXXXX, HK_S_MODE_T,                         KC_LEFT,    KC_DOWN,        KC_UP,    KC_RIGHT,     XXXXXXX, QK_C_EEPROM,
  //|------------+------------+------------+-------------+------------+------------|                   |------------+------------+------------+------------+------------+------------|
          KC_LSFT,      KC_F13,      KC_F14,      XXXXXXX,     XXXXXXX, HK_D_MODE_T,                         XXXXXXX,     XXXXXXX,     XXXXXXX,       XXXXXXX,   XXXXXXX,  HK_BONGO_T,
  //|------------+------------+------------+-------------+------------+------------+--------| |--------+------------+------------+------------+------------+------------+------------|
                                                               KC_LGUI,     _______,  KC_SPC,    KC_ENT,     _______,     KC_RALT
                                                       //`----------------------------------' `----------------------------------'
  ),

  // MOUSE
  [MOUSE] = LAYOUT_split_3x6_3(
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

  // Muggle Mode
  [MUGGLE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+------------|
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_NUHS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+------------|
                                           TT(MOUSE) , TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),
};

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
const uint16_t bckspc_combo[] PROGMEM = {KC_I, KC_O, COMBO_END};
const uint16_t tab_combo[]    PROGMEM = {KC_Q, KC_W, COMBO_END};
const uint16_t muggle_combo[] PROGMEM = {KC_Q, KC_W, KC_E, KC_R, COMBO_END};

combo_t key_combos[] = {
    COMBO(bckspc_combo, KC_BSPC),          // I and O and P => backspace.
    COMBO(tab_combo,    KC_TAB),           // Q and W => tab
    COMBO(muggle_combo, TG(MUGGLE)),
};

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

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case NUM:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case SYM:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case MUGGLE:
            oled_write_P(PSTR("Muggle\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }

    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);

    return true;
}
#endif
