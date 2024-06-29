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

### basic arithmetic:

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

### working with arrays:

```
    !10
0 1 2 3 4 5 6 7 8 9
    + !10
9 8 7 6 5 4 3 2 1 0
    - !10
-0 -1 -2 -3 -4 -5 -6 -7 -8 -9
```

### working with strings:

```
    'Hello, World!'
Hello, World!
```

### verbs:

| Verb | Monadic | Dyadic | ... |
| ---- | ------- | ------ | --- |
| +    | flip    | plus   |     |
| -    | negate  | minus  |     |

### commands:

| Command | Definition                              |
| ------- | --------------------------------------- |
| \       | prints a very small help command        |
| \t      | prints a table of all current variables |

## references:

- https://github.com/kevinlawler/kona/wiki
- https://code.jsoftware.com/wiki/NuVoc
- https://www.uiua.org
