# y - implementation

> [!NOTE]
> For reading purposes have the types and names been adapted to be
> better understandable, furthermore will be all code be written in C.
> This shall be only seen as a _reference_ implementation.

## Miscellaneous

[0.h](../../src/0.h)

## Arguments

[a.h](../../src/a.h)

### Definition

```c
typedef struct arguments {
  bool help;
  bool version;
  bool interactive;
  bool execute;
  bool print;
} Arguments;
```

### Function

```c
// Parsing the Argumens from *argv*
void parseArguments(Arguments* args, int argc, const char** argv);
```

## Internal Data Type's

0. ~~
1. Character/Rune (String is 1 Dimensional Array)
2. Integer (64 bits)
3. Float (64 bits)
4. Boolean (0 or 1 integer)
5. null
6. Dictionarys
7. Time
8. Complex Number (?)
9. Box (Pointer to other Data Types) (?)

## Array's

[t.h](../../src/t.h)

### Definition

Similar to the [kona](https://github.com/kevinlawler/kona/wiki/C-Reference#k-object)
and [J](https://www.jsoftware.com/ioj/iojNoun.htm#Arrays) array types.

The array is in row major order (first row then column).

Currently the following data type adds up to 16 bytes ... from 40 when using
long long for all values.

```c
typedef struct array {
  unsigned char type;
  unsigned char count;
  unsigned short rank;
  unsigned int number;
  void *shape;
} Array;
```

- **T**ype: The type of the array (v.s.)
- reference **C**ount: Garbage Collection
- atoms: The **N**umber of atoms in the Object
- **R**ank:
  - 0: one value
  - 1: 1D array
  - 2: 2D array
  - _n_: nth D array
- **S**hape: The pointer to the data (n+r)
  - rank 0: pointer to the one value
  - rank 1: pointer to the size of the array, folloed by the data
  - rank 2: pointer to the column size, followed after the row size and then the data
  - rank _n_: pointer to nth dimensions, followed by the data

**Shape Examples:**

The 1D number `1.3` has the shape of:

```
pos:      0
shape: [1.3]
```

_visualised:_

```
+---+
|1.3|
+---+
```

The 2D array of the numbers `1`, `2` and `3` has the shape of:

```
pos:    0 1 2 3 4
shape: [1 3 1 2 3]
```

_visualised:_

```
+-----+
|1 2 3|
+-----+
```

### Functions

```c
// Initialising an Array
void initArray(Array *array);
// Freeing an Array
void freeArray(Array *array);
// Writing an Array, with a *type*, *number*, *rank* and the *shape*
void writeArray(Array *array, unsigned char type, unsigned int number,
                unsigned char rank, void *shape);
// Copying the Array *from* into the Array *to*
void copyArray(Array *from, Array *to);
// Copying the Data of an Array *from* into the Array *to* with an *offset*
void copyArrayData(Array *from, Array to, unsigned int offset)
// Incrementing the Reference Count of an Array
void incArray(Array *array);
// Decrementing the Reference Count of an Array
void decArray(Array *array);
// Printing the Array
void printArray(Array *array);
// Getting the size of the Array
unsigned int ArraySize(Array *array);
// Getting the dimensions of the Array
unsigned short ArrayDimensions(Array *array);
// Getting the type of the Array
unsigned short ArrayType(Array *array);
```

### Optimisation

- Loop Unrolling
- top-down while (for 10 loops something like: `int i=10;while(i!=0){i--;}`)
- Using realloc as much as possible
- Search for the _best_ algorithm to use
- Size Optimization:
  - playing with the order of the fields
  - check out the difference between 32 bit and 64 bit OS, etc.

## Compiler

[c.h](../../src/c.h)

- _rigorous_ type-checking
- throwing errors as fast and early as possible

## Virtual Machine

[v.h](../../src/v.h)

### Opcodes

```
...
```

### Optimisation

- Instead of using `switch` use a `table`([ref](https://www.jmeiners.com/lc3-vm/#:op-table))
- Using an Register VM instead of Stack VM (currently planned Stack VM)
- Use multiple different opcodes for `integers` and `floats`
  - when in an example an integer and an float are present -> cast integer into float

## Further Ideas and Research:

- Don't use intrinsic functions for portability
- Read up on how to used Reference Counting: [ref](https://verdagon.dev/grimoire/grimoire)
- Performance:
  - [lobster performance tag](https://lobste.rs/t/performance)
  - [MIT 6.172 Performance Engineering](https://youtube.com/playlist?list=PLUl4u3cNGP63VIBQVWguXxZZi0566y7Wf&si=Hq9P8cj6_2mqzfC_)
  - looking also at hardware restrictions [ref](https://www.youtube.com/watch?v=Ca1hHC2EctY)
- size optimisations:
  - look at allignment of structs(because padding), [ref](https://youtu.be/443UNeGrFoM?si=_HtXiK-7jGv6LeoB&t=4596)
