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
#include <stdio.h>
#include "features/repeat_key.h"

enum {
    TD_PARENS,
    TD_BRACES,
    TD_BRACKETS,
    TD_SLASHES,
    TD_GRAVE
};

#define DW_RBRACE KC_PLUS
#define DW_LBRACE KC_UNDERSCORE
#define DW_RBRACKET KC_EQUAL
#define DW_LBRACKET KC_MINUS

#define DW_EQUAL KC_RIGHT_BRACKET
#define DW_PLUS  KC_RIGHT_CURLY_BRACE
#define DW_QUES  KC_LEFT_CURLY_BRACE
#define DW_FSLASH KC_LEFT_BRACKET

combo_t key_combos[] = {};
uint16_t COMBO_LEN = 0;

enum custom_keycodes {
  REPEAT = SAFE_RANGE,
  // Other custom keys...
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_repeat_key(keycode, record, REPEAT)) { return false; }
  // Your macros ...

  return true;
}

tap_dance_action_t tap_dance_actons[] = {
    [TD_PARENS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [TD_BRACES] = ACTION_TAP_DANCE_DOUBLE(DW_LBRACE, DW_RBRACE),
    [TD_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(DW_LBRACKET, DW_RBRACKET),
    [TD_SLASHES] = ACTION_TAP_DANCE_DOUBLE(DW_FSLASH, KC_BACKSLASH),
    [TD_GRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    KC_BTN2 , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T ,            KC_Y , KC_U         , KC_I         , KC_O         , KC_P             , KC_BTN2 ,
    KC_BTN3 , KC_A         , KC_S         , KC_D         , KC_F         , KC_G ,            KC_H , KC_J         , KC_K         , KC_L         , KC_SCLN          , KC_BTN3 ,
    KC_BTN1 , KC_Z         , KC_X         , KC_C         , KC_V         , KC_B ,            KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH          , KC_BTN1 ,

    KC_ESC, KC_SPC, OSM(MOD_LSFT),   OSM(MOD_LCTL), TO(1), XXXXXXX
  ),

  [1] = LAYOUT_split_3x6_3(
    XXXXXXX , KC_1            , KC_2          , KC_3            , KC_4           , KC_5         ,                   KC_6    , KC_7            , KC_8    , KC_9    , KC_0     , XXXXXXX ,
    XXXXXXX , KC_EXLM         , KC_AT         , KC_HASH         , KC_DLR         , KC_PERC      ,                   KC_CIRC , KC_AMPR         , KC_ASTR , DW_PLUS , DW_EQUAL , XXXXXXX ,
    XXXXXXX , TD(TD_PARENS)   , TD(TD_BRACES) , TD(TD_BRACKETS) , TD(TD_SLASHES) , TD(TD_GRAVE) ,                   KC_PIPE , DW_QUES         , KC_QUOT , XXXXXXX , XXXXXXX  , XXXXXXX ,

    XXXXXXX , TO(0), XXXXXXX,             KC_ENTER, TO(2), XXXXXXX
  ),

  [2] = LAYOUT_split_3x6_3(
    XXXXXXX , XXXXXXX       , XXXXXXX       , OSM(KC_MEH)   , XXXXXXX       , OSM(KC_HYPR),           XXXXXXX   , XXXXXXX , XXXXXXX , KC_BSPC , KC_DEL   , XXXXXXX ,
    XXXXXXX , OSM(MOD_LGUI) , OSM(MOD_LALT) , OSM(MOD_LCTL) , OSM(MOD_LSFT) , A(KC_TAB),              KC_TAB    , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX ,
    XXXXXXX , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , S(A(KC_TAB)),           S(KC_TAB) , KC_HOME , KC_PGDN , KC_PGUP , KC_END   , XXXXXXX ,

    XXXXXXX, TO(0), OSL(3),              KC_ENTER , TO(2), XXXXXXX
  ),

  [3] = LAYOUT_split_3x6_3(
    XXXXXXX , KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,            KC_F6  , KC_F7   , KC_F8   , KC_F9   , KC_F10  , XXXXXXX ,
    XXXXXXX , RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI , XXXXXXX ,            KC_F11 , KC_MUTE , KC_VOLD , KC_VOLU , XXXXXXX , XXXXXXX ,
    XXXXXXX , RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD , XXXXXXX ,            KC_F12 , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,

    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX
  )
};
