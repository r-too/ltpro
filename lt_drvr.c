#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "lt_comn.h"

int lt_drvr(struct lt_query *q)
{
  if (!q->lt_type) {
    printf("Lottery Type Un-initialized. ABORT!\n");
    return 1;
  }
    
  uchar WLIST[q->t_wnum];
  uchar RLIST[q->t_rnum];

  lt_srand_init();
 
  if (q->lt_type == CUSTOM && q->wn_rep == NO_REPEAT && (q->t_wnum > (q->wn_max - q->wn_min))) {
    printf("Options Error: Outside the Range of Possibilities! ABORT\n");
    return -1;
  }

  lt_generator_loop(q->t_wnum, q->wn_min, q->wn_max, q->wn_rep, WLIST);
  printf("%s : ", q->query_str);
  for (int c = 0; c < q->t_wnum; c++)
    printf("%02u ", WLIST[c]);

  if (q->t_rnum) {
    lt_generator_loop(q->t_rnum, q->rn_min, q->rn_max, q->rn_rep, RLIST);
    
    printf("|");
  
    for (int c = 0; c < q->t_rnum; c++)
      printf(" %02u ", RLIST[c]);

  }

  printf("\n");
  return 0;
}

void lt_srand_init()
{
  struct timespec tp;
  clock_gettime(CLOCK_MONOTONIC, &tp);
  srand(tp.tv_nsec);
}

void lt_generator_loop(uchar num, uchar min, uchar max, uchar rep, uchar *LIST)
{
  memset(LIST, 0, num);
   
  for (int i = 0; i < num; i++) {
GENL:
    LIST[i] = min + (rand() % ((max - min) + 1));

    if (rep == NO_REPEAT && i)
      for (int c = 0; c < i; c++)
        if (LIST[c] == LIST[i]) goto GENL;

  }
}
