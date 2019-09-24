#include <stdio.h>
#include "lt_comn.h"


void print_odds(uchar type)
{
  switch (type) {
  case MEGA_MILLIONS:
    print_megamillions_odds();    
    break;
  case POWER_BALL:
    print_powerball_odds();
    break;
  case SUPER_LOTTO:
    print_superlotto_odds();
    break;
  case FANTASY_5:
    print_fantasy5_odds();
    break;
  case DAILY_4:
    print_daily4_odds();
    break;
  case DAILY_3:
    print_daily3_odds();
    break;
  case CUSTOM:
    print_custom_odds();
  default:
    break;
  }
}

void print_megamillions_odds()
{
    lt_factorial(MM_WMAX, MM_WNUM, MM_RMAX);
}
void print_powerball_odds()
{
    lt_factorial(PB_WMAX, PB_WNUM, PB_RMAX);
}
void print_superlotto_odds()
{
    lt_factorial(SL_WMAX, SL_WNUM, SL_RMAX);
}
void print_fantasy5_odds()
{
    lt_factorial(F5_WMAX, F5_WNUM, 1);
}
void print_daily4_odds()
{
}
void print_daily3_odds()
{
}
void print_custom_odds()
{
}
