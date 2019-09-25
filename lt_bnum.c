#include <gmp.h>
#include <stdio.h>
#include <assert.h>

int main(){

  char inputStr[1024];
  mpz_t n;
  int flag;

  printf ("Enter your number: ");
  scanf("%1023s" , inputStr); 

  mpz_init(n);
  mpz_set_ui(n,0);

  flag = mpz_set_str(n,inputStr, 10);
  assert (flag == 0); 

  printf ("n = ");
  mpz_out_str(stdout,10,n);
  printf ("\n");

  mpz_add_ui(n,n,1); 

  printf (" n +1 = ");
  mpz_out_str(stdout,10,n);
  printf ("\n");

  mpz_mul(n,n,n); 


  printf (" (n +1)^2 = ");
  mpz_out_str(stdout,10,n);
  printf ("\n");
  mpz_clear(n);

}
