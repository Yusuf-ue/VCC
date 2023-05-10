#include "verification.h"

#define StackItem int
#define StackIndex unsigned int


_(ghost typedef struct _AbsStack {
	StackIndex highMark;       // number of items on the stack
	StackIndex capacity;       // maximum number of items on the stack

  // this is a map: a "mathematical" array;
  // its index ranges of all elements of the type(!) StackIndex
  StackItem items[StackIndex]

  _(invariant 0 < capacity && highMark <= capacity)

  // this is a complete malloc region and can be free'd as a whole
  _(invariant \malloc_root(\this))

  // ^PAbsStack is a ghost pointer 
} AbsStack, ^PAbsStack;)


#include "stack_private.h"


_(pure)
unsigned int capacity(PStack s)
  _(reads s)
  _(requires \wrapped(s))
  _(returns s->abs->capacity)
;

_(pure)
bool isEmpty(PStack s)
  _(reads s)
  _(requires \wrapped(s))
  _(ensures \result == (s->abs->highMark == 0))
;

_(pure) 
bool isFull(PStack s)

/* 
   insert contract here 
*/
;

StackIndex numItems(PStack s)

/* 
   insert contract here 
*/
;

PStack createStack( unsigned int maxCapacity )
  _(requires maxCapacity > 0)
  _(ensures \wrapped(\result))
  _(ensures isEmpty(\result))
  _(ensures maxCapacity == capacity(\result))
  _(ensures \fresh(\result))
  _(ensures \fresh(\result->abs))
  ;


/* 
   verify according with the given contract
*/

void disposeStack(PStack s)
  _(writes s)
  _(requires \wrapped(s))
  // ensures "nothing", so the caller does not know anything about S after disposing it.
;

void clearStack(PStack s)

/* 
   insert contract here 
*/
;

void push(PStack s, StackItem x)
/* 
   insert contract here 
*/
;

_(pure)
StackItem top(PStack s)

/* 
   insert contract here 
*/
;

void pop(PStack s)

/* 
   insert contract here 
*/
;
