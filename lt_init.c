#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lt_comn.h"

extern char *custom_opts;

void lt_init(struct lt_query *q)
{


  switch (q->lt_type) {
  case MEGA_MILLIONS:
    lt_megamillions_init(q);
    break;
  case POWER_BALL:
    lt_powerball_init(q);
    break;
  case SUPER_LOTTO:
    lt_superlotto_init(q);
    break;
  case FANTASY_5:
    lt_fantasy5_init(q);
    break;
  case DAILY_4:
    lt_daily4_init(q);
    break;
  case DAILY_3:
    lt_daily3_init(q);
    break;
  case CUSTOM:
    lt_custom_init(q);
  default:
    break;
  }
}

void lt_megamillions_init(struct lt_query *q)
{
  q->lt_type = MEGA_MILLIONS;

  q->wn_min = MM_WMIN;
  q->wn_max = MM_WMAX;
  q->t_wnum = MM_WNUM;
  q->wn_rep = MM_WREP;

  q->rn_min = MM_RMIN;
  q->rn_max = MM_RMAX;
  q->t_rnum = MM_RNUM;
  q->rn_rep = MM_RREP;

  memset(q->query_str, '\0', strlen(MM_QSTR)+1);
  memcpy(q->query_str, MM_QSTR, strlen(MM_QSTR));
}

void lt_powerball_init(struct lt_query *q)
{
  q->lt_type = POWER_BALL;

  q->wn_min = PB_WMIN;
  q->wn_max = PB_WMAX;
  q->t_wnum = PB_WNUM;
  q->wn_rep = PB_WREP;
  
  q->rn_min = PB_RMIN;
  q->rn_max = PB_RMAX;
  q->t_rnum = PB_RNUM;
  q->rn_rep = PB_RREP;

  memset(q->query_str, '\0', strlen(PB_QSTR)+1);
  memcpy(q->query_str, PB_QSTR, strlen(PB_QSTR));
}

void lt_superlotto_init(struct lt_query *q)
{
  q->lt_type = SUPER_LOTTO;

  q->wn_min = SL_WMIN;
  q->wn_max = SL_WMAX;
  q->t_wnum = SL_WNUM;
  q->wn_rep = SL_WREP;
  
  q->rn_min = SL_RMIN;
  q->rn_max = SL_RMAX;
  q->t_rnum = SL_RNUM;
  q->rn_rep = SL_RREP;
  
  memset(q->query_str, '\0', strlen(SL_QSTR)+1);
  memcpy(q->query_str, SL_QSTR, strlen(SL_QSTR));
}

void lt_fantasy5_init(struct lt_query *q)
{
  q->lt_type = FANTASY_5;

  q->wn_min = F5_WMIN;
  q->wn_max = F5_WMAX;
  q->t_wnum = F5_WNUM;
  q->wn_rep = F5_WREP;
  
  memset(q->query_str, '\0', strlen(F5_QSTR)+1);
  memcpy(q->query_str, F5_QSTR, strlen(F5_QSTR));
}

void lt_daily4_init(struct lt_query *q)
{
  q->lt_type = DAILY_4;

  q->wn_min = D4_WMIN;
  q->wn_max = D4_WMAX;
  q->t_wnum = D4_WNUM;
  q->wn_rep = D4_WREP;
 
  memset(q->query_str, '\0', strlen(D4_QSTR)+1);
  memcpy(q->query_str, D4_QSTR, strlen(D4_QSTR));
}

void lt_daily3_init(struct lt_query *q)
{
  q->lt_type = DAILY_3;

  q->wn_min = D3_WMIN;
  q->wn_max = D3_WMAX;
  q->t_wnum = D3_WNUM;
  q->wn_rep = D3_WREP;

  memset(q->query_str, '\0', strlen(D3_QSTR)+1);
  memcpy(q->query_str, D3_QSTR, strlen(D3_QSTR));
}

void lt_custom_init(struct lt_query *q)
{
  q->lt_type = CUSTOM;
  sscanf(custom_opts, "range:%hhu-%hhu,num:%hhu,rep:%hhu", &q->wn_min, &q->wn_max, &q->t_wnum, &q->wn_rep);
  // printf("min:%d, max:%d, num:%d, rep:%d\n", q->wn_min, q->wn_max, q->t_wnum, q->wn_rep);
  memcpy(q->query_str, CU_QSTR, strlen(CU_QSTR)); 
  free(custom_opts);
}
