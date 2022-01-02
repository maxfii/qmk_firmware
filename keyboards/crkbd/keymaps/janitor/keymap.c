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

enum Layers { BASE, NUM, NAV, MOUSE, GAME, GAMEFUN };

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
                                                  KC_ESC, KC_SPC,  KC_TAB,                               KC_ENT,   LT (NUM, KC_BSPC), KC_DELETE
                                              //`--------------------------'  `                         --------------------------'

  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, DW_PLUS, DW_EQUAL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, TD(TD_PARENS), TD(TD_BRACES), TD(TD_BRACKETS), TD(TD_SLASHES), TD(TD_GRAVE),                      KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

