Makefile options:
	make: creates object files stackdbl.o and llistdbl.o and executable postfix in the bin directory
	make tests: creates object files alistint.o and llistdbl.o and executables aListTest, inOutLlistTest, addToEmptyTest in the bin directory
	make clean: removes bin directory

The answers for problem 1 and 6 are in the file hw2.txt.

For problem 3 the llistdbl.o object file will be created by calling either "make" or "make tests". In the directory tests, testAddToEmptyList.cpp is the provided test file and inOutLlistDblTest.cpp is the test file I created. They can be run with "./bin/addToEmptyTest" and "./bin/inOutLlistTest", respectively.

For problem 4 the alistint.o object file will be created by calling "make tests". Note that there will be a compiler warning for referencing a local variable, which was the only way to deal with calling the get function on an invalid index. This also sends a warning to the cerr stream, which also happens when the constructor defaults to size 10 if the user requests an array size less than 1. The test file for the AListInt class is in the directory tests and is called aListTest.cpp. It can be run with "./bin/aListTest".

For problem 5 the stackdbl.o object file will be created by calling "make". Note that there will be a compiler warning for referencing a local variable, which was the only way to deal with calling the top function on an empty stack. This also sends a warning to the cerr stream.

Postfix.cpp is the completed calculator program specified in problem 7. Note that it assumes that there are no invalid characters or spacing errors in the input. It also assumes that having more than one character remaining after all operations are performed is invalid.
Run with: ./postfix <input file> <output file>
Postfix.in is the provided sample input.