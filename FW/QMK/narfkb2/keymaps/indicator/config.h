

#pragma once

// Set number of layers for VIA (+30 per layer)
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#define WS2812_DI_PIN GP16
#define RGB_DI_PIN GP16

#define RGBLED_NUM 2
#define RGBLED_SPLIT {1,1}
#define RGBLIGHT_LIMIT_VAL 30//Power draw may still exceed the USB limitations of 0.6A at max brightness with white colour with this setting.
//#define RGBLIGHT_SLEEP //Turn off LEDs when computer sleeping (+72)
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF





