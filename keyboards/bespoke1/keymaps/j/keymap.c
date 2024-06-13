#include QMK_KEYBOARD_H
#include <stdio.h>


#define DW_RBRACE KC_PLUS
#define DW_LBRACE KC_UNDERSCORE
#define DW_RBRACKET KC_EQUAL
#define DW_LBRACKET KC_MINUS

#define DW_EQUAL KC_RIGHT_BRACKET
#define DW_PLUS  KC_RIGHT_CURLY_BRACE
#define DW_QUES  KC_LEFT_CURLY_BRACE
#define DW_FSLASH KC_LEFT_BRACKET

enum Layers { BASE, NUM, NAV, FUN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5__3(
    KC_Q         , MEH_T(KC_W)  , HYPR_T(KC_E) , KC_R         , KC_T ,            KC_Y , KC_U         , HYPR_T(KC_I) , MEH_T(KC_O)  , KC_P             ,
    LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , KC_G ,            KC_H , LSFT_T(KC_J) , LCTL_T(KC_K) , LALT_T(KC_L) , LGUI_T (KC_SCLN) ,
    KC_Z         , KC_X         , KC_C         , KC_V         , KC_B ,            KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH          ,
                                      LM(NUM, MOD_LSFT), LT(NAV, KC_SPC), OSM(MOD_LSFT),        OSM(MOD_LCTL), QK_REP,    OSL(NUM)
  ),


  [NUM] = LAYOUT_split_3x5__3(
    _______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,

                                                XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
  ),
  [NAV] = LAYOUT_split_3x5__3(
    XXXXXXX       , OSM(MOD_MEH)  , OSM(MOD_HYPR) , XXXXXXX       , XXXXXXX , KC_WH_U   , KC_WH_D , KC_ESC  , KC_BSPC , KC_DEL   ,
    OSM(MOD_LGUI) , OSM(MOD_LALT) , OSM(MOD_LCTL) , OSM(MOD_LSFT) , XXXXXXX , KC_TAB    , KC_LEFT , KC_UP   , KC_DOWN , KC_RIGHT ,
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX , S(KC_TAB) , KC_HOME , KC_PGDN , KC_PGUP , KC_END   ,

                         XXXXXXX , XXXXXXX , XXXXXXX , KC_ENT , XXXXXXX , XXXXXXX
  ),

  [FUN] = LAYOUT_split_3x5__3(
    KC_F1   , MEH_T(KC_F2) , HYPR(KC_F3) , KC_F4   , KC_F5   ,            KC_F6  , KC_F7   , HYPR_T(KC_F8) , MEH_T(KC_F9) , KC_F10  ,
    XXXXXXX , XXXXXXX      , XXXXXXX     , XXXXXXX , XXXXXXX ,            KC_F11 , XXXXXXX , XXXXXXX       , XXXXXXX      , XXXXXXX ,
    XXXXXXX , XXXXXXX      , XXXXXXX     , XXXXXXX , XXXXXXX ,            KC_F12 , XXXXXXX , XXXXXXX       , XXXXXXX      , XXXXXXX ,

                                  XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX
  ),
};
