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
    
    m_add_grocery_bill_widget = new AddGroceryBillWidget(this);
    m_search_grocery_bill_widget = new SearchGroceryBillWidget(this);
    m_yearly_overview_dashbaord_widget = new YearlyOverviewDashboardWidget(this);
    
    m_central_widget = new QStackedWidget(this);
    m_central_widget->addWidget(m_add_grocery_bill_widget);
    m_central_widget->addWidget(m_search_grocery_bill_widget);
    m_central_widget->addWidget(m_yearly_overview_dashbaord_widget);

    m_central_widget->setCurrentWidget(m_search_grocery_bill_widget);
    this->setCentralWidget(m_central_widget);
    
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

    m_add_bill_item = new QAction(tr("&Bill Item"), this);
    m_add_bill_item->setStatusTip(tr(ADD_BILL_ITEM_TEXT));
    m_add_bill_item->setToolTip(tr(ADD_BILL_ITEM_TEXT));
    connect(m_add_bill_item, &QAction::triggered, this, &MainWindow::addBillItem);

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

    m_search_bill_item = new QAction(tr("&Bill Item"), this);
    m_search_bill_item->setStatusTip(tr(SEARCH_BILL_ITEM_TEXT));
    m_search_bill_item->setToolTip(tr(SEARCH_BILL_ITEM_TEXT));
    connect(m_search_bill_item, &QAction::triggered, this, &MainWindow::searchBillItem);

    m_search_item_category = new QAction(tr("&Item Category"), this);
    m_search_item_category->setStatusTip(tr(SEARCH_ITEM_CATEGORY_TEXT));
    m_search_item_category->setToolTip(tr(SEARCH_ITEM_CATEGORY_TEXT));
    connect(m_search_item_category, &QAction::triggered, this, &MainWindow::searchItemCategory);

    // Dashboard Menu Actions:
    m_view_dashboard_yearly_overview = new QAction(QIcon::fromTheme("view-dashboard"), tr("&Yearly Overview"), this);
    m_view_dashboard_yearly_overview->setStatusTip(tr(VIEW_DASHBOARD_YEARLY_OVERVIEW_TEXT));
    m_view_dashboard_yearly_overview->setToolTip(tr(VIEW_DASHBOARD_YEARLY_OVERVIEW_TEXT));
    connect(m_view_dashboard_yearly_overview, &QAction::triggered, this, &MainWindow::viewDashboardYearlyOverview);
    
    m_view_dashboard_monthly_overview = new QAction(QIcon::fromTheme("x-office-document"), tr("&Monthly Overview"), this);
    m_view_dashboard_monthly_overview->setStatusTip(tr(VIEW_DASHBOARD_MONTHLY_OVERVIEW_TEXT));
    m_view_dashboard_monthly_overview->setToolTip(tr(VIEW_DASHBOARD_MONTHLY_OVERVIEW_TEXT));
    connect(m_view_dashboard_monthly_overview, &QAction::triggered, this, &MainWindow::viewDashboardMonthlyOverview);
}


void MainWindow::createMenus() {
    qDebug() << "Create Menus!\n";
    m_add_menu = menuBar()->addMenu(tr("&Add"));
    m_add_menu->addAction(m_add_grocery_bill);
    m_add_menu->addAction(m_add_grocery_store);
    m_add_menu->addAction(m_add_bill_item);
    m_add_menu->addAction(m_add_item_category);

    m_search_menu = menuBar()->addMenu(tr("&Search"));
    m_search_menu->addAction(m_search_grocery_bill);
    m_search_menu->addAction(m_search_grocery_store);
    m_search_menu->addAction(m_search_bill_item);
    m_search_menu->addAction(m_search_item_category);

    m_dashboard_menu = menuBar()->addMenu(tr("&Dashboard"));
    m_dashboard_menu->addAction(m_view_dashboard_yearly_overview);
    m_dashboard_menu->addAction(m_view_dashboard_monthly_overview);

    m_reports_menu = menuBar()->addMenu(tr("&Reports"));
}


// Slots:
void MainWindow::addGroceryBill() {
    qDebug() << "Add Grocery Bill clicked!\n";
    if ((m_central_widget->currentWidget()) != m_add_grocery_bill_widget) {
        m_add_grocery_bill_widget->clearFields();
    }
    m_central_widget->setCurrentWidget(m_add_grocery_bill_widget);
}

void MainWindow::searchGroceryBill() {
    qDebug() << "Search Grocery Store clicked!\n";
    if ((m_central_widget->currentWidget()) != m_search_grocery_bill_widget) {
        m_search_grocery_bill_widget->clearFields();
    }
    m_central_widget->setCurrentWidget(m_search_grocery_bill_widget);
}

void MainWindow::addGroceryStore() {
    qDebug() << "Add Item Category clicked!\n";

}

void MainWindow::searchGroceryStore() {
    qDebug() << "Search Grocery Bill clicked!\n";

}

void MainWindow::addBillItem() {
    qDebug() << "Add Bill Item clicked!\n";

}

void MainWindow::searchBillItem() {
    qDebug() << "Search Bill Item clicked!\n";

}

void MainWindow::addItemCategory() {
    qDebug() << "Search Grocery Store clicked!\n";

}

void MainWindow::searchItemCategory() {
    qDebug() << "Search Item Category clicked!\n";

}

void MainWindow::viewDashboardYearlyOverview() {
    qDebug() << "View Dashboard (Yearly Overview) clicked!\n";

    m_central_widget->setCurrentWidget(m_yearly_overview_dashbaord_widget);
}

void MainWindow::viewDashboardMonthlyOverview() {
    qDebug() << "View Dashboard (Monthly Overview) clicked!\n";
    
}
