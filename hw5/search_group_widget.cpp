#include "search_group_widget.h"
#include "util.h"
#include "msort.h"

SearchGroup::SearchGroup(ActualDataStore* inDS)
{
  ds = inDS;





  // Overall Layout
  overallLayout = new QVBoxLayout();




  searchingLayout = new QHBoxLayout();
  overallLayout->addLayout(searchingLayout);
  // // Box for specifying search terms and options
  // Layout
  searchBoxLayout = new QVBoxLayout();
  searchingLayout->addLayout(searchBoxLayout);

  // Title
  searchBoxTitle = new QLabel("Search Products");
  searchBoxLayout->addWidget(searchBoxTitle);

  // Option buttons
  searchOptionsLayout = new QHBoxLayout();
  searchBoxLayout->addLayout(searchOptionsLayout);
  // AND button
  andButton = new QRadioButton("AND Search");
  andButton->setToolTip("Products containing ALL terms entered");
  searchOptionsLayout->addWidget(andButton);
  // OR button
  orButton = new QRadioButton("OR Search");
  orButton->setToolTip("Products containing ANY terms entered");
  searchOptionsLayout->addWidget(orButton);

  // Terms
  searchTermsLayout = new QHBoxLayout();
  searchBoxLayout->addLayout(searchTermsLayout);
  // Text field
  searchInput = new QLineEdit();
  searchInput->setPlaceholderText("Enter search terms");
  searchTermsLayout->addWidget(searchInput);
  // Go button
  goButton = new QPushButton("Go");
  connect(goButton, SIGNAL(clicked()), this, SLOT(search()));
  searchTermsLayout->addWidget(goButton);

  // Make it so search box stays together
  searchBoxLayout->addStretch();

  // Make text field longer
  QSize longer = searchInput->minimumSizeHint();
  longer.setWidth(longer.width()+100);
  searchInput->setMinimumSize(longer);

  // Allow enter/return key to act as go button
  connect(searchInput, SIGNAL(returnPressed()), this, SLOT(search()));

  



  // // List of results with sorting options
  // Layout
  resultsLayout = new QVBoxLayout();
  searchingLayout->addLayout(resultsLayout);

  // Title
  resultsTitle = new QLabel("Search Results");
  resultsLayout->addWidget(resultsTitle);

  // Sorting options
  sortOptions = new QTabBar();
  sortOptions->addTab("Sort Alphabetical");
  sortOptions->addTab("Sort Rating High to Low");
  connect(sortOptions, SIGNAL(currentChanged(int)), this, SLOT(dispSearchResults(int)));
  resultsLayout->addWidget(sortOptions);

  // Search results
  resultsList = new QListWidget();
  resultsLayout->addWidget(resultsList);
  connect(resultsList, SIGNAL(currentRowChanged(int)), this, SLOT(dispReviews(int)));




  
  // // Reviews
  // Title
  reviewSecTitle = new QLabel("Reviews");
  overallLayout->addWidget(reviewSecTitle);
  // Layout
  reviewGroupLayout = new QHBoxLayout();
  overallLayout->addLayout(reviewGroupLayout);
  // List
  reviewList = new QListWidget();
  reviewGroupLayout->addWidget(reviewList);
  // Add review button
  addReviewButton = new QPushButton("Add Review");
  connect(addReviewButton, SIGNAL(clicked()), this, SLOT(openNewReviewWindow()));
  reviewGroupLayout->addWidget(addReviewButton);




  
  // Set overall Layout
  setLayout(overallLayout);
}

SearchGroup::~SearchGroup()
{
  qDeleteAll(this->children());
}

void SearchGroup::addItemToCart(QString qStrUsername)
{
  if (resultsList->currentRow() == -1)
    return;

  ds->addToCart(qStrUsername.toStdString(), hits[resultsList->currentRow()]);
}

void SearchGroup::refreshSearchResults()
{
  // Save the current selected item if applicable
  if (resultsList->currentRow() != -1)
  {
    std::string temp = hits[resultsList->currentRow()]->getName();
    dispSearchResults(sortOptions->currentIndex());
    for (int row = 0; row < resultsList->count(); ++row)
    {
      if (hits[row]->getName() == temp)
      {
        resultsList->setCurrentItem(resultsList->item(row));
        break;
      }
    }
  }
  else
    dispSearchResults(sortOptions->currentIndex());
}

void SearchGroup::search()
{
  if (searchInput->text().isEmpty() || (!orButton->isChecked() && !andButton->isChecked()))
    return;

  // Parse input terms
  std::stringstream ss(searchInput->text().toStdString());
  std::string term;
  std::vector<std::string> terms;
  while (ss >> term)
  {
    term = convToLower(term);
    terms.push_back(term);
  }

  // Clear input field
  searchInput->setText("");

  // Perform search
  if (andButton->isChecked())
    hits = ds->search(terms, 0);
  else
    hits = ds->search(terms, 1);

  dispSearchResults(sortOptions->currentIndex());
}

void SearchGroup::dispSearchResults(int sortNum)
{
  resultsList->clear();

  if (sortNum == 0)
  {
    AlphaProdComp aComp;
    mergeSort(hits, aComp);
  }
  else if (sortNum == 1)
  {
    RatingProdComp rComp;
    mergeSort(hits, rComp);
  }

  for (std::vector<Product*>::iterator it = hits.begin(); it != hits.end(); ++it)
    resultsList->addItem(QString::fromStdString((*it)->displayString()));
}

void SearchGroup::dispReviews(int pIndex)
{
  reviewList->clear();

  // Do not attempt to add reviews after the resultsList has been cleared
  if (pIndex == -1)
    return;

  reviewList->addItem("Average Review Score: "+QString::number(hits[pIndex]->getAvgReview()));
  
  reviews = ds->getProductReviews(hits[pIndex]->getName());

  DateReviewComp dComp;
  mergeSort(reviews, dComp);

  for (std::vector<Review*>::iterator it = reviews.begin(); it != reviews.end(); ++it)
    reviewList->addItem(QString::fromStdString((*it)->displayString()));
}

void SearchGroup::openNewReviewWindow()
{
  if (resultsList->currentRow() == -1)
    return;

  newReviewWindow = new AddReviewWindow(ds, hits[resultsList->currentRow()]->getName());
  newReviewWindow->exec();
  delete newReviewWindow;

  refreshSearchResults();
}