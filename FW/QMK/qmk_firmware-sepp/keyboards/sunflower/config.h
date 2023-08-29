#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS { GP26 }
#define MATRIX_COL_PINS { GP3, GP4, GP2, GP7, GP6, GP29, GP28 }

// #define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5


#define TAPPING_TERM 500
#define PERMISSIVE_HOLD

#define SERIAL_PIO_USE_PIO1

#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { GP1 }
#define ENCODERS_PAD_B { GP0 }
#define ENCODER_RESOLUTION 4

// #define ENCODER_DIRECTION_FLIP
