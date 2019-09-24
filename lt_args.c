#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lt_comn.h"

char *custom_opts;

int lt_args(int argc, char **argv, struct lt_opts *opts)
{
  int c;
  
  if (argc < 2) {
    usage();
    exit(1);
  }

  opts->iter = 1;
 
  while ((c = getopt(argc, argv, "hp:c:t:i:")) != -1) {
    switch(c) {
    case 't':
      set_type(optarg, &opts->type);
      break;
    case 'i':
      opts->iter = atoi(optarg);
      if (opts->iter > 65535) opts->iter = 65535;
      break;
    case 'c':
      opts->type = CUSTOM;
      custom_opts = malloc(strlen(optarg)+1);
      memset(custom_opts, '\0', strlen(optarg)+1);
      strncpy(custom_opts, optarg, strlen(optarg));
      break;
    case 'p':
      set_type(optarg, &opts->type);
      print_odds(opts->type);
      exit(0);
    default:
      usage();
      exit(1);
    }
  }
  
  return 0;
}

void set_type(char *optarg, uchar *type) 
{
  if (strncasecmp(optarg, "mm", 2) == 0) *type = MEGA_MILLIONS;
  else if (strncasecmp(optarg, "pb", 2) == 0) *type = POWER_BALL;
  else if (strncasecmp(optarg, "sl", 2) == 0) *type = SUPER_LOTTO;
  else if (strncasecmp(optarg, "f5", 2) == 0) *type = FANTASY_5;
  else if (strncasecmp(optarg, "d4", 2) == 0) *type = DAILY_4;
  else if (strncasecmp(optarg, "d3", 2) == 0) *type = DAILY_3;
}

void usage()
{
  printf("\n\
Usage: ltpro [options]\n\
-t ${lottery_type} - must be 'mm', 'pb', 'sl', 'f5', 'd4' or 'd3'\n\
-i ${iterations} - can be between 1 and 65535. Default is 1\n\
-c ${custom_options} - range:$min-$max,num:$n,rep:$r\n\
-p ${lottery_type} - must be 'mm', 'pb', 'sl', 'f5', 'd4' or 'd3'\n\
   print lottery odds\n\
\n\
-h this help\n\
\n\
mm - Mega Millions\n\
pb - Power Ball\n\
sl - Super Lotto Plus\n\
f5 - Fantasy 5\n\
d4 - Daily 4\n\
d3 - Daily 3\n\
\n");

} 
