#include "verification.h"


struct range {
  int low;
  int high;

  _(invariant low <= high)

};

struct rangeRestricted {
  int x;
  struct range * r;

  _(invariant r->low <= x && x <= r->high)


/* Exercise:
   Add invariants to make rangeRestricted admissible.
   (Check admissibility by right-clicking inside the struct and verifying).
*/


};

void setRange(struct rangeRestricted * y, struct range * r)
  _(writes y)
  _(maintains \wrapped(y))

  // needed to ensure the invariant of y
  _(requires r->low <= y->x && y->x <= r->high)


/* Exercise:
   Extend the contract to make setRange verify.
*/


{
  _(unwrapping y)
  {
    y->r = r;
  }
}
