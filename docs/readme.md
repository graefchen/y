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
- using (for now) only ascii chars (as they are on every\* keyboard and make things easier without installing additional tooling)
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

Interface over ~~subcommands or~~ flags

Because it want to be so small and fast ... primarely some functions over flags.

Starting the repl:

**note: the prompt for y are 6 empty spaces**

```sh
$ y    :h for help. Ctrl+C for exit.
y
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

Printing the help message:

```sh
$ y -h
A tiny array programming language
Usage: y [options] [script]
Aviable options are:
  -h       print help message
  -v       print version
  -i       enter interactive shell after executing 'script'
  -e stat  execute string 'stat'
  -x stat  execute and print string 'stat'
$ ...
```

Printing the version message:

```sh
$ y -v
y 0.0.1 -- Copyright (C) @graefchen
$ ...
```

Entering interactive shell after running script:

```sh
$ y -i rl.y
1 0 0
0 1 0
0 0 1
      10
$ ...
```

Executing an string input:

```sh
$ y -e 10*10*10
$ ...
```

Executing and printing an string input:

```sh
$ y -x 10*10*10
1000
$ ...
```

### language

**rules:**

- evaluation from right to left (except a different precedence is given)
- all primatives can be used in at least two forms
  - monadic (1 argument)
  - dyadic (2 arguments)
- expressions are executed
- definitions are remembered
- arrays are 1 indexed

#### primitives

| Verb | Monadic       | Dyadic                |
| ---- | ------------- | --------------------- |
| +    | conjugate     | addition              |
| \-   | negate        | subtraction           |
| \*   | signum        | muliplication         |
| %    | reciprocal    | division              |
| $    | shape         | reshape               |
| !    | iota          | residue(modolu)       |
| ^    | exponent of e | power                 |
| =    | depth         | equal                 |
| ==   |               | match                 |
| <    | grade up      | less than             |
| <=   |               | less than or equal    |
| >=   |               | greater than or equal |
| >    | grade down    | greater than          |
| ~    | not           | match                 |
| \|   | magnitude     | min                   |
| &    | index of      | max                   |
| \|\| |               | or                    |
| &&   |               | and                   |

| Adverb | Monadic | Dyadic |
| ------ | ------- | ------ |
| /      | reduce  |        |
| \\     | scan    |        |

| Miscellanious | Definition |
| ------------- | ---------- |
| NB.           | comment    |
| <-            | assign     |

| Command | Definition                       |
| ------- | -------------------------------- |
| :h      | prints a very small help command |
| :p      | pretty printing                  |

#### values

```
      1 NB. number
1
      8000 NB. number
8000
      1.2 NB. floating point number
1.2
      -1 NB. negative number
_1
      "I" NB. character/rune
"I"
```

#### vectors

```
      1 2 3 NB. numbers
1 2 3
      1.2 -1.3 -1.4 NB. floating point numbers
 1.2 _1.3 _1.4
      "Hello World" NB. string
"Hello World"
```

#### matrices

```
      3 3 $ ! 9 NB. Usage of reshape and iota
1 2 3
4 5 6
7 8 9
      3 3 $ 3 % ! 9
```

#### comments

```
      NB. This is a comment
      NB. There are only one line comments
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
      d <- 2 3 $ c NB. using reshape
      d
1 2 3
4 5 6
```

#### indexing

```
      a[2]
| undefined-variable error
| *description*
      a <- ! 3
      a
1 2 3
      a[3]
3
      a[1;2]
| length error
| *description*
      m <- 3 3 $ ! 9
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
      m[3]
| length error
| *description*
```

#### addition/subtraction/multiplication/division

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
|zero-division error
      0 % 2
|zero-division error
      2 % 3
0.6666666667
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
|length error
|*description*
      2 4 8 16 % 2
1 2 4 8
      2 4 8 16 % 2 4 8 16
1 1 1 1
      (2 2 $ 1 1 1 1) + 2 2 $ 1 1 1 1
2 2
2 2
      (2 2 $ 1) - 2 2 $ 1
0 0
0 0
      (2 2 $ 1) * 2
2 2
2 2
      (2 2 $ 1) % 2
0.5 0.5
0.5 0.5
```

#### dimension/reshape

```
      $ 1 2 3
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
      2 3 $ 1 2
1 2 1
2 1 2
      3 2 $ 1 2
1 2
1 2
1 2
```

#### range

```
      ! 3
1 2 3
      ! 1 3
1 2 3
      ! 2 3
1 2 3
4 5 6
      ! 3 3
1 2 3
4 5 6
7 8 9
      ! 2 2 2
1 2
3 4

5 6
7 8
      ! 3 6
 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15
```

#### reduce/scan

```
      a <- 1 1 1 1 1
      + / a
5
      + \ a
1 2 3 4 5
      - / a
-3
      - \ a
1 0 -1 -2 -3
      * / a
1
      * \ a
1 1 1 1 1
      % / a
1
      % \ a
1 1 1 1 1
```

## references:

- [APL demonstration 1975 (Imperial College London)](https://youtu.be/_DTpQ4Kk2wA?si=FgDMA80LUncFFsEF)
- [APL syntax](https://en.wikipedia.org/wiki/APL_syntax_and_symbols#Syntax_rules)
- [kona wiki](https://github.com/kevinlawler/kona/wiki)
- [Minimal J](https://code.jsoftware.com/wiki/User:Devon_McCormick/MinimalBeginningJ)
- [J Nuvoc](https://code.jsoftware.com/wiki/NuVoc)
- [J-Playground](https://jsoftware.github.io/j-playground/bin/html2/)
- [Uiua-Playground](https://www.uiua.org)
- [oK-Playground](https://johnearnest.github.io/ok/index.html)
- [BQN-Playground](https://mlochbaum.github.io/BQN/)
- [j](https://github.com/cratelyn/j)
