// look at contracts.h first!

#include "contracts.h"




int remainder(int x, int y)
{
    int r = x;
    int q = 0;

/* Excercise:
  Annotate the loop with invariants, such that remainder() verifies.

  Annotate the loop body with assertions simulating how the invariants propagate 
  over the statements in the loop body.

  Do NOT use division or remainder functions in the invariants and assertions.
  Only use addition, subtraction or multiplication.

  State the canonical postcondition of the loop body as an assertion after the loop.
*/
  while (r >= y)
  {   
    r = r-y;
    q = q + 1;
  }

 _(assume \false)
/* Exercise:
   After completing the verification of the loop,
   comment out the "assume \false" and try to verify
   the following assertion (which reflects the postcondition of remainder().
   Use the Z3 inspector to figure out what condition the prover fails to verify.
   Add a suitable assumption that connects the postcondition of the loop and the postcondition of remainder()
   to help the prover.
*/

  _(assert r == x % y)

  return(r);
}

int round(int x, int y)
{ 
  int d;
  int r;


/* Excercise:
   State the preconditions and postconditions of remainder() 
   as assertions before and after the function call.
*/
  r = remainder(x,y);



  d = _(unchecked)(x - r);
  return(d);
}
