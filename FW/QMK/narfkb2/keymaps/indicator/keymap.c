#include QMK_KEYBOARD_H
extern rgblight_config_t rgblight_config;


enum layers { BASE = 0, RAISE, LOWER, SET, GAME };

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
        [LOWER] =  { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
        [RAISE] =  { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
        [SET] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
        [GAME] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    };
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                                          KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_MPLY,     KC_MUTE,                   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, _______, _______, _______,     _______, _______, _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
                                   KC_LWIN, MO(1), KC_SPC,                                   KC_SPC,  MO(2), KC_RALT
    ),
    [RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
                                            _______, _______, KC_SPC,                                          KC_SPC,  MO(3), _______
    ),
    [LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
                                            _______, MO(3), KC_SPC,                                            KC_SPC,  _______, _______
    ),
    [SET] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
                                            _______, _______, KC_SPC,                                          KC_SPC,  _______, _______
    ),
    [GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
                                            _______, _______, KC_SPC,                                          KC_SPC,  _______, _______
    )
};

//Capas RGB (El led 0 es el del controlador izquierdo y el 1 el del lado derecho)
const rgblight_segment_t PROGMEM my_base[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,2,HSV_WHITE} //Se enciende en color blanco 2 leds a partir del led 0
);

const rgblight_segment_t PROGMEM my_raise[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1,HSV_BLUE} //Se enciende en color azul 1 led a partir del led 1
);

const rgblight_segment_t PROGMEM my_lower[] = RGBLIGHT_LAYER_SEGMENTS(
    {1,1,HSV_RED}
);

const rgblight_segment_t PROGMEM my_set[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,2,HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1,HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_gaming[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1,HSV_RED},
    {1,1,HSV_YELLOW}
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_base,
    my_raise,
    my_lower,
    my_set,
    my_gaming,
    my_capslock
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
   };

//Función booleana para encender o apagar el indicador de CAPS LOCK
bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(5, led_state.caps_lock);
	return true;

}

 //Capa RGB default BASE en color blanco
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    return state;
}

//Resto de capas RGB en distintos colores
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, SET));
    rgblight_set_layer_state(4, layer_state_cmp(state, GAME));
    return state;
}

//******************************************************************************

