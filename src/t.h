// types
#ifndef y_t_h
#define y_t_h

#include "0.h"

// types
#define t_int 1
#define t_float 2
#define t_str 3
// ...

// Table(variable storage)

// Array
// type,reference count,rank,atoms,shape(pointer)
typedef struct a{u8 t,c;u16 r;u32 n;i64 s[1];}*A;
// init Array
V initA(A*a);
// free Array
V freeA(A*a);
// write Array
V writeA(A*a,u8 t,u32 n,u16 r,i64*s);

#endif
