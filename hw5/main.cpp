#include "actual_datastore.h"
#include "db_parser.h"
#include "search_group_widget.h"
#include "main_window.h"
#include <QApplication>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Please specify a database file" << std::endl;
    return 1;
  }

  ActualDataStore ds;

  // Instantiate the parser and its individual product parsers
  DBParser parser;
  parser.addProductParser(new ProductBookParser);
  parser.addProductParser(new ProductClothingParser);
  parser.addProductParser(new ProductMovieParser);

  // Now parse the database to populate the DataStore
  if (parser.parse(argv[1], ds))
  {
    std::cerr << "Error parsing!" << std::endl;
    return 1;
  }

  QApplication app(argc, argv);

  MainWindow mainWindow(&ds);
  mainWindow.show();

  return app.exec();
}