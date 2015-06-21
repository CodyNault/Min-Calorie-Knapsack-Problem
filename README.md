Minimum-Calorie Knapsack Problem
-------------------
Author: Cody Nault
Date: 5/29/2015
This is a C++ implementation of a classic Knapsack problem with a restaurant twist. 
The goal here is to take in a list of food items, with their corresponding cost and calorie count, 
and find the minimum number of calories that we can but with exactly X amount of money.
This program demonstrates both memoized and iterative dynamic programming techniques of finding a 
solution efficiently. It then displays a solution that will lead to the optimal result.

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
