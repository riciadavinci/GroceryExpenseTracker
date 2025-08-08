#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QDate>
#include <QTime>
#include <QDateTime>

class AddGroceryBillWidget: public QWidget
{
    Q_OBJECT

public:
    AddGroceryBillWidget(QWidget* parent);
    void clearFields();

private:
    // Members:
    QLabel* m_title;
    QLineEdit* m_bill_amount_field;
    QComboBox* m_grocery_store_dropdown;
    QDateEdit* m_bill_date_field;
    QTimeEdit* m_bill_time_field;
    QPushButton* m_save_button;
    QPushButton* m_clear_button;
    QPushButton* m_cancel_button;

    void createUi();
};
