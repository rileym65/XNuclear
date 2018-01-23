#include <X11/Xlib.h>
#include "librcs.h"
#include <stdarg.h>

typedef unsigned char byte;

#define declare
#include "support.h"

int rndm(int x)
  {
    RandSeed=RandSeed*9821.0+0.211327;
    RandSeed=RandSeed-int(RandSeed);
    return int(RandSeed*x)+1;
  }
