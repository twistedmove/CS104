#include "view_cart_window.h"

ViewCartWindow::ViewCartWindow(ActualDataStore* inDS, QString qstrUsername)
{
  ds = inDS;
  userName = qstrUsername.toStdString();
  cart = ds->getUserCart(userName);




  // Overall layout
  overallLayout = new QVBoxLayout();




  // Label to know whose cart is active
  currentUserLabel = new QLabel(qstrUsername+" Cart");
  overallLayout->addWidget(currentUserLabel);




  // List of cart items
  cartItemsList = new QListWidget();
  updateCartDisp();
  overallLayout->addWidget(cartItemsList);




  // // Buttons for interacting with window and cart
  // Layout
  buttonsLayout = new QHBoxLayout();
  overallLayout->addLayout(buttonsLayout);
  // Buy cart button
  buyCartButton = new QPushButton("Buy Cart");
  buyCartButton->setToolTip("Attempts to check out each item in the cart in order.\nOnly buys in-stock items for which the user has enough credit");
  connect(buyCartButton, SIGNAL(clicked()), this, SLOT(buyCart()));
  buttonsLayout->addWidget(buyCartButton);
  // Remove item button
  removeItemButton = new QPushButton("Remove Item");
  connect(removeItemButton, SIGNAL(clicked()), this, SLOT(removeItem()));
  buttonsLayout->addWidget(removeItemButton);
  // Close button
  closeButton = new QPushButton("Close");
  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
  buttonsLayout->addWidget(closeButton);




  // Set overall layout
  setLayout(overallLayout);
}

ViewCartWindow::~ViewCartWindow()
{
  qDeleteAll(this->children());
}

void ViewCartWindow::updateCartDisp()
{
  cartItemsList->clear();

  for (std::vector<Product*>::iterator it = cart.begin(); it != cart.end(); ++it)
    cartItemsList->addItem(QString::fromStdString((*it)->displayString()));
}

void ViewCartWindow::buyCart()
{
  ds->buyCart(userName);
  cart = ds->getUserCart(userName);
  updateCartDisp();
}

void ViewCartWindow::removeItem()
{
  if (cartItemsList->currentRow() == -1)
    return;

  ds->removeItem(userName, cartItemsList->currentRow());
  cart = ds->getUserCart(userName);
  updateCartDisp();
}