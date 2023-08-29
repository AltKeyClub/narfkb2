#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                 KC_MPRV,    KC_MPLY, KC_MNXT,
                 C(KC_LEFT), KC_CALC, C(KC_RIGHT),
        KC_MUTE, S(KC_P),    MO(1),   S(KC_N)
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code_delay(KC_VOLU, 10);
    } else {
        tap_code_delay(KC_VOLD, 10);
    }
    return false;
}

