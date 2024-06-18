#include QMK_KEYBOARD_H
#include <stdio.h>


#define DW_LBRC KC_MINUS
#define DW_RBRC KC_EQUAL
#define DW_MINS KC_QUOT
#define DW_EQL KC_RIGHT_BRACKET
#define DW_SLSH KC_LEFT_BRACKET


enum Layers { BASE, NUM, CTL, NAV, FUN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5__3(
    KC_Q         , KC_W         , KC_E         , KC_R         , KC_T , KC_Y , KC_U         , KC_I         , KC_O         , KC_P             ,
    LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , KC_G , KC_H , LSFT_T(KC_J) , LCTL_T(KC_K) , LALT_T(KC_L) , LGUI_T (KC_SCLN) ,
    KC_Z         , KC_X         , KC_C         , KC_V         , KC_B , KC_N , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH          ,

                                      LT(CTL, KC_SPC), TT(NAV), XXXXXXX,XXXXXXX,           LM(NUM,MOD_LSFT ),OSL(NUM)
  ),
  [NUM] = LAYOUT_split_3x5__3(
    _______ , _______ , _______ , _______ , XXXXXXX , XXXXXXX , KC_BSLS , KC_GRV  , DW_LBRC , DW_RBRC ,
    KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , DW_MINS , DW_SLSH , DW_EQL  , XXXXXXX ,

                                                TO(BASE),XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
  ),
  [CTL] = LAYOUT_split_3x5__3(
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_ESC  , KC_BSPC , KC_DEL  ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_ENT  , KC_TAB  , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP , KC_END  ,

                         TO(BASE), XXXXXXX       , XXXXXXX       , XXXXXXX        , XXXXXXX  , MO(FUN)
  ),
  [NAV] = LAYOUT_split_3x5__3(
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , C(KC_I)   , KC_BTN1 , KC_BTN2 , KC_BTN3 , XXXXXXX  ,
    XXXXXXX , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , XXXXXXX   , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT ,
    XXXXXXX , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , C(KC_DOT) , KC_HOME , KC_PGDN , KC_PGUP , KC_END   ,

                         TO(BASE), XXXXXXX       , XXXXXXX       , XXXXXXX        , XXXXXXX  , MO(FUN)
  ),
  [FUN] = LAYOUT_split_3x5__3(
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6  , KC_F7   , KC_F8   , KC_F9   , KC_F10  ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F11 , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F12 , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,

                                  TO(BASE), XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX
  ),
};
