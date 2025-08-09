#include "YearlyOverviewDashboardWidget.h"

YearlyOverviewDashboardWidget::YearlyOverviewDashboardWidget(QWidget* parent)
    : QWidget {parent}
{
    // Left side: 12 Month cards
    auto current_year = QDate::currentDate().year();
    auto previous_year = current_year - 1;
    auto year_before_last = current_year - 2;

    m_year_selector = new QComboBox(this);
    m_year_selector->addItem(QString::number(current_year, 10));
    m_year_selector->addItem(QString::number(previous_year, 10));
    m_year_selector->addItem(QString::number(year_before_last, 10));
    connect(m_year_selector, &QComboBox::currentIndexChanged, this, [=](int index){
        onYearSelected(index);
    });

    m_grid_container = new QWidget(this);
    m_grid_layout = new QGridLayout(m_grid_container);

    m_card_button_group = new QButtonGroup(this);
    m_card_button_group->setExclusive(this);

    for(int i = 0; i < m_month_names.size(); ++i) {
        auto card = new QPushButton(m_month_names[i], this);
        card->setMinimumSize(120, 80);
        card->setCheckable(true);
        card->setStyleSheet(
            "QPushButton {"
            "  background-color: #f0f0f0;"
            "  border: 1px solid #ccc;"
            "  border-radius: 8px;"
            "  font-weight: bold;"
            "}"
            "QPushButton:checked {"
            "  background-color: #a0cf44;"
            "}"
        );
        
        int row = i / 3; // 3 columns
        int column = i % 3; // 4 rows
        m_grid_layout->addWidget(card, row, column);
        m_card_button_group->addButton(card, i);
    }
    // TODO: Add connection between card and QListWidget content
    connect(m_card_button_group, &QButtonGroup::idPressed, this, [=](int id){
        qDebug() << "Month selected: " << m_month_names[id];
        onMonthSelected(id);
    });

    auto lhs_layout = new QVBoxLayout;
    lhs_layout->addWidget(m_year_selector);
    lhs_layout->addWidget(m_grid_container);

    // Right side: QListWidget (Monthly bill list)
    m_monthly_bills_list = new QListWidget(this);

    auto h_box_layout = new QHBoxLayout;
    h_box_layout->addLayout(lhs_layout, 3);
    h_box_layout->addWidget(m_monthly_bills_list, 2);

    m_dashboard_title = new QLabel(QString("<h3>%1 - %2</h3>").arg(
        m_default_bill_list_heading, QString::number(current_year, 10)), this);
    auto main_layout = new QVBoxLayout(this);
    main_layout->addWidget(m_dashboard_title);
    main_layout->addLayout(h_box_layout);
    this->setLayout(main_layout);    
}

void YearlyOverviewDashboardWidget::resetFields() {
    auto currently_selected_year = m_year_selector->currentText();
    m_dashboard_title->setText(QString("<h3>%1 - %2</h3>").arg(
        m_default_bill_list_heading, currently_selected_year));
    m_monthly_bills_list->clear();
    // WARNING:
    // Not doing this here: m_year_selector->setCurrentIndex(0); 
    // since the signal &QComboBox::QcurrentIndexChanged would  
    // cause infinite loop and the program crashes

    m_card_button_group->setExclusive(false);
    for (auto* card_button : m_card_button_group->buttons()) {
        card_button->setChecked(false);
    }
    m_card_button_group->setExclusive(true);
}

void YearlyOverviewDashboardWidget::onMonthSelected(int month_index) {
    m_monthly_bills_list->clear();
    auto updated_title = QString("<h3>%1 - %2 %3</h3>").arg(
        m_default_bill_list_heading, 
        m_month_names[month_index],
        m_year_selector->itemText(m_year_selector->currentIndex())
    );
    m_dashboard_title->setText(updated_title);
    // TODO: fetch data & populate the bills_list
}

void YearlyOverviewDashboardWidget::onYearSelected(int year_selector_index) {
    this->resetFields();
    qDebug() << "Year selected: " << m_year_selector->currentText();
    qDebug() << "Year Index: " << year_selector_index;
    // TODO: fetch data for that year & populate the cards    
}

// TODO:  Make YearlyOverviewModel, SqlYearlyOverviewRepository, MonthlyOverviewModel, 
//        & SqlMonthlyOverviewRepository for managing dashboard data querrying, accessing,
//        & in-memory caching.
