#include "SearchGroceryBillWidget.h"

SearchGroceryBillWidget::SearchGroceryBillWidget(QWidget* parent)
    : QWidget {parent}
{
    this->createUi();
}


void SearchGroceryBillWidget::createUi() {
    m_title = new QLabel("<h3>Search Grocery Bill</h3>", this);

    m_search_bar = new QLineEdit(this);
    m_search_buton = new QPushButton(tr("Search"), this);
    auto search_fields_layout = new QHBoxLayout;
    search_fields_layout->addWidget(m_search_bar);
    search_fields_layout->addWidget(m_search_buton);

    m_search_results_list = new QListWidget(this);

    auto main_layout = new QVBoxLayout(this);
    main_layout->addWidget(m_title);
    main_layout->addLayout(search_fields_layout);
    main_layout->addWidget(m_search_results_list);
    this->setLayout(main_layout);
}

void SearchGroceryBillWidget::clearFields() {
    m_search_bar->clear();
    m_search_results_list->clear();
}
