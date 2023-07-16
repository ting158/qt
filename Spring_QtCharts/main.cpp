#include "springwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpringWidget w;
    w.show();
    return a.exec();
}
