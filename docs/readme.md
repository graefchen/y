# y - language definition

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
- using (for now) only ascii chars (as they are on every\* keyboard and make things easier without isntalling additional tooling)
- optional goals (sorted base on how likely I am at implementing them):
  1. make it similar to lua that other people can implement it in their c programs
  2. accept utf-8 (C11, selfbuild wrapper or Unicode parser; note: seems to be somehow very hard on windows...)
  3. emojis as variables allowed
  4. preprocessor step so that `over` or `über` produce a _glyphe_ (similar to UIUA)(?)

\* at least every programmers keyboard

## goals for me

- get better at C
- get to know the ATW-style of writing programs
- writing another VM, with an compiler
- learning more about array programming languages
- learning more about functional programming languages
- have fun!

## design

### command line

Interface over `subcommands` or `flags`?

Because it want to be so small and fast ... primarely some functions over flags,
**for now currently `none`**

Starting the repl:

```sh
$ y
y repl
      1 + 2
3
$ ...
```

Running a file:

```sh
$ y rl.y
1 0 0
0 1 0
0 0 1
$ ...
```

### language

**rules:**

- evaluation from right to left (except a different precedence is given)
- all primatives can be used in two forms
  - monadic (1 argument)
  - dyadic (2 arguments)
- expressions are executed
- definitions are remembered
- arrays are 1 indexed

#### primatives/operators

primatives/operators should all be postfix when given one value and infix when
given two values.

| Verb | Monadic    | Dyadic        |
| ---- | ---------- | ------------- |
| +    |            | addition      |
| \-   |            | subtraction   |
| \*   |            | muliplication |
| %    |            | division      |
| $    | dimensions | reshape       |
| /    |            | reduce        |
| \\   |            | scan          |

##### addition/subtraction/multiplication/division

With _number_:

```
      1 + 2
3
      2 - 1
1
      1 * 2
2
      2 % 1
2
      2 % 0
| zero-division error
      0 % 2
| zero-division error
      2 % 3
0.6666666667
```

With _vectors_:

```
      1 2 + 2
3 4
      1 2 + 2 1
3 3
      2 2 2 - 1 1 1
1 1 1
      1 1 * 2
2 2
      2 * 1 1
2 2
      1 1 2 2 * 2 1 1
| length error
| *description*
      2 4 8 16 % 2
1 2 4 8
      2 4 8 16 % 2 4 8 16
1 1 1 1
```

<!--
TODO: Add matrice documentation
With _matrices_:

```

```
-->

##### dimension/reshape

```
      $1 2 3
3
      1 2 $ 2
2 2
      2 1 $ 2
2
2
      2 2 $ 1
1 1
1 1
      3 3 $ 1
1 1 1
1 1 1
1 1 1
      3 3 $ 1 2
1 2 1
2 1 2
1 2 1
```

##### reduce/scan

```
      a <- 1 1 1 1 1
      +/a
5
      +\a
1 3 6 10 15
      -/a
-13
      -\a
1 -1 -4 -8 -13
      */a
120
      *\a
1 2 6 24 120
      %/a
0.0083
      %\a
1 0.5 0.1667 0.0417 0.0083
```

#### type declaration

```
      a <- 1 + 2
      a
3
      b <- x + 1
| undefined-variable error
| *description*
      c <- 1 2 3 4 5 6
      c
1 2 3 4 5 6
      d <- 2 3 $ 1 2 3 4 5 6
      d
1 2 3
4 5 6
```

##### indexing

```
      m <- 3 3 $ 1 2 3 4 5 6 7 8 9
      m
1 2 3
4 5 6
7 8 9
      m[1;1]
1
      m[2;]
4 5 6
      m[;3]
3 6 9
```

#### functions:

functions should all be postfix.

| Name        | Symbol | Monadic | Dyadic | ... |
| ----------- | ------ | ------- | ------ | --- |
| iota(range) | !      | vector  | matrix |     |

#### commands:

| Command | Definition                       |
| ------- | -------------------------------- |
| :help   | prints a very small help command |

## references:

- [APL demonstration 1975 (Imperial College London)](https://youtu.be/_DTpQ4Kk2wA?si=FgDMA80LUncFFsEF)
- [kona wiki](https://github.com/kevinlawler/kona/wiki)
- [Minimal J](https://code.jsoftware.com/wiki/User:Devon_McCormick/MinimalBeginningJ)
- [J Nuvoc](https://code.jsoftware.com/wiki/NuVoc)
- [J-Playground](https://jsoftware.github.io/j-playground/bin/html2/)
- [Uiua-Playground](https://www.uiua.org)
- [oK-Playground](https://johnearnest.github.io/ok/index.html)
- [BQN-Playground](https://mlochbaum.github.io/BQN/)
- [j](https://github.com/cratelyn/j)
