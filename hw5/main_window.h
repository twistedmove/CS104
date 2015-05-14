#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include "actual_datastore.h"
#include "search_group_widget.h"
#include "view_cart_window.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QSignalMapper>

class MainWindow : public QWidget
{
  Q_OBJECT

  public:
    MainWindow(ActualDataStore*);
    ~MainWindow();

  private slots:
    void openViewCartWindow();
    void saveDatabase();

  private:
    ActualDataStore* ds;
    std::set<std::string> userNames;
    std::vector<Product*> searchResults;

    // Layouts
    QVBoxLayout* overallLayout;

    // Search group for searching functionality
    SearchGroup* sGroup;

    // Section for interacting with users
    QHBoxLayout* userGroupLayout;
    QLabel* userButtonIdentifier;
    QComboBox* userSelButton;
    QPushButton* addCartButton;
    QPushButton* viewCartButton;
    ViewCartWindow* viewCartWindow;

    // Section for dealing with database
    QHBoxLayout* dbGroupLayout;
    QLineEdit* newDBField;
    QPushButton* saveButton;
    QPushButton* quitButton;

    // Mapper to reroute addCartButton to sGroup
    QSignalMapper* signalMapper;

};
#endif