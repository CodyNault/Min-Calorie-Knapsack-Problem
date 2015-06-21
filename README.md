Author: Cody Nault
Date: 5/29/2015
Class: CIS 315
Instructor: Chris Wilson, Ph.D
Assignment: Assignment 6 (Programming)

Installation
-------------------
To Install the application simple run make from the current project directory.
make compiles files to the bin directory

Running
-------------------
To run simply call ./chipotle from the project directory.
Graph data input files are supplied in the application using standard input.

Additional Notes
-------------------
My code exists in 2 different files
src/chipotle.C
include/chipotle.h
Both are required for successful compilation

Results
-------------------
The following commands where run from the root directory 
and produced these results which match the expected output.

$ ./chipotle < bin/inSample2.txt
Iterative:
Not possible to spend exactly: 950

Memoized:
Not possible to spend exactly: 950



$./chipotle < bin/inSample3.txt
Iterative:
Possible to spend exactly: 1000000
Minimum calories: 725166
B 2
C 3620
D 2

Memoized:
Possible to spend exactly: 1000000
Minimum calories: 725166
B 2
C 3620
D 2



$./chipotle < bin/inSample4.txt
Iterative:
Possible to spend exactly: 1978624
Minimum calories: 1758977
C 1
D 1
H 1
K 4394

Memoized:
Possible to spend exactly: 1978624
Minimum calories: 1758977
C 1
D 1
H 1
K 4394
