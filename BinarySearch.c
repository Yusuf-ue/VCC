#include <vcc.h>
#include <limits.h>

unsigned binary_search(int val, int *arr, unsigned len) 
{
  unsigned low, high, mid;
  low = 0; high = len;
  while (low < high)
  {
    mid = (high + low) / 2;
    if (arr[mid] < val)             low = mid + 1;
    else                            high = mid;
  }

  if (low < len && arr[low] == val) return low;
  else                              return UINT_MAX;
}
