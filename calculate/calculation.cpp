#include "calculation.h"

Calculation::Calculation()
{

}

void Calculation::setA(int a)
{
    m_a = a;
}

int Calculation::getA()
{
    return m_a;
}

void Calculation::setB(int b)
{
    m_b = b;
}

int Calculation::getB()
{
    return m_b;
}

void Calculation::setArr()
{
    int i = 0;

    for (i = 0; i < 10; i++){
        m_arr[i] = i;
    }
}

int *Calculation::getArr()
{
    return m_arr;
}

int Calculation::add()
{
    return m_a + m_b;
}

int Calculation::squAdd()
{
    return m_a * m_a + m_b * m_b;
}

int Calculation::squAddArr()
{
    int sum = 0;
    int i = 0;

    for (i = 0; i < 10; i++){
        sum += m_arr[i] * m_arr[i];
    }

    return sum;
}
