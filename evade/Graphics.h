#ifndef GRAPHICS_H
#define GRAPHICS_H

/**
 * Portions of this class were lifted from the Arduboy2 library/class.
 * See https://github.com/MLXXXp/Arduboy2
 */
#include "Game.h"

// INLINE_PLOT causes more code by including the plotPixel logic inline in the line drawing
// code.  This saves the overhead of push, push, push the arguments to the drawing function
// and the function call, and the pop, pop, pop.  The performance is noticeably better.
// TODO: maybe get rid of this and just inline, period.
#define INLINE_PLOT
//#undef INLINE_PLOT

// SMART_ERASE is experimental and appears to be too slow for production use at this time
// We can speed it up by tracking the lines and points drawn and simply erasing those.
// The cost is precious SRAM.
#define SMART_ERASE
#undef SMART_ERASE

#ifndef BLACK
#define BLACK 0
#endif

#ifndef WHITE
#define WHITE 1
#endif

class Graphics {
public:
  static void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color = WHITE);
  static void drawPixel(WORD x, WORD y);
  static void drawPixel(WORD x, WORD y, UBYTE color);
  static void drawLine(WORD x, WORD y, WORD x2, WORD y2);
  static void drawVectorGraphic(const BYTE *graphic, float x, float y, float theta, float scaleFactor);
  static void explodeVectorGraphic(const BYTE *graphic, float x, float y, float theta, float scaleFactor, BYTE step);
  static void fillScreen(UBYTE color);
  static void display(BOOL clear);
#ifdef SMART_ERASE
  static void eraseLine(WORD x, WORD y, WORD x2, WORD y2);
  static void eraseVectorGraphic(const uint8_t *graphic, float x, float y, float theta, float scaleFactor){
#endif
  };

#endif