#include "stack.h"

unsigned int capacity(PStack s)
{
  return(s->max);
};

bool isEmpty(PStack s)
{
  return s->list == NULL;
}

bool isFull(PStack s)
{
  return s->size == s->max;
}

StackIndex numItems(PStack s)
{
  return s->size;
}

/* 
   add ghost code and verify
*/

PStack createStack( unsigned int maxCapacity )
{
  PStack s;

  s = (PStack) malloc(sizeof(struct Stack));
  _(assume s!=NULL)

  s->size = 0;
  s->max = maxCapacity;
  s->list = NULL;

  return s;
}


/* 
   add ghost code and verify
   hint: assert invariant and state of s->List
         after MakeEmpty(s);
   hint: do not forget to dispose abstract stack!
*/

void disposeStack(PStack s)
{
  clearStack(s);

  free(s);
}


/* 
   add invariants and verify
*/

void clearStack(PStack s)
{
  while(!isEmpty(s))
  {
    pop(s);
  } 
}


/* 
   add invariant assertion and verify
*/

StackItem top(PStack s)
{
  return s->list->key;
}

/* 
   add ghost code and verify
*/

void push(PStack s, StackItem x) 
{
  PStackNode newEntry = (PStackNode)malloc(sizeof(struct StackNode));
  _(assume newEntry != NULL)

  newEntry->key = x;
  newEntry->next = s->list;

  s->list = newEntry;
  s->size++;
}


/* 
   add ghost code and verify
   hint: keep track of ownership!
   hint: modify s->abs to preserve invariant!
*/

void pop(PStack s)
{ 
  struct StackNode *firstEntry = s->list;

  s->list = firstEntry->next;
  s->size = s->size - 1 ;
  free(firstEntry);
}
