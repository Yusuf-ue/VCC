#include <vcc.h>
#include <limits.h>

#define PAGELEN 1024


// fill one page (size PAGELEN) starting at arr with val
void fillPage(int val, int *arr) 
  _(writes \array_range(arr,PAGELEN))
  _(requires \mutable_array(arr, PAGELEN))
  _(ensures \forall unsigned i; i < PAGELEN ==> arr[i] == val)
;
