#include "add_review_window.h"

AddReviewWindow::AddReviewWindow(ActualDataStore* inDS, std::string pName)
{
  ds = inDS;
  prodName = pName;




  // Overall layout
  overallLayout = new QVBoxLayout();




  // // Interaction elements for adding reviews
  // Layout
  buttonInputLayout = new QHBoxLayout();
  overallLayout->addLayout(buttonInputLayout);
  // Score input
  scoreLabel = new QLabel("Score");
  scoreButton = new QComboBox();
  for (int i = 1; i < 6; ++i)
    scoreButton->addItem(QString::number(i));
  buttonInputLayout->addWidget(scoreLabel);
  buttonInputLayout->addWidget(scoreButton);
  // Date input
  dateLabel = new QLabel("Date");
  dateButton = new QDateEdit();
  dateButton->setDisplayFormat("MM/dd/yyyy");
  buttonInputLayout->addWidget(dateLabel);
  buttonInputLayout->addWidget(dateButton);
  // Review input
  reviewField = new QLineEdit();
  reviewField->setPlaceholderText("Enter review here");
  overallLayout->addWidget(reviewField);

  // Defaults date input to system's current date for convenience
  dateButton->setDate(QDate::currentDate());




  // // Interaction for closing window
  // Layout
  closureButtonLayout = new QHBoxLayout();
  overallLayout->addLayout(closureButtonLayout);
  // Add button
  addButton = new QPushButton("Add Review");
  connect(addButton, SIGNAL(clicked()), this, SLOT(addReview()));
  closureButtonLayout->addWidget(addButton);
  // Cancel button
  cancelButton = new QPushButton("Cancel");
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
  closureButtonLayout->addWidget(cancelButton);




  // Set overall layout
  setLayout(overallLayout);
}

AddReviewWindow::~AddReviewWindow()
{
  qDeleteAll(this->children());
}

void AddReviewWindow::addReview()
{
  if (reviewField->text().isEmpty() || scoreButton->currentIndex() == -1)
    return;

  int rating = scoreButton->currentIndex()+1;

  std::string date = dateButton->date().toString(Qt::ISODate).toStdString();

  std::string reviewText = reviewField->text().toStdString();

  Review* r = new Review(prodName, rating, date, reviewText);
  ds->addReview(r);

  close();
}