# Makefile Options

**make**: defaults to make tests and make rectangles   
**make tests**: defaults to make inTreeTest and make itTreeTest   
**make rectangles**: creates rectangles executable in bin directory   
**make inTreeTest**: creates inTreeTest executable in bin directory   
**make itTreeTest**: creates itTreeTest executable in bin directory   
**make clean**: removes bin directory

# Problem 2 Class Structures and Inheritance

hw7_p2.pdf contains the answers to problem 2's questions about diagramming classes. The relationship diagrams are done with a combination of graphics and UML.

# Problem 3 Red-Black Trees

hw7_p3.pdf contains the answers to problem 3's questions about inserting in a Red-Black Tree. The intermediate steps of the insertions are not shown for the sake of convenience.

# Problem 4 Binary Search Tree Iterators

bst.h contains the completed code for the Binary Search Tree iterator template, and iteratorTreeTest.cpp contains the program verifying its correctness. The output of the test must be verified manually.   
Note that this code relies upon the insert function in problem 5 working correctly. Note also that attempting to dereference an iterator past the end results in undefined behavior.

>Compile with: make or make tests or make itTreeTest   
Run with: ./bin/itTreeTest

# Problem 5 Red-Black Tree Insertion

rbbst.h contains the completed code for the Red-Black Tree insert template, and insertTreeTest.cpp contains the program verifying its correctness. The output of the test must be verified manually.

>Compile with: make or make tests or make inTreeTest   
Run with: ./bin/inTreeTest

# Problem 6 Backtracking

rectangle.cpp contains the completed main program that attempts to tile a rectangular surface. Note that it assumes that input files will be in the proper format.

>Compile with: make or make rectangles   
Run with: ./bin/rectangles \<input file\> \<output file\>

sampleIn.txt, sampleIn2.txt, and sampleIn3.txt are the sample inputs shown on the course website.