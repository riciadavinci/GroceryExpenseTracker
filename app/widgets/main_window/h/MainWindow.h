#pragma once

#include <QWidget>
#include <QMainWindow>

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

    void createUi();

private:
    //
};
