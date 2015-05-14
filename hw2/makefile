CC = g++
CFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/postfix

$(BIN_DIR)/postfix: postfix.cpp $(BIN_DIR)/.dirstamp $(BIN_DIR)/stackdbl.o $(BIN_DIR)/llistdbl.o
	$(CC) $(CFLAGS) $(BIN_DIR)/stackdbl.o $(BIN_DIR)/llistdbl.o $< -o $@

$(BIN_DIR)/stackdbl.o: stackdbl.cpp stackdbl.h $(BIN_DIR)/.dirstamp
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/llistdbl.o: llistdbl.cpp llistdbl.h $(BIN_DIR)/.dirstamp
	$(CC) $(CFLAGS) -c $< -o $@



tests: $(BIN_DIR)/aListTest $(BIN_DIR)/inOutLlistTest $(BIN_DIR)/addToEmptyTest

$(BIN_DIR)/aListTest: tests/aListTest.cpp $(BIN_DIR)/.dirstamp $(BIN_DIR)/alistint.o
	$(CC) $(CFLAGS) $(BIN_DIR)/alistint.o $< -o $@

$(BIN_DIR)/inOutLlistTest: tests/inOutLlistDblTest.cpp $(BIN_DIR)/.dirstamp $(BIN_DIR)/llistdbl.o
	$(CC) $(CFLAGS) $(BIN_DIR)/llistdbl.o $< -o $@

$(BIN_DIR)/addToEmptyTest: tests/testAddToEmptyList.cpp $(BIN_DIR)/.dirstamp $(BIN_DIR)/llistdbl.o
	$(CC) $(CFLAGS) $(BIN_DIR)/llistdbl.o $< -o $@

$(BIN_DIR)/alistint.o: alistint.cpp alistint.h $(BIN_DIR)/.dirstamp
	$(CC) $(CFLAGS) -c $< -o $@



$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)