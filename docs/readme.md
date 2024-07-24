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
- accept utf-8 (C11, selfbuild wrapper or Unicode parser; note: seems to be somehow very hard on windows...)
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
- have fun!

## syntax:

### basic operators:

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

### function/type declaration

```
    a <- 1 + 2
    a <- x + y
```

## references:

- https://github.com/kevinlawler/kona/wiki
- https://code.jsoftware.com/wiki/NuVoc
- https://www.uiua.org
- https://github.com/cratelyn/j
