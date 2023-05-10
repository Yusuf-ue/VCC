// look at account.c first!
#include "account.c"


struct AccountGroup {

  // account group owns these two accounts
  struct Account *giro;       
  struct Account *creditCard;

  int total; // the total amount in both giro and creditCard

/* Exercise:
   Provide invariants for AccountGroup making sure that
   - both accounts are valid
   - total is kept within appropriate limits
   - total contains the right amount.
   Remember to specify ownership!
*/


};

// transfers amount from a->giro to b->giro
void transferGiro(struct AccountGroup* a, struct AccountGroup* b, int amount)

/* Exercise:
   Provide a contract for transferGiro that keeps a and b wrapped,
   and describes the effect of the transfer on all accounts.
*/


{

/* Exercise:
   1. add ghost code to make transferGiro verify.
   2. replace the two assignments below by the call
      to transfer and verify again.
*/

  a->giro->amount = a->giro->amount - amount;
  b->giro->amount = b->giro->amount + amount;
  
  // transfer(a->giro,b->giro,amount);

  a->total = a->total - amount;
  b->total = b->total + amount;

}
