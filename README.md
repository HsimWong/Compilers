# Compilers
This repo is for designing project of compilers instructed by Mr. Xudong Xu, Professor of Beijing University of Technology.

## Mission Description
1. Design and implementation of lexical analysis
2. Design and implementation of compiler parsing
3. Syntax-driven three-address code generator

## Module Discription

### Lexical Analysis
The lexical part takes in a string and return respective value which indicates the tag of words. ```scan()``` is function absorbs a word and called over and over again.
return value---tag
16---HEX
10---Dec
8---OCT
7---TAG
6---Token'_'
0---error

