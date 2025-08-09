#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QIcon>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "AddGroceryBillWidget.h"
#include "SearchGroceryBillWidget.h"

#include "YearlyOverviewDashboardWidget.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);


private slots:
    void addGroceryBill();
    void searchGroceryBill();
    void addGroceryStore();
    void searchGroceryStore();
    void addBillItem();
    void searchBillItem();
    void addItemCategory();
    void searchItemCategory();
    void viewDashboardYearlyOverview();
    void viewDashboardMonthlyOverview();


private:
    // Menus:
    QMenu* m_add_menu;
    QMenu* m_search_menu;
    QMenu* m_dashboard_menu;
    QMenu* m_reports_menu;

    // Actions:
    QAction* m_add_grocery_bill;
    QAction* m_search_grocery_bill;
    QAction* m_add_grocery_store;
    QAction* m_search_grocery_store;
    QAction* m_add_bill_item;
    QAction* m_search_bill_item;
    QAction* m_add_item_category;
    QAction* m_search_item_category;
    QAction* m_view_dashboard_yearly_overview;
    QAction* m_view_dashboard_monthly_overview;

    // Widgets:
    QStackedWidget* m_central_widget;
    AddGroceryBillWidget* m_add_grocery_bill_widget;
    SearchGroceryBillWidget* m_search_grocery_bill_widget;
    YearlyOverviewDashboardWidget* m_yearly_overview_dashbaord_widget;

    // Private methods:
    void createUi();
    void createActions();
    void createMenus();

    // TODO: Rename 'void clearFields()' to 'void resetFields()'
    
    // TODO: Should I remove BillItem from Add & Search Menus? 
    //       Should I keep a database of all items purchased? 
    //       How will I handle discounts? 
    //       What abour price hikes after inflation??
    //       Think about it carefully!
    // Answer: Product table for standard product, 
    //         Bill Item table for instance of product(it covers discounts, price hikes, etc.)
    //         Look at ChatGPT answer for more details
    // TODO: Thus, replace BillItem in Add & Search Menu with Product entity 

};
