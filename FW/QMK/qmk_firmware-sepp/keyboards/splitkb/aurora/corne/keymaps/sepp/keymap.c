#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "layers.h"

#define A_LT LGUI_T(DE_A)
#define S_LT LALT_T(DE_S)
#define D_LT LCTL_T(DE_D)
#define F_LT LSFT_T(DE_F)
#define J_LT LSFT_T(DE_J)
#define K_LT LCTL_T(DE_K)
#define L_LT LALT_T(DE_L)
#define HASH_LT LGUI_T(DE_HASH)

#define INS_MODE LSA(KC_INS)
#define IJ_RUN C(S(KC_F11))

#define OS_GUI OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_SFT OSM(MOD_LSFT)

#ifdef POINTING_DEVICE_ENABLE
bool set_scrolling = false;

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOUSE);
    set_auto_mouse_enable(true);
}

#define SCROLL_DIVISOR_H 8.0
#define SCROLL_DIVISOR_V 8.0
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v -= (float)mouse_report.y / SCROLL_DIVISOR_V;

        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    return true;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,          DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,     KC_DEL,
        KC_TAB,  A_LT,    S_LT,    D_LT,    F_LT,    DE_G,          DE_H,    J_LT,    K_LT,    L_LT,    HASH_LT,  DE_PLUS,
        DE_LABK, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,          DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,  KC_ENT,
                                   TT(NUM), MO(FUN), KC_BSPC,       KC_SPC,  TT(NAV), MO(SYM)
    ),
    [SYM] = LAYOUT_split_3x6_3(
        _______, DE_AT,   DE_LPRN, DE_RPRN, DE_UDIA, DE_SS,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
        _______, DE_BSLS, DE_LCBR, DE_RCBR, DE_ADIA, DE_ODIA,       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  XXXXXXX,
        XXXXXXX, DE_EURO, DE_LBRC, DE_RBRC, DE_CIRC, DE_GRV,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
                                   _______, _______, _______,       _______, _______, _______
    ),
    [NUM] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       DE_7,    DE_8,    DE_9,    DE_TILD, XXXXXXX,  _______,
        _______, KC_LGUI, KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,       DE_4,    DE_5,    DE_6,    DE_PIPE, XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX, C(S(DE_X)), C(S(DE_C)), C(S(DE_V)), XXXXXXX,       DE_1,    DE_2,    DE_3,    DE_QUES, XXXXXXX,  _______,
                                      _______,    _______,    _______,       _______, _______, DE_0
    ),
    [FUN] = LAYOUT_split_3x6_3(
        SH_TG,   OS_GUI,  OS_ALT,  OS_CTL,  OS_SFT,  XXXXXXX,       KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX,  _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,       KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX, C(DE_X), C(DE_C), C(DE_V), XXXXXXX,       KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX,  _______,
                                   _______, _______, _______,       _______,  _______, _______
    ),
    [NAV] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  SH_TG,
        CW_TOGG, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  XXXXXXX,
        KC_CAPS, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,
                                   _______, _______, _______,       _______, _______, _______
    ),
    [OTHER] = LAYOUT_split_3x6_3(
        KC_VOLU, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,       XXXXXXX, IJ_RUN,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, INS_MODE,XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                   _______, _______, _______,       _______, _______, _______
    ),
    [MOUSE] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DRAG_SCROLL,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                   KC_BTN3, KC_BTN1, KC_BTN2,       _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef POINTING_DEVICE_ENABLE
    if (get_highest_layer(state) != AUTO_MOUSE_DEFAULT_LAYER) {
        set_scrolling = false;
    }
#endif
    return update_tri_layer_state(state, FUN, NAV, OTHER);
}

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
