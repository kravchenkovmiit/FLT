# Fillit @ SBER school 21 (42)

**Algorithms Practice - Fit tetris pieces into the smallest square possible.**

[Program Specs](https://github.com/kravchenkovmiit/flt/blob/master/fillit.en.pdf)

[School Code Formatting Standards - The Norm](https://github.com/kravchenkovmiit/flt/blob/master/Norm.pdf)

## Compiling
`make fillit`

## Usage
`./fillit [file]`

### What Fillit Does
Fillit recieves a map text file like this one with pieces.

![Valid Map](https://github.com/kravchenkovmiit/flt/blob/master/assets/example_map.png)

It finds the smallest possible square the pieces can be arranged in and prints out the square:

```
~ ./fillit samples/test_3
ABBBB
ACCC.
A..C.
ADD..
DD...
```
