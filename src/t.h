// types
#ifndef y_t_h
#define y_t_h

#include "0.h"

// types
typedef enum t{t_none,t_char,t_int,t_float,t_bool,t_null,t_dict,t_time}t;
// ...

// Table(variable storage)

// Array
// type,reference count,rank,atoms,shape(pointer)
typedef struct a{u8 t,c;u16 r;u32 n;V*s;}A;
// init Array
V initA(A*a);
// free Array
V freeA(A*a);
// write Array
V writeA(A*a,u8 t,u32 n,u16 r,V*s);

#endif
