
#include "verification.h"

/* Excercise:
   Try to verify framing().
   Which additional precondition is needed to make
   the verification succeed?
*/

void increment(int* x)
	_(writes x)
	_(requires *x < INT_MAX)
	_(ensures *x == \old(*x) + 1)
{

/* What is the difference between (*x)++ and *x++ ?
*/
  (*x)++;    
  x++;

  return;
}


/* Excercise:
   Try to verify framing().
   Which additional precondition is needed to make
   the verification succeed?
*/

void framing(int *x, int *y)
	_(writes x,y)
{
  _(assume *x == 1 && *y == 1)

  increment(y);

  _(assert *x == 1) 
}