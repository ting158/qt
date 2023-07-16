#include "springmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpringMainWindow w;
    w.show();
    return a.exec();
}
