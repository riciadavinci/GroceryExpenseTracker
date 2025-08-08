#include "MainWindow.h"

#include "MainMenuTextContent.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{parent}
{

    this->setWindowTitle("Grocery Expense Tracker");
    this->createUi();
}


void MainWindow::createUi() {
    qDebug() << "Create UI!\n";
    
    this->createActions();
    this->createMenus();

    auto central_widget = new QStackedWidget();
    this->setCentralWidget(central_widget);

    QString message = tr("Welcome to Grocery Expense Tracker");
    statusBar()->showMessage(message);
}

void MainWindow::createActions() {
    qDebug() << "Create Actions!\n";

    // Add Menu Actions:
    m_add_grocery_bill = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew),
                                     tr("&Grocery Bill"), this);
    m_add_grocery_bill->setStatusTip(tr(ADD_GROCERY_BILL_TEXT));
    m_add_grocery_bill->setToolTip(tr(ADD_GROCERY_BILL_TEXT));
    connect(m_add_grocery_bill, &QAction::triggered, this, &MainWindow::addGroceryBill);

    m_add_grocery_store = new QAction(tr("&Grocery Store"), this);
    m_add_grocery_store->setStatusTip(tr(ADD_GROCERY_STORE_TEXT));
    m_add_grocery_store->setToolTip(tr(ADD_GROCERY_STORE_TEXT));
    connect(m_add_grocery_store, &QAction::triggered, this, &MainWindow::addGroceryStore);

    m_add_item_category = new QAction(tr("&Item Category"), this);
    m_add_item_category->setStatusTip(tr(ADD_ITEM_CATEGORY_TEXT));
    m_add_item_category->setToolTip(tr(ADD_ITEM_CATEGORY_TEXT));
    connect(m_add_item_category, &QAction::triggered, this, &MainWindow::addItemCategory);

    // Search Menu Actions:
    m_search_grocery_bill = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch),
                                     tr("&Grocery Bill"), this);
    m_search_grocery_bill->setStatusTip(tr(SEARCH_GROCERY_BILL_TEXT));
    m_search_grocery_bill->setToolTip(tr(SEARCH_GROCERY_BILL_TEXT));
    connect(m_search_grocery_bill, &QAction::triggered, this, &MainWindow::searchGroceryBill);

    m_search_grocery_store = new QAction(tr("&Grocery Store"), this);
    m_search_grocery_store->setStatusTip(tr(SEARCH_GROCERY_STORE_TEXT));
    m_search_grocery_store->setToolTip(tr(SEARCH_GROCERY_STORE_TEXT));
    connect(m_search_grocery_store, &QAction::triggered, this, &MainWindow::searchGroceryStore);

    m_search_item_category = new QAction(tr("&Item Category"), this);
    m_search_item_category->setStatusTip(tr(SEARCH_ITEM_CATEGORY_TEXT));
    m_search_item_category->setToolTip(tr(SEARCH_ITEM_CATEGORY_TEXT));
    connect(m_search_item_category, &QAction::triggered, this, &MainWindow::searchItemCategory);

}


void MainWindow::createMenus() {
    qDebug() << "Create Menus!\n";
    m_add_menu = menuBar()->addMenu(tr("&Add"));
    m_add_menu->addAction(m_add_grocery_bill);
    m_add_menu->addAction(m_add_grocery_store);
    m_add_menu->addAction(m_add_item_category);

    m_search_menu = menuBar()->addMenu(tr("&Search"));
    m_search_menu->addAction(m_search_grocery_bill);
    m_search_menu->addAction(m_search_grocery_store);
    m_search_menu->addAction(m_search_item_category);
}


// Slots:

void MainWindow::addGroceryBill() {
    qDebug() << "Add Grocery Bill clicked!\n";
}

void MainWindow::searchGroceryBill() {
    qDebug() << "Add Grocery Store clicked!\n";

}

void MainWindow::addGroceryStore() {
    qDebug() << "Add Item Category clicked!\n";

}

void MainWindow::searchGroceryStore() {
    qDebug() << "Search Grocery Bill clicked!\n";

}

void MainWindow::addItemCategory() {
    qDebug() << "Search Grocery Store clicked!\n";

}

void MainWindow::searchItemCategory() {
    qDebug() << "Search Item Category clicked!\n";

}

