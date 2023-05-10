#include <vcc.h>
#include <limits.h>

#include "FillPage.h"
// specify fillPage before verifying fillBufferPages

/* Exercise: 
   Specify and verify fillBufferPages:
   1. Set up a preliminary contract and verify memory safety, providing appropriate loop invariants
   2. Augment the contract to describe the effect of fillBufferPages and verify, 
      providing additional loop invariants and an assertion after "_(lemma1)".
*/

#define lemma1 assert \forall unsigned i,j; int *a; {(a)[j+i]} (a+j)[i] == val ==> (a[j+i] == val)

// fill all consecutive pages starting at arr upto len with val
void fillBufferPages(int val, int *arr, unsigned len) 
{
  unsigned idx;

  idx = 0;

  while ((idx+1)*PAGELEN <= len)
  {
    fillPage(val,arr+(idx*PAGELEN));

    _(lemma1)
    /* add an assertion here to verify the loop invariant */

    idx++;
  }
}
