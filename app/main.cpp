#include <iostream>
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char** argv) {
    auto app = QApplication{argc, argv};
    auto window = MainWindow{nullptr};
    window.show();
    return app.exec();
}
