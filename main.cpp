#include "mainwindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    std::cout << &w << std::endl;
    w.show();
    return a.exec();
}
