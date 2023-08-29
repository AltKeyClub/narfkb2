#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"


enum layers { BASE, SYM, NUM, FUN, NAV, OTHER };

const uint16_t PROGMEM o_p_combo[] = {DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM q_w_combo[] = {DE_Q, DE_W, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(o_p_combo, DE_PLUS),
    COMBO(q_w_combo, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
            DE_Q,         DE_W,          DE_E,           DE_R,            DE_T,             DE_Z,           DE_U,         DE_I,         DE_O,           DE_P,
            LGUI_T(DE_A), LALT_T(DE_S),  LCTL_T(DE_D),   LSFT_T(DE_F),    DE_G,             DE_H,           LSFT_T(DE_J), LCTL_T(DE_K), LALT_T(DE_L),   LGUI_T(DE_HASH),
            DE_Y,         DE_X,          DE_C,           DE_V,            DE_B,             DE_N,           DE_M,         DE_COMM,      DE_DOT,         LT(OTHER, DE_MINS),
                                                         LT(NUM,KC_TAB),  LT(FUN,KC_BSPC),  LT(NAV,KC_SPC), LT(SYM, KC_ENTER)
    ),
    [SYM] = LAYOUT(
            DE_AT,        DE_LPRN,       DE_RPRN,        DE_UDIA,         DE_SS,            XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
            DE_BSLS,      DE_LCBR,       DE_RCBR,        DE_ADIA,         DE_UDIA,          XXXXXXX,        KC_LSFT,      KC_LCTL,      KC_LALT,        KC_LGUI,
            DE_LABK,      DE_LBRC,       DE_RBRC,        DE_GRV,          DE_GRV,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
                                                         _______,         KC_DEL,           _______,        _______
    ),
    [NUM] = LAYOUT(
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          KC_7,           KC_8,         KC_9,         DE_TILD,        DE_EURO,
            KC_LGUI,      KC_LALT,       KC_LCTL,        KC_LSFT,         XXXXXXX,          KC_4,           KC_5,         KC_6,         DE_PIPE,        XXXXXXX,
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          KC_1,           KC_2,         KC_3,         DE_QUES,        XXXXXXX,
                                                         _______,         _______,          _______,        KC_0
    ),
    [FUN] = LAYOUT(
            XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          KC_F7,          KC_F8,        KC_F9,        KC_F12,         XXXXXXX,
            KC_LGUI,      KC_LALT,       KC_LCTL,        KC_LSFT,         XXXXXXX,          KC_F4,          KC_F5,        KC_F6,        KC_F11,         XXXXXXX,
            XXXXXXX,      C(DE_X),       C(DE_C),        C(DE_V),         XXXXXXX,          KC_F1,          KC_F2,        KC_F3,        KC_F10,         XXXXXXX,
                                                         _______,         _______,          _______,        _______
    ),
    [NAV] = LAYOUT(
            XXXXXXX,      KC_PGUP,       KC_HOME,        KC_UP,           KC_END,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
            XXXXXXX,      KC_PGDN,       KC_LEFT,        KC_DOWN,         KC_RIGHT,         XXXXXXX,        KC_LSFT,      KC_LCTL,      KC_LALT,        KC_LGUI,
            KC_CAPS,      XXXXXXX,       XXXXXXX,        KC_INS,          XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
                                                         XXXXXXX,         XXXXXXX,          XXXXXXX,        XXXXXXX
    ),
    [OTHER] = LAYOUT(
            KC_VOLU,      XXXXXXX,       KC_MPRV,        KC_MPLY,         KC_MNXT,          XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
            KC_VOLD,      XXXXXXX,       XXXXXXX,        XXXXXXX,         XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
            KC_MUTE,      XXXXXXX,       C(S(KC_F11)),   LSA(KC_INS),     XXXXXXX,          XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,
                                                         TG(NUM),         XXXXXXX,          TG(NAV),        XXXXXXX
    )
};
