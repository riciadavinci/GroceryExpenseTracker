#include "AddGroceryBillWidget.h"

AddGroceryBillWidget::AddGroceryBillWidget(QWidget* parent)
    : QWidget {parent}
{
    this->createUi();
}


void AddGroceryBillWidget::createUi() {
    m_title = new QLabel("<h3>Add Grocery Bill<h3>", this);

    auto bill_amount_label = new QLabel(tr("Bill amount:"), this);
    m_bill_amount_field = new QLineEdit(this);
    m_bill_amount_field->setValidator(new QDoubleValidator(0.0, 1000.0, 2, this));
    auto bill_amount_layout = new QHBoxLayout;
    bill_amount_layout->addWidget(bill_amount_label);   
    bill_amount_layout->addWidget(m_bill_amount_field);

    auto grocery_store_label = new QLabel(tr("Grocery Store:"), this);
    m_grocery_store_dropdown = new QComboBox(this);
    m_grocery_store_dropdown->addItem("Aldi Seud");
    m_grocery_store_dropdown->addItem("Rewe");
    m_grocery_store_dropdown->addItem("Netto");
    m_grocery_store_dropdown->addItem("Kaufland");
    m_grocery_store_dropdown->addItem("Lidl");
    auto grocery_store_dropdown_layout = new QHBoxLayout;
    grocery_store_dropdown_layout->addWidget(grocery_store_label);
    grocery_store_dropdown_layout->addWidget(m_grocery_store_dropdown);

    auto bill_date_label = new QLabel(tr("Date:"), this);
    m_bill_date_field = new QDateEdit(this);
    m_bill_date_field->setDate(QDate::currentDate());
    m_bill_date_field->setCalendarPopup(true);
    auto date_field_layout = new QHBoxLayout;
    date_field_layout->addWidget(bill_date_label);
    date_field_layout->addWidget(m_bill_date_field);

    auto bill_time_label = new QLabel(tr("Time:"), this);
    m_bill_time_field = new QTimeEdit(this);
    m_bill_time_field->setTime(QTime::currentTime());
    m_bill_time_field->setCalendarPopup(true);
    auto time_field_layout = new QHBoxLayout;
    time_field_layout->addWidget(bill_time_label);
    time_field_layout->addWidget(m_bill_time_field);

    m_save_button = new QPushButton("Save", this);
    m_clear_button = new QPushButton("Clear", this);
    m_cancel_button = new QPushButton("Cancel", this);
    auto buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(m_save_button);
    buttons_layout->addWidget(m_clear_button);
    buttons_layout->addWidget(m_cancel_button);

    connect(m_clear_button, &QPushButton::pressed, this, &AddGroceryBillWidget::clearFields);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->addWidget(m_title);
    main_layout->addLayout(bill_amount_layout);
    main_layout->addLayout(grocery_store_dropdown_layout);
    main_layout->addLayout(date_field_layout);
    main_layout->addLayout(time_field_layout);
    main_layout->addLayout(buttons_layout);
    this->setLayout(main_layout);
}

void AddGroceryBillWidget::clearFields() {
    m_bill_amount_field->clear();
    m_grocery_store_dropdown->setCurrentIndex(0);
    m_bill_date_field->setDate(QDate::currentDate());
    m_bill_time_field->setTime(QTime::currentTime());

}
