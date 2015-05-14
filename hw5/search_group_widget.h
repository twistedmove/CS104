#ifndef SEARCH_GROUP_WIDGET_H
#define SEARCH_GROUP_WIDGET_H
#include "actual_datastore.h"
#include "add_review_window.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTabBar>
#include <QListWidget>
#include <sstream>

struct AlphaProdComp
{
  bool operator()(const Product* lhs, const Product* rhs)
  {
    return lhs->getName() <= rhs->getName();
  }
};

struct RatingProdComp
{
  bool operator() (const Product* lhs, const Product* rhs)
  {
    return lhs->getAvgReview() >= rhs->getAvgReview();
  }
};

struct DateReviewComp
{
  bool operator() (const Review* lhs, const Review* rhs)
  {
    return lhs->date <= rhs->date;
  }
};

class SearchGroup : public QWidget
{
  Q_OBJECT

  public:
    SearchGroup(ActualDataStore*);
    ~SearchGroup();

  public slots:
    void addItemToCart(QString);
    void refreshSearchResults();

  private slots:
    void search();
    void dispSearchResults(int);
    void dispReviews(int);
    void openNewReviewWindow();

  private:
    // Data
    ActualDataStore* ds;
    std::vector<Product*> hits;
    std::vector<Review*> reviews;

    // UI
    // Layouts
    QVBoxLayout* overallLayout;
    QHBoxLayout* searchingLayout;

    // Box for specifying search terms and options
    QLabel* searchBoxTitle;
    QVBoxLayout* searchBoxLayout;
    QHBoxLayout* searchOptionsLayout;
    QHBoxLayout* searchTermsLayout;
    QRadioButton* andButton;
    QRadioButton* orButton;
    QLineEdit* searchInput;
    QPushButton* goButton;

    // List of results with sorting options
    QVBoxLayout* resultsLayout;
    QLabel* resultsTitle;
    QTabBar* sortOptions;
    QListWidget* resultsList;

    // Reviews
    QHBoxLayout* reviewGroupLayout;
    QLabel* reviewSecTitle;
    QListWidget* reviewList;
    QPushButton* addReviewButton;
    AddReviewWindow* newReviewWindow;
};
#endif