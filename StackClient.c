#include "stack.h"


////////////////////////////////////////////////////////////////////////////
//
// This is the entry point for the execution of this code.
//
////////////////////////////////////////////////////////////////////////////

#define numItems 10
void StackAsList() 
{
  PStack myStack;
  StackItem x;

  myStack = createStack(numItems);

  _(assert isEmpty(myStack))
  _(assert !isFull(myStack))

  push(myStack,3);

  _(assert !isEmpty(myStack))
  _(assert !isFull(myStack))

  _(assert myStack \in \domain(myStack))
  _(assert myStack->abs \in \domain(myStack))

  _(assert myStack->abs->items[0] == 3)

  push(myStack,2);
  
  _(assert top(myStack) == 2)

  pop(myStack);

  _(assert top(myStack) == 3)

  clearStack(myStack);

  _(assert isEmpty(myStack))
  _(assert !isFull(myStack))

  push(myStack,1);

  _(assert !isEmpty(myStack))

  x = top(myStack);

  _(assert x == 1)

  disposeStack(myStack);

}
