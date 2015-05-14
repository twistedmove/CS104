#ifndef VIEW_CART_WINDOW_H
#define VIEW_CART_WINDOW_H
#include "actual_datastore.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>

class ViewCartWindow : public QDialog
{
  Q_OBJECT

  public:
    ViewCartWindow(ActualDataStore*, QString);
    ~ViewCartWindow();

  private slots:
    void updateCartDisp();
    void buyCart();
    void removeItem();

  private:
    // Data
    ActualDataStore* ds;
    std::vector<Product*> cart;
    std::string userName;

    // UI
    // Layouts
    QVBoxLayout* overallLayout;
    QHBoxLayout* buttonsLayout;

    // Label to know whose cart is active
    QLabel* currentUserLabel;

    // List of cart items
    QListWidget* cartItemsList;

    // Buttons for interacting with window and cart
    QPushButton* buyCartButton;
    QPushButton* removeItemButton;
    QPushButton* closeButton;
};
#endif