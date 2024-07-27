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
typedef struct a {J t,c,n,r,s[1];} *A;
// init Array
V initA(A*a,J t,J n,J r,J*s);
// free Array
V freeA(A *a);

#endif
