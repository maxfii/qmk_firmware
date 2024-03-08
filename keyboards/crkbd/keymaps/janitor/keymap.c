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

combo_t key_combos[] = {};
uint16_t COMBO_LEN = 0;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    KC_BTN2 , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T ,            KC_Y , KC_U         , KC_I         , KC_O         , KC_P             , KC_BTN2 ,
    KC_BTN3 , KC_A         , KC_S         , KC_D         , KC_F         , KC_G ,            KC_H , KC_J         , KC_K         , KC_L         , KC_SCLN          , KC_BTN3 ,
    KC_BTN1 , KC_Z         , KC_X         , KC_C         , KC_V         , KC_B ,            KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH          , KC_BTN1 ,

    KC_ESC, LT(2, KC_SPC), OSM(MOD_LSFT),        OSM(MOD_LCTL), LT(1, QK_REP), LT(3, QK_AREP)
  ),

  [1] = LAYOUT_split_3x6_3(
    XXXXXXX , XXXXXXX         , XXXXXXX       , XXXXXXX         , XXXXXXX        , XXXXXXX      ,                   XXXXXXX , KC_BSLS , XXXXXXX , KC_MINS , KC_EQL   , XXXXXXX ,
    XXXXXXX , KC_1            , KC_2          , KC_3            , KC_4           , KC_5         ,                   KC_6    , KC_7    , KC_8    , KC_9    , KC_0     , XXXXXXX ,
    XXXXXXX , XXXXXXX         , XXXXXXX       , XXXXXXX         , XXXXXXX        , XXXXXXX      ,                   XXXXXXX , KC_QUOT , KC_LBRC , KC_RBRC , XXXXXXX  , XXXXXXX ,

    XXXXXXX , XXXXXXX, OSM(MOD_LSFT),             KC_ENTER, XXXXXXX, XXXXXXX
  ),

  [2] = LAYOUT_split_3x6_3(
    XXXXXXX , XXXXXXX       , XXXXXXX       , OSM(KC_MEH)   , XXXXXXX       , OSM(KC_HYPR),           A(KC_SPACE)   , XXXXXXX , XXXXXXX , KC_BSPC , KC_DEL   , XXXXXXX ,
    XXXXXXX , OSM(MOD_LGUI) , OSM(MOD_LALT) , OSM(MOD_LCTL) , OSM(MOD_LSFT) , XXXXXXX,                KC_TAB        , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX ,
    XXXXXXX , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX,                S(KC_TAB)     , KC_HOME , KC_PGDN , KC_PGUP , KC_END   , XXXXXXX ,

    XXXXXXX, XXXXXXX, OSL(3),              KC_ENTER, KC_BSPC, TO(0)
  ),

  [3] = LAYOUT_split_3x6_3(
    XXXXXXX , KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,            KC_F6  , KC_F7   , KC_F8   , KC_F9   , KC_F10  , XXXXXXX ,
    XXXXXXX , RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI , XXXXXXX ,            KC_F11 , KC_MUTE , KC_VOLD , KC_VOLU , XXXXXXX , XXXXXXX ,
    XXXXXXX , RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD , XXXXXXX ,            KC_F12 , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,

    XXXXXXX , XXXXXXX, OSM(MOD_LSFT), OSM(MOD_LCTL), XXXXXXX , XXXXXXX
  )
};
