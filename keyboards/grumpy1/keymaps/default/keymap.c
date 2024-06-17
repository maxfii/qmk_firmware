// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_28(
                 KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    LT(1, KC_SPC),    LM(2, MOD_LSFT),    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
    ),
    [1] = LAYOUT_ortho_28(
                 KC_GRV,    KC_Q,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,    KC_P,    XXXXXXX,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_Z,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BSLS,    KC_MINS,    KC_EQL,    KC_COMM, KC_DOT,  KC_SLSH
    ),

};
