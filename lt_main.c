#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lt_comn.h"

int main(int argc, char **argv)
{
  struct lt_opts opts = { 0 };
  lt_args(argc, argv, &opts);

  struct lt_query lq = { 0 };
  
  lq.lt_type = opts.type;
  lt_init(&lq);

  while (opts.iter--) 
    lt_drvr(&lq);  
  
  return 0;
}
