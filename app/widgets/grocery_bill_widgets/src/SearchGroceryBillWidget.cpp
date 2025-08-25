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

    // Button connections
    connect(m_search_buton, &QPushButton::pressed, this, &SearchGroceryBillWidget::searchData);
    connect(m_search_results_list, &QListWidget::itemDoubleClicked, this, &SearchGroceryBillWidget::test);
}

void SearchGroceryBillWidget::clearFields() {
    m_search_bar->clear();
    m_search_results_list->clear();
}

void SearchGroceryBillWidget::searchData() {
    // TODO: Handle search later
    QVector<QString> dummy_data = {
        "Netto (02-08-2025) - 9.07€ ",
        "Netto (05-08-2025) - 9.35€ ",
        "Aldi Süd (07-08-2025) - 8.23€ ",
        "REWE (07-08-2025) - 5.63 ",
        "Netto (08-08-2025) - 13.14€ ",
        "Aldi Süd (11-08-2025) - 21.90€ ",
        "Aldi Süd (14-08-2025) - 10.36€ "
    };
    m_search_results_list->clear();
    for (auto& result: dummy_data) {
        m_search_results_list->addItem(result);    
    }
}

void SearchGroceryBillWidget::test() {
    qDebug() << "Item pressed!";
    emit testSignal();
}