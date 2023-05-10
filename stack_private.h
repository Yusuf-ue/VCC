#include "verification.h"

typedef _(dynamic_owns) struct StackNode
{
  struct StackNode *next;
  StackItem key;
  _(ghost StackIndex index;) 
  _(ghost StackItem entries[StackIndex];) 

  // has been allocated as a single region by malloc, so it can be free'd by free
  _(invariant \malloc_root(\this))

  // one node owns the next one in the list
  _(invariant ((next == NULL) || \mine(next)))

  //  indexes are decreasing down the chain, counting from 0
  _(invariant ((next != NULL) ==> (index > 0) && (index == next->index + 1)))
  _(invariant ((next == NULL) ==> (index == 0)))

  // entries is abstraction of stack up to this node
  _(invariant entries[index] == key)
  _(invariant \forall  StackIndex idx ; (0 <= idx) && ( idx < index ) 
                   ==> (next->entries[idx] == entries[idx] ))
} *PStackNode;

typedef _(dynamic_owns) struct Stack
{
  struct StackNode *list;
  StackIndex size;
  StackIndex max;

  // Stack is a data refinement of AbsStack
  _(ghost PAbsStack abs;) 

  _(invariant \malloc_root(\this))
    
  // invariants mirroring abstract stack properties
  // these are redundant but help VCC
  _(invariant 0 < max && size <= max)

  // size is the number of StackNodes in list
  _(invariant (list != NULL) ==> (size > 0) && (size - 1 == list->index)) 
  _(invariant (list == NULL) ==> (size == 0)) 

  // abstraction relation
  _(invariant (size == abs->highMark) &&
              (max == abs->capacity) &&
              (\forall  StackIndex idx ; (0 <= idx) && ( idx < size ) 
                        ==> (list->entries[idx] == abs->items[idx] )))

  // ownership hierarchy
  _(invariant \mine(abs)) 
  _(invariant (list != NULL) ==> \mine(list))

} *PStack;
