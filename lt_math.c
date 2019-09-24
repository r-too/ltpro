#include <stdio.h>
#include <gsl/gsl_sf_gamma.h>
#include "lt_comn.h"

#define FACT gsl_sf_fact

int lt_factorial(uint total_num, uint draw_num, uint ad_num)
{
  for (int i = 1; i <= draw_num; i++) {
    printf("% 20ld - ", (long) (FACT(total_num)/(FACT(i)*FACT(total_num-i))));
    printf("% 20ld\n", (long) ((FACT(total_num)/(FACT(i)*FACT(total_num-i)))*ad_num));
  }
		  
  return 0;
}
