#include QMK_KEYBOARD_H

#include "swapper.h"

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TABL G(S(KC_LBRC))
#define TABR G(S(KC_RBRC))
#define SPCL A(G(KC_LEFT))
#define SPC_R A(G(KC_RGHT))
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RGUI OSM(MOD_RGUI)

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    SW_WIN = SAFE_RANGE,
    SW_LANG, // Switch to next input language (gui-spc)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_QUOT ,KC_COMM ,KC_DOT  ,KC_P    ,KC_Y    ,                          KC_F    ,KC_G    ,KC_C    ,KC_R    ,KC_L    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                              KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                              KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
  //└────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┤
                                KC_BSPC ,LA_NAV  , OS_LSFT,        OS_RSFT ,LA_SYM  ,KC_SPC
  //                           └────────┴────────┴────────        └────────┴────────┴────────
    ),

    [SYM] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_LBRC ,KC_LCBR ,KC_LPRN ,KC_TILD ,                          KC_CIRC ,KC_RPRN ,KC_RCBR ,KC_RBRC , KC_GRV ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_MINS ,KC_ASTR ,KC_EQL  ,KC_UNDS ,KC_DLR  ,                          KC_HASH ,OS_RSFT ,OS_RCTL ,OS_RALT , OS_RGUI,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC,                           XXXXXXX ,KC_BSLS ,KC_AMPR ,KC_QUES , KC_EXLM,
  //└────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┤
                                KC_ESC  ,_______ , _______,        _______ ,_______ ,_______
  //                           └────────┴────────┴────────        └────────┴────────┴────────
    ),

    [NAV] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_TAB  ,SW_WIN  ,TABL    ,TABR    ,KC_VOLU ,                          QK_BOOT, HOME    ,KC_UP   ,END     ,KC_DEL  ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     OS_LGUI ,OS_LALT ,OS_LCTL ,OS_LSFT ,KC_VOLD ,                          CW_TOGG ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     SPCL,    SPC_R,   BACK,    FWD,     KC_MPLY,                           XXXXXXX, KC_PGDN ,KC_PGUP ,SW_LANG, KC_ENT  ,
  //└────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┤
                                _______, _______, _______,         _______ ,_______ ,KC_ENT
  //                           └────────┴────────┴────────        └────────┴────────┴────────
    ),

    [NUM] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,XXXXXXX ,                          XXXXXXX ,OS_RSFT ,OS_RCTL ,OS_RALT ,OS_RGUI,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10,
  //└────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┤
                                _______ , _______, _______,        _______ , _______, _______
  //                           └────────┴────────┴────────        └────────┴────────┴────────
    ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
