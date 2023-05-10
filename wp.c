#include "verification.h"

void truthTable()
{
  // negation
  _(assert ! \false <==> \true)
  _(assert ! \true <==> \false)



/* Exercise: 
   Complete the truth-table assertion for
   conjunction, disjunction, implication and equivalence.
   Check the assertion by verifying the function truthTable().
*/

  // conjunction
  _(assert  (\false && \false) <==> \false)

  // disjunction
  _(assert  (\false || \false) <==> \false)

  // implication
  _(assert  (\false ==> \false) <==> \true)

  // equivalence
  _(assert  (\false <==> \false) <==> \true)



  // quantification

  _(assert  (\forall int i; i <= i) <==> \true)

}


void wpAssignment()
{ 
  int x,y;


/* Exercise: 
   Add assertions and an assumption simulating wp calculation of the statement,
   such that the function verifies.
*/

  x = y + 1;

  _(assert x >= y)


}

void wpAssignmentSelf()
{ 
  int x, y;

  _(ghost int X = x)
  _(ghost int Y = y)

/* Exercise: 
   Add assertions and an assumption simulating wp calculation of the statement,
   such that the function verifies.
*/

  x = x + 1;

  _(assert x > X && y == Y)



}


void wpConditional()
{
    int x;
    bool y;

    _(ghost int X = x)
    _(ghost int Y = y)


/* Exercise: 
   Add assertions and an assumption simulating wp calculation of the if statement
   and the statements in the two branches of the if,
   such that the function verifies.
   
*/

  if (y)
  {
        x = x + 1;
  }
  else
  {  
        x = x - 1;
  }

  _(assert (!(y) ==> x == X-1) && (y ==> x == X+1))



}

void wpLoop()
{
    int x, y;

    _(ghost int XL)
    _(ghost int YL)

    _(ghost int X = x)
    _(ghost int Y = y)



/* Exercise: 
   Add assertions, invariants of the while statement, 
   and an assumption simulating wp calculation,
   such that the function verifies.
   In the loop body, use ghost code to safe the current values
   of x and y in XL and YL, respectively.
*/

  while (0 < x)
  {
    y++;
    x--;
  }

  _(assert y == X+Y)


}

