
#include <vcc.h>
#include <limits.h>
#include "verification.h"

void update ( int * x, int * y, int a )
_(writes x)
_(requires \mutable(x) && \mutable(y))
_(ensures *x == a + \old(*y))
{
  *x = a + *y;
}
void scenario ( int * v, int * w) 
_(writes v, w)
_(requires \mutable(v) && \mutable(w))
_(requires *v == 6 + *w)
{
  update(v,w,6);
  _(assert *w == \old(*w))
}