Makefile options:
	make: defaults to make amazon
	make amazon: creates executable amazon and object files amazon.o, actual_datastore.o, user.o, db_parser.o, product.o, book.o, clothing.o, movie.o, product_parser.o, and util.o in the bin directory
	make clean: removes the bin directory

Amazon.cpp is the completed top-level online retail system. Note that the datastore assumes that users all have unique names, so trying to add a duplicate user or product, create a cart for a user not in the database, or add a product not in the database to a cart will do nothing.  Also note that all dollar amounts are not formatted to display exactly two decimal places ever.  This is to remain consistent without modifying the provided product.cpp and user.cpp files.
Run with: ./bin/amazon <input file>
database.txt is the provided sample input.