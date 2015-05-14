# Makefile Options

**make**: defaults to make test and make puzzle   
**make test**: creates heapTest executable in bin directory   
**make puzzle**: creates puzzle executable and object files board.o, puzzle_heur.o, puzzle_move.o, puzzle.o, and puzzle_solver.o in bin directory   
**make clean**: removes bin directory

# Problem 2 Max Heaps

prob2Ans.txt contains the answers to problem 2's questions about heaps. The tree representations of the heaps are done with ASCII art.

# Problem 3 m-ary Heaps

heap.h contains the completed code for the Heap class template, and heapTest.cpp contains the Google Test program verifying its correctness.

>Compile with: make or make test   
Run with: ./bin/heapTest

# Problem 4 A* Puzzle Solver

Note that the operator<(const Board& rhs) function does not contain error checking if the boards are of different sizes.

>Compile with: make or make puzzle   
Run with: ./bin/puzzle \<size\> \<init moves\> \<seed\> \<heur\>

# Problem 5 Runtime Comparisons

The table of expansion counts is in the file perf.txt