
#include "FillPage.h"

/* Exercise: 
   Verify fillPage based on the contract in FillPage.h
   First verify memory safety (temporarily weakening the contract accordingly).
   Then add a loop invariant to verify the full contract.
*/

void fillPage(int val, int *arr)
{
  unsigned idx;

  idx = 0;

  while (idx < PAGELEN)
  {
    arr[idx++] = val;
  }
}