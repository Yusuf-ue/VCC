#include "verification.h"

#define N 16  
#define inRange(l,x,h) l <= x && x < h 

_(ghost 
  typedef struct _Abs {
  int a;
  _(invariant inRange(0,a,N))
  } Abs;
)

#define abstractsTo(abs,conc) \
      (0 <= conc->b ==> abs->a == conc->b) \
  &&  (conc->b < 0 ==> abs->a == conc->b + N)

typedef struct _Conc {
  int b;
  _(ghost Abs *abs)

  _(invariant \mine(abs))
  _(invariant inRange(-N,b,N))
  _(invariant abstractsTo(abs,\this))
} Conc;


int Get(Conc *c)
  _(maintains \wrapped(c))
  _(returns c->abs->a)
  _(ensures inRange(0,\result,N))
{   

/* Excercise: 
  Add implementation here
*/

};

void Set(Conc *c, int v)
  _(writes c)
  _(maintains \wrapped(c))
  _(requires inRange(-N,v,N))

/* Excercise: 
  add postcondition 
*/

{
  _(unwrapping c)
  {
    c->b = v;

/* Excercise:
  add code here
*/

  };
};
