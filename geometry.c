#include "verification.h"

// --------------- point --------------

#define MaxX 16
#define MaxY 16

#define inrange(x,max) 0 <= x && x < max
#define inrangeX(x) inrange(x,MaxX)
#define inrangeY(y) inrange(y,MaxY)

// a point in the 2-dim plane (0..MaxX,0..MaxY)
typedef struct _Point {
  int x, y; 
  _(invariant inrangeX(x))
  _(invariant inrangeY(y))
} Point;

#define eqPointP(a,b) ((a)->x == (b)->x && (a)->y == (b)->y)

/* Excercise:
  Specify, implement and verify the pure function eqPoint
*/

_(pure)
bool eqPoint(Point *a, Point*b)
{

}

// create a new Point using fresh memory
Point * newPoint(int nx, int ny)
  _(requires inrangeX(nx) && inrangeY(ny))
  _(ensures \wrapped(\result))
  _(ensures \fresh(\result))
  _(ensures \result->x == nx && \result->y == ny)
{
  Point *a;
  
  a = (Point *) malloc(sizeof(Point));
  // assume that allocation was successful
  _(assume a != NULL)

  a->x = nx;
  a->y = ny;

  _(wrap a)

  return a;
}

#define shiftInRangeP(a,dx,dy) (inrangeX(a->x + dx) && inrangeY(a->y + dy))

#define shiftedPointP(a,dx,dy) ((a)->x == \old((a)->x) + dx && (a)->y == \old((a)->y) + dy)

// shift a point by the vector (dx,dy)
void shiftPoint(Point *a, int dx, int dy) 
  _(writes a)
  _(maintains \wrapped(a))
  _(requires shiftInRangeP(a,dx,dy))
  _(ensures shiftedPointP(a,dx,dy))
{
  _(unwrap a);
  a->x += dx;
  a->y += dy;
  _(wrap a)
}

// --------------- straight lines ----------------

/* Excercise:
  Specify, implement and verify the pure function onStraightLine.
*/

#define onStraightLineDistinctP(a,b,c) (((b)->x - (a)->x) * ((c)->y - (a)->y) == ((c)->x - (a)->x) * ((b)->y - (a)->y))

_(pure)
bool onStraightLine(Point *a, Point *b, Point *c)

{

}

// --------------- triangles ----------------

#define pairwiseDisjointP(v,n) (\forall unsigned j, k; j < k && k < n ==> (v[j]) != (v[k]))

/* Excercise:
  Extend the following type definition with appropriate invariants.
  Refer to the three vertices with constant indexes, such as vertex[1].
*/

typedef struct _Triangle {
  Point *vertex[3];

  /* add invariants here */

  // VCC does not infer this automatically
  _(invariant pairwiseDisjointP(vertex,3))
} Triangle;

/* Excercise:
  Specify, implement, and verify shiftTriangle,
  which is supposed to provide a parallel translation 
  of the Triangle t by the vector (dx,dy).
*/

void shiftTriangle(Triangle *t, int dx, int dy)

{

}
