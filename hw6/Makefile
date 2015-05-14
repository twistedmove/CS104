CXX = g++
CFLAGS = -g -Wall
BIN_DIR = bin
GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread

all: test puzzle 

test: $(BIN_DIR)/heapTest

puzzle: $(BIN_DIR)/puzzle
	

$(BIN_DIR)/heapTest: heapTest.cpp heap.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) $< $(GTEST_LL) -o $@

$(BIN_DIR)/puzzle: $(BIN_DIR)/board.o $(BIN_DIR)/puzzle.o $(BIN_DIR)/puzzle_heur.o $(BIN_DIR)/puzzle_move.o $(BIN_DIR)/puzzle_solver.o
	$(CXX) $(CFLAGS) $^ -o $@

$(BIN_DIR)/board.o: board.cpp board.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/puzzle.o: puzzle.cpp board.h puzzle_heur.h puzzle_solver.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/puzzle_heur.o: puzzle_heur.cpp puzzle_heur.h board.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/puzzle_move.o: puzzle_move.cpp puzzle_move.h board.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/puzzle_solver.o: puzzle_solver.cpp puzzle_solver.h board.h puzzle_move.h puzzle_heur.h heap.h $(BIN_DIR)/.dirstamp
	$(CXX) $(CFLAGS) -c $< -o $@


$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $@


.PHONY: clean

clean:
	rm -rf $(BIN_DIR)