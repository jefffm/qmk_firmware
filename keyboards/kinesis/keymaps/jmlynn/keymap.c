#include QMK_KEYBOARD_H

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
};

// layers
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

// oneshot mods
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RGUI OSM(MOD_RGUI)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DEF] = LAYOUT_pretty(
// ,---------------------------------------------------------------------------------------------------------------------------------------------------------------------.
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO  , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO  , QK_BOOT ,
// |--------+---------+---------+---------+-------+--------+-------------------------------------------------+--------+---------+---------+---------+--------+---------|
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO  ,                                                  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO  , KC_NO   ,
// |--------+---------+---------+---------+-------+--------|                                                 |--------+---------+---------+---------+--------+---------|
    KC_NO   , KC_QUOT , KC_COMM , KC_DOT  , KC_P  , KC_Y   ,                                                   KC_F   , KC_G    , KC_C    , KC_R    , KC_L   , KC_NO   ,
// |--------+---------+---------+---------+-------+--------|                                                 |--------+---------+---------+---------+--------+---------|
    KC_NO   , KC_A    , KC_O    , KC_E    , KC_U  , KC_I   ,                                                   KC_D   , KC_H    , KC_T    , KC_N    , KC_S   , KC_NO   ,
// |--------+---------+---------+---------+-------+--------|                                                 |--------+---------+---------+---------+--------+---------|
    KC_NO   , KC_SCLN , KC_Q    , KC_J    , KC_K  , KC_X   ,                                                   KC_B   , KC_M    , KC_W    , KC_V    , KC_Z   , KC_NO   ,
// `--------+---------+---------+---------+-------+--------'                                                 `--------+---------+---------+---------+--------+---------'
              KC_NO   , KC_NO   , KC_NO   , KC_NO ,                                                                     KC_NO   , KC_NO   , KC_NO   , KC_NO  ,
//          `-------------------------------------'                                                                   `--------------------------------------'
//                                          ,-------------------.                                        ,--------------------.
                                              KC_LSFT , KC_NO   ,                                          KC_NO   , KC_RSFT  ,
//                                ,---------|---------|---------|                                        |---------+----------+---------.
                                                        KC_NO   ,                                          KC_NO   ,
//                                |         |         |---------|                                        |---------|          |         |
                                    KC_BSPC , LA_NAV  , KC_NO   ,                                          KC_NO   , LA_SYM   , KC_SPC  ,
//                                |         |         |         |                                        |         |          |         |
//                                `-----------------------------'                                        `------------------------------'
  ),

};
// clang-format on
