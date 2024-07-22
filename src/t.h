// types
#ifndef y_t_h
#define y_t_h

#include "0.h"

// types
#define t_int 1
#define t_float 2
// ...

// Table(variable storage)

// Array
// type,reference count,atoms,rank,shape(pointer)
// type      -> [1,2] => types
// ref count -> reference count
// atoms     -> n (r + s[0])
// rank      -> [0,1,2] => n of dimensions
//           \> r = 0 => s[0] = empty(kjust pointer)
//           \> r = 1 => s[0] = row(n)
//           \> r = 2 => s[0] = row(n)
//                   \=> s[1] = column(n)
// shape     -> shape of the array
typedef struct {I t,c,n,r,s[1];} A;

// new Array
A newA(I t,I n,I r,I*s);
// (type)a->t
#define AT a->t
// (reference count)a->c
#define AC a->c
// (atoms/number of elements)a->n
#define AN a->n
// (rank)a->r
#define AR a->r
// (shape)a->s
#define AS a->s
// free Array
V freeA(A *a);

#endif
