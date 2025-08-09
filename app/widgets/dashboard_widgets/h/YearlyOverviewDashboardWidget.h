#pragma once

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QDate>
#include <QStringList>
#include <QPushButton>
#include <QString>
#include <QButtonGroup>
#include <QLabel>

class YearlyOverviewDashboardWidget: public QWidget
{
    Q_OBJECT

public:
    YearlyOverviewDashboardWidget(QWidget* parent = nullptr);

    void resetFields();

private:
    // Members:
    QLabel* m_dashboard_title;
    QComboBox* m_year_selector;
    QListWidget* m_monthly_bills_list;
    QWidget* m_grid_container;
    QGridLayout* m_grid_layout;
    QButtonGroup* m_card_button_group;

    QStringList m_month_names = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    QString m_default_bill_list_heading = "Yearly overview";

    void onMonthSelected(int month_index);
    void onYearSelected(int year_selector_index);

};