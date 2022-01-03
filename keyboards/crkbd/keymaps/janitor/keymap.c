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

enum Layers { BASE, NUM, NAV, GAME, GAMEFUN };

enum Taps {
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
#define DW_FSLASH KC_LEFT_BRACKET




qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PARENS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [TD_BRACES] = ACTION_TAP_DANCE_DOUBLE(DW_LBRACE, DW_RBRACE),
    [TD_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(DW_LBRACKET, DW_RBRACKET),
    [TD_SLASHES] = ACTION_TAP_DANCE_DOUBLE(DW_FSLASH, KC_BACKSLASH),
    [TD_GRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,------------------     ------------  ---------      ---------       -----.                    ,--------------------         ---------       ----------      ------          --------.
       KC_TAB,    KC_Q,         KC_W,       KC_E,          KC_R,           KC_T,                         KC_Y,    KC_U,             KC_I,           KC_O,         KC_P,            KC_BSPC,
  //|--------+--------+     --------+---  -----+---      -----+---       -----|                    |--------+--------+--         ------+--       ------+---      -----+          --------|
      KC_LCTL, LGUI_T(KC_A), LALT_T(KC_S),  LCTL_T(KC_D), LSFT_T(KC_F),    KC_G,                         KC_H,    LSFT_T(KC_J),     LCTL_T(KC_K),   LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+---   -----+-     -------  +     --------+-       - ------|                    |--------+--------+------  --+------      --+--------     +--------|
      KC_LSFT,    KC_Z,       KC_X,         KC_C,         KC_V,            KC_B,                         KC_N,    KC_M,             KC_COMM,        KC_DOT,       KC_SLSH,         KC_ESC,
  //|--------+--------+---   -----+-     -------+--     ------+---                                -----+--------|  |--------+--  ------+--      ------+----     ----+--------+--------+--------|
                                                  KC_ESC, LT(NAV, KC_SPC),  KC_TAB,                               KC_ENT,   LT (NUM, KC_BSPC), KC_DELETE
                                              //`--------------------------'  `                         --------------------------'

  ),

    // TODO: mod taps on symbol layer
  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, DW_PLUS, DW_EQUAL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, TD(TD_PARENS), TD(TD_BRACES), TD(TD_BRACKETS), TD(TD_SLASHES), TD(TD_GRAVE),                      KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_TRNS, XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

  [NAV] = LAYOUT_split_3x6_3(
      // TODO: Add function keys to nav (or somewhere)
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_AGIN, KC_PASTE, KC_COPY, KC_CUT, KC_UNDO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      DF(GAME),  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_INS , KC_HOME,  KC_PGDN, KC_PGUP, KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_TRNS, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                           ,-----------------------------------------------------.
      XXXXXXX, KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                           |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,                            DF(BASE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                           |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|         |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DEL,  KC_SPC,  MO(GAMEFUN),    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'         `--------------------------'
  ),
  [GAMEFUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
