#ifndef CALCULATION_H
#define CALCULATION_H


class Calculation
{
public:
    Calculation();

private:
    int m_a;
    int m_b;
    int m_arr[10];

public:
    void setA(int a);  //设置变量a
    int getA();  //获取变量A

    void setB(int b);  //设置变量a
    int getB();  //获取变量A

    void setArr();  //设置数组arr
    int *getArr(); //获取数组arr

    int add();   //加法
    int squAdd();  //平方和
    int squAddArr();   //数组平方和
};

#endif // CALCULATION_H
