CC = g++
CFLAGS = -g -Wall
BIN_DIR = bin

.PHONY: pgindex
pgindex: $(BIN_DIR)/pgindex

.PHONY: copytest
copytest: $(BIN_DIR)/copytest

.PHONY: settest
settest: $(BIN_DIR)/settest


$(BIN_DIR)/pgindex: $(BIN_DIR)/llistint.o $(BIN_DIR)/setint.o $(BIN_DIR)/.dirstamp
	$(CC) $(CFLAGS) $(BIN_DIR)/llistint.o $(BIN_DIR)/setint.o pgindex.cpp -o $@

$(BIN_DIR)/copytest: $(BIN_DIR)/llistint.o $(BIN_DIR)/.dirstamp
	$(CC) $(CFLAGS) $(BIN_DIR)/llistint.o tests/testLlistInt.cpp -o $@

$(BIN_DIR)/settest: $(BIN_DIR)/llistint.o $(BIN_DIR)/setint.o $(BIN_DIR)/.dirstamp
	$(CC) $(CFLAGS) $(BIN_DIR)/llistint.o $(BIN_DIR)/setint.o tests/testSetInt.cpp -o $@

$(BIN_DIR)/llistint.o: llistint.h $(BIN_DIR)/.dirstamp
	$(CC) $(CFLAGS) -c llistint.cpp -o $@

$(BIN_DIR)/setint.o: setint.h llistint.h $(BIN_DIR)/.dirstamp
	$(CC) $(CFLAGS) -c setint.cpp -o $@


$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)