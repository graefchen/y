# implementation

**Note:** For reading purposes have the types and names been adapted to be
better understandable.

## Internal Data Type's

- 0: Character/Rune (String is 1 Dimensional Array)
- 1: Integer (32 or 64 bits) / Boolean (0 or 1 integer)
- 2: Float (64 bits)
- 3: Box (Pointer to other Data Types)

## Array's

[t.h](../../src/t.h)

## Definition

Similar to the [kona](https://github.com/kevinlawler/kona/wiki/C-Reference#k-object)
and [J](https://www.jsoftware.com/ioj/iojNoun.htm#Arrays) array types.

The array is in row major order (first row then column).

Currently the following data type adds up to 16 bytes ... from 40 when using
long long for all values.

```c
typedef struct array {
  unsigned char t;
  unsigned char c;
  unsigned short r;
  unsigned int n;
  long long s[1];
} *Array;
```

- **T**ype: The type of the array (v.s.)
- reference **C**ount: Garbage Collection
- atoms: The **N**umber of atoms in the Object
- **R**ank:
  - 0: one value
  - 1: 1D array
  - 2: 2D array
  - _n_: nth D array
- **S**hape: The pointer to the data
  - rank 0: pointer to the one value
  - rank 1: pointer to the size of the array, following by the data
  - rank 2: pointer to the row size, following after the column size and then the data
  - rank _n_: pointer to nth dimensions, following by the data

## Functions

```c
void initArray(Array array);
void freeArray(Array array);
void writeArray(Array array,unsigned char type, unsigned int number,
                unsigned char rank, unsigned long long*shape);
```

### Optimisation

- Loop Unrolling
- Using realloc as much as possible
- Search for the _best_ algorithm to use
- Size Optimization:
  - setting

## Compiler

- _rigorous_ type-checking
- throwing errors as fast and early as possible

## Virtual Machine

### Opcodes

```
...
```

### Optimisation

- Instead of using `switch` use a `table`([ref](https://www.jmeiners.com/lc3-vm/#:op-table))
- Using an Register VM instead of Stack VM
- Use multiple different opcodes for `integers`, `floats` and `mixed`

## Further Ideas and Research:

- Don't use intrinsic functions for portability
- Read up on how to used Reference Counting: [ref](https://verdagon.dev/grimoire/grimoire)
- Performance:
  - [lobster performance tag](https://lobste.rs/t/performance)
  - [MIT 6.172 Performance Engineering](https://youtube.com/playlist?list=PLUl4u3cNGP63VIBQVWguXxZZi0566y7Wf&si=Hq9P8cj6_2mqzfC_)
- size optimisations:
  - look at allignment of structs(because padding), [ref](https://youtu.be/443UNeGrFoM?si=_HtXiK-7jGv6LeoB&t=4596)
