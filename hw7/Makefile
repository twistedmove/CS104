CXX = g++
CFLAGS = -g -Wall
BIN_DIR = bin

all: tests rectangles 

tests: inTreeTest itTreeTest

itTreeTest: $(BIN_DIR)/itTreeTest

inTreeTest: $(BIN_DIR)/inTreeTest

rectangles: $(BIN_DIR)/rectangles


$(BIN_DIR)/itTreeTest: iteratorTreeTest.cpp bst.h rbbst.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) $< -o $@

$(BIN_DIR)/inTreeTest: insertTreeTest.cpp bst.h rbbst.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) $< -o $@

$(BIN_DIR)/rectangles: rectangle.cpp bst.h rbbst.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) $< -o $@


$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $@


.PHONY: clean

clean:
	rm -rf $(BIN_DIR)