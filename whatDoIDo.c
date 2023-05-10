#include <vcc.h>
#include <limits.h>

/* Exercise:
  Figure out what the function is supposed to do.
  Modify a contract known from other excercises.
  Correct an "off-by-one" error in the implementation
  and verify the function.
*/

unsigned whatDoIDo(int val, int *arr) 
{
  int low;
  low = 0;

  if (arr[511] < val)		low = 1000 - 512;
  if (arr[low+256] < val)	low += 256;
  if (arr[low+128] < val)	low += 128;
  if (arr[low+64] < val)	low += 64;
  if (arr[low+32] < val)	low += 32;
  if (arr[low+16] < val)	low += 16;
  if (arr[low+8] < val)	low += 8;
  if (arr[low+4] < val)	low += 4;
  if (arr[low+2] < val)	low += 2;
  if (arr[low+1] < val)	low += 1;
  low += 1;

  if (low < 1000 && arr[low] == val)	return (unsigned)low;
  else								                return UINT_MAX;
}

