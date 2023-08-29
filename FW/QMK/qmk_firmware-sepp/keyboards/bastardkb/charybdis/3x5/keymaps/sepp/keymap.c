#include QMK_KEYBOARD_H

#include "keymap_german.h"

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYMBOLS,
    LAYER_NUMERAL,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_POINTER,
};

#define DEL_NUM LT(LAYER_NUMERAL, KC_DEL)
#define BSP_FUN LT(LAYER_FUNCTION, KC_BSPC)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define TAB_SYM LT(LAYER_SYMBOLS, KC_TAB)

#define A_LT LGUI_T(DE_A)
#define S_LT LALT_T(DE_S)
#define D_LT LCTL_T(DE_D)
#define F_LT LSFT_T(DE_F)
#define J_LT LSFT_T(DE_J)
#define K_LT LCTL_T(DE_K)
#define L_LT LALT_T(DE_L)
#define V_LT LT(LAYER_POINTER, DE_V)
#define HASH_LT LGUI_T(DE_HASH)

#define OS_GUI OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_SFT OSM(MOD_LSFT)

#define INS_MODE LSA(KC_INS)
#define IJ_RUN C(S(KC_F11))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                   DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,
    A_LT,    S_LT,    D_LT,    F_LT,    DE_G,                   DE_H,    J_LT,    K_LT,    L_LT,    HASH_LT,
    DE_Y,    DE_X,    DE_C,    V_LT,    DE_B,                   DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,
                      DEL_NUM, BSP_FUN, KC_ENT,                 SPC_NAV, TAB_SYM
  ),
  [LAYER_SYMBOLS] = LAYOUT(
    DE_AT,   DE_LPRN, DE_RPRN, DE_UDIA, DE_SS,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    DE_BSLS, DE_LCBR, DE_RCBR, DE_ADIA, DE_ODIA,                XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    DE_EURO, DE_LBRC, DE_RBRC, DE_CIRC, DE_GRV,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_ESC,  _______, _______,                _______, _______
  ),
  [LAYER_NUMERAL] = LAYOUT(
    KC_ESC,  XXXXXXX,    C(KC_PGUP), C(KC_PGDN), XXXXXXX,       DE_7,    DE_8,    DE_9,    DE_TILD, XXXXXXX,
    KC_LGUI, KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,       DE_4,    DE_5,    DE_6,    DE_PIPE, DE_LABK,
    XXXXXXX, C(S(DE_X)), C(S(DE_C)), C(S(DE_V)), XXXXXXX,       DE_1,    DE_2,    DE_3,    DE_QUES, DE_PLUS,
                         _______,    _______,    _______,       _______, DE_0
  ),
  [LAYER_FUNCTION] = LAYOUT(
    OS_GUI,  OS_ALT,  OS_CTL,  OS_SFT,  XXXXXXX,                KC_F7,    KC_F8,   KC_F9,   KC_F12,  TO(LAYER_BASE),
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                KC_F4,    KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
    XXXXXXX, C(DE_X), C(DE_C), C(DE_V), XXXXXXX,                KC_F1,    KC_F2,   KC_F3,   KC_F10,  TG(LAYER_NUMERAL),
                      _______, _______, _______,                _______,  _______
  ),
  [LAYER_NAVIGATION] = LAYOUT(
    CW_TOGG, KC_PGUP, KC_HOME, KC_UP,   KC_END,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,               XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_INS,  INS_MODE,XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______,                _______, _______
  ),
  [LAYER_POINTER] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                DPI_MOD, DPI_RMOD,S_D_MOD, S_D_RMOD,XXXXXXX,
    XXXXXXX, XXXXXXX, SNP_TOG, XXXXXXX, XXXXXXX,                XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    XXXXXXX, XXXXXXX, DRG_TOG, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_BTN2, KC_BTN3, KC_BTN1,                _______, _______
  ),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
        case DE_MINS:
        case DE_UDIA:
        case DE_ADIA:
        case DE_ODIA:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;
    }
}
