#include <thread>
#include <QApplication>
#include "mainwindow.h"
#include "system.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    System::ui = &w;
    std::thread t(&System::run);

    w.show();

    auto ret = a.exec();
    t.join();
    return ret;
}
