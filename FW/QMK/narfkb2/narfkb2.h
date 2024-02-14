#pragma once

#include "quantum.h"

#define LAYOUT( \
  L00, L01, L02, L03, L04, L05,                                     R45, R44, R43, R42, R41, R40, \
  L10, L11, L12, L13, L14, L15,           L18,       R58,           R55, R54, R53, R52, R51, R50, \
  L20, L21, L22, L23, L24, L25, L26, L27, L28,       R68, R67, R66, R65, R64, R63, R62, R61, R60, \
                                L36, L37, L38,       R78, R77, R76 \
  ) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15, KC_NO, KC_NO, L18 }, \
    { L20, L21, L22, L23, L24, L25, L26, L27, L28 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, L36, L37, L38 }, \
    { R40, R41, R42, R43, R44, R45 }, \
    { R50, R51, R52, R53, R54, R55, KC_NO, KC_NO, R58 }, \
    { R60, R61, R62, R63, R64, R65, R66, R67, R68 }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, R76, R77, R78 } \
  }
