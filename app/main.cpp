#include <iostream>
#include <QApplication>
#include <QWidget>

int main(int argc, char** argv) {
    auto app = QApplication{argc, argv};
    auto window = QWidget{};
    window.show();
    return app.exec();
}
