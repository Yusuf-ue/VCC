#include "verification.h"

#define LOW_LIMIT -10000
#define UP_LIMIT 25000

struct Account {
  int amount;

  _(invariant LOW_LIMIT <= amount && amount <= UP_LIMIT)
};

// transfers amount from account a to account b
void transfer(struct Account* a, struct Account* b, int amount)

/* Excercise:
   Provide a contract for transfer() such that no money is lost
   and the function verifies.
*/


{
  _(unwrap a)  // make a mutable
  _(unwrapping b)   // "unwrapping" has the same effect as unwrapping at beginning of block and wrapping at the end
  {
    a->amount = a->amount - amount;
    b->amount = b->amount + amount;
  }
  _(wrap a)   // wrap a; invariant of a must hold!
}

