#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVector>
#include <QDebug>

class SearchGroceryBillWidget: public QWidget
{
    Q_OBJECT

public:
    SearchGroceryBillWidget(QWidget* parent);
    void clearFields();
    void searchData();

signals:
    void testSignal();

private:
    // Members:
    QLabel* m_title;
    QLineEdit* m_search_bar;
    QPushButton* m_search_buton;
    QListWidget* m_search_results_list;
    
    void createUi();
    void test();
};
