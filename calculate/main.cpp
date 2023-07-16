#include <QCoreApplication>
#include <QDebug>

#include "calculation.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int sum, squSum;
    Calculation c1, c2;

    c1.setA(1);
    c1.setB(2);
    c2.setA(3);
    c2.setB(4);

    sum = c1.add();
    squSum = c1.squAdd();

    qDebug() << "c1的和为：" << sum;
    qDebug() << "c1的平方和为：" << squSum;

    sum = c2.add();
    squSum = c2.squAdd();

    qDebug() << "c2的和为：" << sum;
    qDebug() << "c2的平方和为：" << squSum;


    int * arr;
    int squArrAum = 0;

    c1.setArr();
    arr = c1.getArr();
    squArrAum = c1.squAddArr();

    for (int i = 0; i < 10; i++){
        qDebug() << arr[i];
    }

    qDebug() << "c1数组的平方和为：" << squArrAum;


    return a.exec();
}
