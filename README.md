# CLogic, CO120.3 C Project Extension

This is as part of _Imperial College London's CO120.3C Programming (C) Extension_ course, a project
 extension collaboratively implemented by Chloe Lau, Karan Obhrai, Leo Unoki and Oliver Federico, for Group 13, Academic Year 2019/20, First Year Computing.

### Introduction

As part of our _CO112 Introduction to Computer Systems_ course, we have built strong logic
 and circuit knowledge with a variety of software. In order to enhance the learning experience
 , we have decided to build an extension to our C Project by building a logic gate/combinatorial
  circuit design emulator, `CLogic`, with easy instructions for students to use within
  , and beyond the course.

The `CLogic` program would take in instructions to build a logic gate circuit through a parser
, then the function would find the value of each output by a recursive trees approach. The
 program would allow easier control of multiple `(n >= 2)` inputs being processed to one
  operation, with an efficient handling method and possibly faster for theoretical circuits designs.

### CLogic Input Rules
Each line of text can take two forms (--> excluded):

- `<NAME> INPUT`

- `<NAME> OUTPUT? <FUNCTION> <INPUTS...>`

`?` wildcard indicates optional.


### Gates Rules:

- OR (Minimum 2 inputs)

- AND (Minimum 2 inputs)

- NOT (1 Input)

- XOR (Minimum 2 inputs)

- XAND (Minimum 2 inputs)

- NOR (Minimum 2 inputs)

- NAND (Minimum 2 inputs)

### Approach
We have taken a _trie_ approach instead of a graph approach
- Loops will throw an error! Something cannot directly or indirectly take it's own output as it's
 own input.
- This will be done because a gate can only take inputs previously referenced in the code
 (including it's unable to take itself).

### CLogic Input Rules
To run the test suite, run the './extension_tests/testsuite_runner.sh' shell script from a UNIX based OS machine.
The last line will say "All tests passed" if the test suite passed all tests.
 
### Example
Input
```
A INPUT
B INPUT
C OUTPUT OR A B
```
Output
```
<-START->
Input Gate: A Value: 0
Input Gate: B Value: 0
Output Gate: C Value: 0
<- END ->

<-START->
Input Gate: A Value: 1
Input Gate: B Value: 0
Output Gate: C Value: 1
<- END ->

<-START->
Input Gate: A Value: 0
Input Gate: B Value: 1
Output Gate: C Value: 1
<- END ->

<-START->
Input Gate: A Value: 1
Input Gate: B Value: 1
Output Gate: C Value: 1
<- END ->
``` 

### Testing

Testing would run two tests from the subdirectory `extension_tests`, just run the file
 `testsuite_runner.sh` and it will run all the tests on terminal with the shell command, first to
  run the execute tests, then the comparison of a recursive usage with a manually coded expected output.
