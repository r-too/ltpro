#include <gd.h>
#include <stdio.h>
#include "lt_comn.h"

#define rcolor (rand() % 255)

int gdmain() {
  
  gdImagePtr im;
  FILE *pngout;
  int black, white;
  
  lt_srand_init();
  im = gdImageCreate(512, 512);
  black = gdImageColorAllocate(im, 0, 0, 0);
  white = gdImageColorAllocate(im, 0xff, 0xff, 0xff);

  for (int x = 0; x < 512; x += 32) 
    for (int y = 0; y < 512; y += 32) {
      gdImageFilledRectangle(im, x, y, x+32, y+32, ((int)(rand() %2))?black:white);
    }

  pngout = fopen("test.png", "wb");
  gdImagePng(im, pngout);
  fclose(pngout);
  gdImageDestroy(im);

  return 0;
}
