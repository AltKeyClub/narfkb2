#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        C(KC_W),   KC_MPRV,      KC_MPLY, KC_MNXT,
        C(KC_0),   C(KC_LEFT),   KC_CALC, C(KC_RIGHT),
        KC_MUTE,   S(KC_P),      MO(1),   S(KC_N)
    ),
    [1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(A(KC_RIGHT));
        } else {
            tap_code16(A(KC_LEFT));
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(C(KC_PPLS));
        } else {
            tap_code16(C(KC_PMNS));
        }
    } else if (index == 2) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return false;
}
