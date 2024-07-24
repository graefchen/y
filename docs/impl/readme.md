# implementation

## Array's

[t.h](../../src/t.h)

Similar to the [kona](https://github.com/kevinlawler/kona/wiki/C-Reference#k-object)
and [J](https://www.jsoftware.com/ioj/iojNoun.htm#Arrays) array types.

The array is in row major order (first row then column).

```c
typedef struct {int t,c,n,r,s[1];} Array;
```

- **t**ype: The type of the array
  - 0: Character/Rune (String is 1 Dimensional Array)
  - 1: Integer (32 or 64 bits)
  - 2: Float (64 bits)
  - 3: Boolean (0 or 1 integer value)
- reference **c**ount: Garbage Collection
- atoms: The **n**umber of atoms in the Object
- **r**ank:
  - 0: one value
  - 1: 1D array
  - 2: 2D array
- **s**hape: The pointer to the data
  - rank 0: pointer to the one value
  - rank 1: pointer to the size of the array, following by the data
  - rank 2: pointer to the row size, following after the column size and then the data

<!--
### verbs:

| Verb | Monadic | Dyadic  | ... |
| ---- | ------- | ------- | --- |
| +    |         | plus    |     |
| -    |         | minus   |     |
| \*   |         | muliply |     |
| /    |         | divide  |     |

### commands:

| Command | Definition                              |
| ------- | --------------------------------------- |
| \       | prints a very small help command        |
| \t      | prints a table of all current variables |
-->
