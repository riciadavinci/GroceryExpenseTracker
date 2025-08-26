#include <iostream>
#include <QApplication>
#include "MainWindow.h"
#include "SqlQueryLoader.h"

int main(int argc, char** argv) {
    auto app = QApplication{argc, argv};
    auto window = MainWindow{nullptr};
    auto sql_query_loader = SqlQueryLoader("resources/sql");

    window.show();
    return app.exec();
}
