# y

The idea behind y is to create an toy array programminh language and then extend it into a _real_ programming language.

## base ideas

- like APl, J, K, BQN, UIUA
- able to write terse code
- small footprint
- only _one_ data type
- pointless
- unmutable

## goals

- cross compilable (Win/Linux/Mac)
- using bytecode vm
- dominantly made as an interactive programming environment
- accept utf-8
- emojis as variables allowed
- preprocessor step so that `over` or `über` produce a _glyphe_ (similar to UIUA)(?)
- using only ascii chars (as they are on every\* keyboard and make things easier without isntalling additional tooling)
- make it similar to lua that other people can implement it in their c programs

\* at least every programmers keyboard

## goals for me

- get better at c
- get to know the ATW-style of writing programs
- writing another vm, with an compiler
- learning more about array programming languages
- learning more about functional programming languages
- have fun

## language:

### only datataype:

Similar to the [kona](https://github.com/kevinlawler/kona/wiki/C-Reference#k-object)
and [J](https://www.jsoftware.com/ioj/iojNoun.htm#Arrays) array types.

The array is in row major order (first row then column).

```
typedef {long t,c,n,r,s[1];} *A;
t: type             => The type of the array(see below)
c: reference count  => Garbage Collection
n: atoms            => The number of atoms in the Object
r: rank             => 0: one value; 1: 1D array; 2: 2D array
s: shape            => The pointer to the data
                    rank:
                    0 -> pointer to the one value
                    1 -> pointer to the size of the array, following by the data
                    2 -> pointer to the row size, following after the column size and then the data
```

### types:

```
0 => Character/Rune (String is 1 Dimensional Array)
1 => Integer (32 bits)
2 => Float (64 bits)
3 => Boolean
```

### basic arithmetic:

Using integer:

```
    1 + 2
3
    2 - 1
1
    1 * 2
2
    2 / 1
2
```

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

## references:

- https://github.com/kevinlawler/kona/wiki
- https://code.jsoftware.com/wiki/NuVoc
- https://www.uiua.org
- https://github.com/cratelyn/j
