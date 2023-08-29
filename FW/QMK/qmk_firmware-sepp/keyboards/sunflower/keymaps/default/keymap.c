#include "sunflower.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6)
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_UP);
    } else {
        tap_code(KC_DOWN);
    }
    return false;
}

