#include "verification.h"

_(pure)  // a function without side effects
int remainder(int x, int y)

/* Exercise: 
   Add appropriate preconditions
*/

	// alternative: returns(x % y)
	_(ensures \result == x % y)
	;



_(pure)
int round(int x, int y)

/* Exercise: 
   Add appropriate preconditions
*/
	_(ensures \result == x - (x % y))
	;


