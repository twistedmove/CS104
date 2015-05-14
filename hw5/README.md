# Implement Merge Sort

msort.h contains the implementation of the templated merge sort function. The program mergeTest.cpp in the tests directory evaluates the functionality of the algorithm.

>Compile with: g++ -g -Wall tests/mergeTest.cpp -o mergeTest   
Run with: ./mergeTest

# Qt FrontEnd

**IMPORTANT:** do not compile the main Amazon GUI with qmake -project, qmake, make   
A properly modified .pro file has been provided, so only run qmake and make.

If you do run qmake -project, be sure to delete the word "tests" on the line "DEPENDPATH += . tests" and the entire line "tests/mergeTest.cpp" under the SOURCES section.

>Compile with: qmake   
				make   
Run with: ./hw5 \<database input file\>

In the tests directory database.txt is the provided sample database, and largeDatabase.txt is a bigger database for testing purposes that does not contain any reviews.