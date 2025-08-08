#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>

class SearchGroceryBillWidget: public QWidget
{
    Q_OBJECT

public:
    SearchGroceryBillWidget(QWidget* parent);
    void clearFields();

private:
    // Members:
    QLabel* m_title;
    QLineEdit* m_search_bar;
    QPushButton* m_search_buton;
    QListWidget* m_search_results_list;
    
    void createUi();
};
