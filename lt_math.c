#include <stdio.h>
#include <gsl/gsl_sf_gamma.h>
#include "lt_comn.h"

#define FACT gsl_sf_fact

int lt_factorial(uint total_num, uint draw_num, uint ad_num)
{
  for (int i = 1; i <= draw_num; i++)
    if (ad_num > 1) 
      printf("(%d of %d) %10ld | (%d of %d + 1 of %d) %10ld\n",\
           i, total_num,\
          (long) (FACT(total_num)/(FACT(i)*FACT(total_num-i))),\
           i, total_num, ad_num,\
          (long) ((FACT(total_num)/(FACT(i)*FACT(total_num-i)))*ad_num));
    else
      printf("(%d of %d) %10ld\n",\
           i, total_num,\
          (long) (FACT(total_num)/(FACT(i)*FACT(total_num-i))));
		  
  return 0;
}
