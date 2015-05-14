Makefile options:
	make: defaults to make pgindex
	make pgindex: creates object files llistint.o and setint.o and executable pgindex in the bin directory
	make copytest: creates object file llistint.o and executable copytest in the bin directory
	make settest: creates object files llistint.o and setint.o and executable settest in the bin directory
	make clean: removes the bin directory

The test program for problem 2 is testLlistInt.cpp in the tests directory. It mainly examines the copy constructor, assignment, and push-back functions, although it relies on old functions like size and empty to do so. Note that the tester is expected to read the output himself and determine any non-fatal errors. The test executable copytest can be created by calling "make copytest" and run with "./bin/copytest".

The test program for problem 3 is testSetInt.cpp in the tests directory. It examines every single function in the SetInt class. Note that the tester is expected to read the output himself and determine any non-fatal errors. The test executable settest can be created by calling "make settest" and run with "./bin/settest".

Pgindex.cpp is the completed word indexing program specified in problem 4. Note that it can be run without any words to search for as command line arguments, but doing so will produce no output. Also note that the only parsing applied to the words to search for is making them all lowercase.
Run with: ./bin/pgindex <input file> <output file> <any number of search words>
In the tests directory, pages.txt is the provided sample input and wordSoup.txt is input I used to test my string parsing functions. WordSoup.txt contains no <pagebreak> and is less useful for final testing.