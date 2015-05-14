CXX=g++
CXXFLAGS=-g -Wall 
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=bin/amazon.o bin/actual_datastore.o bin/user.o bin/db_parser.o bin/product.o bin/book.o bin/clothing.o bin/movie.o bin/product_parser.o bin/util.o

all: amazon

amazon: $(OBJS) bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o bin/$@ $(OBJS)

bin/amazon.o: amazon.cpp db_parser.h datastore.h product_parser.h util.h actual_datastore.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c amazon.cpp
bin/actual_datastore.o: actual_datastore.cpp actual_datastore.h datastore.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c actual_datastore.cpp
bin/user.o: user.cpp user.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c user.cpp
bin/db_parser.o: db_parser.cpp db_parser.h product.h product_parser.h user.h datastore.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c db_parser.cpp
bin/product.o: product.cpp product.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product.cpp
bin/book.o: book.cpp book.h product.h util.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c book.cpp
bin/clothing.o: clothing.cpp clothing.h product.h util.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c clothing.cpp
bin/movie.o: movie.cpp movie.h product.h util.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c movie.cpp
bin/product_parser.o: product_parser.cpp product_parser.h product.h book.h movie.h clothing.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product_parser.cpp
bin/util.o: util.cpp util.h bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c util.cpp

bin/.dirstamp:
	mkdir -p bin
	touch $@


clean:
	rm -rf bin
