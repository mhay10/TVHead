#include "expressions.h"

PROGMEM const unsigned char expr8x8[] = {
  8, 8, 0, // width, height, start

  // broken
  0x00, 0x00, 0x30, 0x38, 0x1c, 0x0e, 0x07, 0x03,
  0x00, 0x00, 0x0c, 0x1c, 0x38, 0x70, 0xe0, 0xc0,
  0x03, 0x07, 0x0e, 0x1c, 0x38, 0x30, 0x00, 0x00,
  0xc0, 0xe0, 0x70, 0x38, 0x1c, 0x0c, 0x00, 0x00,

  // happy
  0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x38, 0x70,
  0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0x1c, 0x0e,
  0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,

  // surprised
  0x00, 0x00, 0x03, 0x0f, 0x1c, 0x18, 0x30, 0x30,
  0x00, 0x00, 0xc0, 0xf0, 0x38, 0x18, 0x0c, 0x0c,
  0x30, 0x30, 0x18, 0x1c, 0x0f, 0x03, 0x00, 0x00,
  0x0c, 0x0c, 0x18, 0x38, 0xf0, 0xc0, 0x00, 0x00,

  // skeptical
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00,

  // tired
  0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x60,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06,
  0x70, 0x38, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x0e, 0x1c, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00,

  // neutral
  0x00, 0x00, 0x00, 0x03, 0x0f, 0x0f, 0x1f, 0x1f,
  0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf0, 0xf8, 0xf8,
  0x1f, 0x1f, 0x0f, 0x0f, 0x03, 0x00, 0x00, 0x00,
  0xf8, 0xf8, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x00,

  // angry left
  0x00, 0x00, 0x00, 0x00, 0x30, 0x3c, 0x0f, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf0, 0x3c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,

  // angry right
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x0c, 0x3c, 0xf0, 0xc0,
  0x0f, 0x3c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  // sad left
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x30, 0x70, 0xf8, 0xf8,
  0x1f, 0x1f, 0x0f, 0x0f, 0x03, 0x00, 0x00, 0x00,
  0xf8, 0xf8, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x00,

  // sad right
  0x00, 0x00, 0x00, 0x00, 0x0c, 0x0e, 0x1f, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0,
  0x1f, 0x1f, 0x0f, 0x0f, 0x03, 0x00, 0x00, 0x00,
  0xf8, 0xf8, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x00
};
