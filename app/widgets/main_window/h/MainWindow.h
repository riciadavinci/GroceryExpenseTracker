#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QIcon>
#include <QStackedWidget>

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
    void addItemCategory();
    void searchItemCategory();


private:
    void createUi();
    void createActions();
    void createMenus();

    // Menus:
    QMenu* m_add_menu;
    QMenu* m_search_menu;

    // Actions:
    QAction* m_add_grocery_bill;
    QAction* m_search_grocery_bill;
    QAction* m_add_grocery_store;
    QAction* m_search_grocery_store;
    QAction* m_add_item_category;
    QAction* m_search_item_category;


};
