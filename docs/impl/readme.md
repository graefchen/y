# implementation

**Note:** For reading purposes have the types and names been adapted to be
better understandable.

## Internal Data Type's

- 0: Character/Rune (String is 1 Dimensional Array)
- 1: Integer (32 or 64 bits)
- 2: Float (64 bits)
- 3: Boolean (0 or 1 integer value)
- 4: Box (Pointer to other Data Types)

## Array's

[t.h](../../src/t.h)

## definition

Similar to the [kona](https://github.com/kevinlawler/kona/wiki/C-Reference#k-object)
and [J](https://www.jsoftware.com/ioj/iojNoun.htm#Arrays) array types.

The array is in row major order (first row then column).

```c
typedef struct array{long long t,c,n,r,s[1];} *Array;
```

- **T**ype: The type of the array (v.s.)
- reference **C**ount: Garbage Collection
- atoms: The **N**umber of atoms in the Object
- **R**ank:
  - 0: one value
  - 1: 1D array
  - 2: 2D array
  - n: nD array
- **S**hape: The pointer to the data
  - rank 0: pointer to the one value
  - rank 1: pointer to the size of the array, following by the data
  - rank 2: pointer to the row size, following after the column size and then the data
  - rank n: pointer to nth dimensions, following by teh data

## functions:

```c
void initA(Array a, long long t, long long n, long long r, long long*s);
void freeA(Array a);
```
