#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lt_comn.h"

int main(int argc, char **argv)
{
  struct lt_opts opts = { 0 };
  lt_args(argc, argv, &opts);

  struct lt_query lq;
  lt_init(&lq, opts.type);

  while (opts.iter--) 
    lt_drvr(&lq);  
  
  return 0;
}
