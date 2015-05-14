#ifndef ADD_REVIEW_WINDOW_H
#define ADD_REVIEW_WINDOW_H
#include "actual_datastore.h"
#include <string>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QPushButton>

class AddReviewWindow : public QDialog
{
  Q_OBJECT

  public:
    AddReviewWindow(ActualDataStore*, std::string);
    ~AddReviewWindow();

  private slots:
    void addReview();

  private:
    // Data
    ActualDataStore* ds;
    std::string prodName;

    // UI
    // Layouts
    QVBoxLayout* overallLayout;
    QHBoxLayout* buttonInputLayout;
    QHBoxLayout* closureButtonLayout;

    // Interaction elements for adding review
    QLabel* scoreLabel;
    QComboBox* scoreButton;
    QLabel* dateLabel;
    QDateEdit* dateButton;
    QLineEdit* reviewField;

    // Interaction elements for closing window
    QPushButton* addButton;
    QPushButton* cancelButton;
};
#endif