#include "main_window.h"
#include <QApplication>
#include <fstream>

MainWindow::MainWindow(ActualDataStore* inDS)
{
  ds = inDS;
  userNames = ds->getUsersNames();




  // Title
  setWindowTitle("Amazon");




  // Overall layout
  overallLayout = new QVBoxLayout();




  // // Search group for searching functionality
  sGroup = new SearchGroup(ds);
  overallLayout->addWidget(sGroup);




  // // Section for interacting with users
  // Layout
  userGroupLayout = new QHBoxLayout();
  overallLayout->addLayout(userGroupLayout);
  // Button for selecting current user
  userButtonIdentifier = new QLabel("Current User:");
  userSelButton = new QComboBox();
  for (std::set<std::string>::iterator it = userNames.begin(); it != userNames.end(); ++it)
  {
    userSelButton->addItem(QString::fromStdString(*it));
  }
  userGroupLayout->addWidget(userButtonIdentifier);
  userGroupLayout->addWidget(userSelButton);


  // Add to cart button
  addCartButton = new QPushButton("Add to Cart");
  userGroupLayout->addWidget(addCartButton);
  // Viewcart button
  viewCartButton = new QPushButton("View Cart");
  connect(viewCartButton, SIGNAL(clicked()), this, SLOT(openViewCartWindow()));
  userGroupLayout->addWidget(viewCartButton);




  // // Section for dealing with database
  // Layout
  dbGroupLayout = new QHBoxLayout();
  overallLayout->addLayout(dbGroupLayout);
  // Save functionality
  newDBField = new QLineEdit();
  newDBField->setPlaceholderText("Enter new database filename");
  saveButton = new QPushButton("Save");
  connect(saveButton, SIGNAL(clicked()), this, SLOT(saveDatabase()));
  dbGroupLayout->addWidget(newDBField);
  dbGroupLayout->addWidget(saveButton);
  // Quit
  quitButton = new QPushButton("Quit");
  connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
  dbGroupLayout->addWidget(quitButton);

  // Allow enter/return key to act as go button
  connect(newDBField, SIGNAL(returnPressed()), this, SLOT(saveDatabase()));




  // Mapper to reroute addCartButton to sGroup
  signalMapper = new QSignalMapper(this);
  connect(addCartButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
  signalMapper->setMapping(addCartButton, userSelButton->currentText());
  connect(signalMapper, SIGNAL(mapped(QString)), sGroup, SLOT(addItemToCart(QString)));




  // Set overall layout
  setLayout(overallLayout);
}

MainWindow::~MainWindow()
{
  qDeleteAll(this->children());
}

void MainWindow::openViewCartWindow()
{
  if (userSelButton->currentIndex() == -1)
    return;

  viewCartWindow = new ViewCartWindow(ds, userSelButton->currentText());
  viewCartWindow->exec();
  delete viewCartWindow;

  sGroup->refreshSearchResults();
}

void MainWindow::saveDatabase()
{
  if (newDBField->text().isEmpty())
    return;

  std::ofstream oFile(newDBField->text().toStdString().c_str());
  if (oFile.fail())
    return;

  ds->dump(oFile);

  oFile.close();
  newDBField->setText("");
}