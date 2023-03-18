#ifndef MyComplex_H
#define MyComplex_H

#include <iostream>
using namespace std;
#include <cmath>
class MyComplex {
public:

    MyComplex(double real = 1, double imag = 0);
    MyComplex(MyComplex& c);//如果有复制构造函数，那么就不能return MyComplex

    MyComplex(const MyComplex& c);
    //一定要有这个才能将多个运算叠加，因为括号返回的是临时生成的const MyComplex类型，然后读不懂，尝试转换为MyComplex，但是已经是MyComplex了

    double getreal()const;
    double getimag()const;
    double getmodel()const;
    double getlen()const;
    double getang()const;

    void setreal(double x);
    void setimag(double y);

    void show()const;

    double operator [](int);
    /*MyComplex operator+(MyComplex c1);
    MyComplex operator-(MyComplex c1);
    MyComplex operator+(MyComplex c1);
    MyComplex operator-(MyComplex c1);*/
    ///这些不能与数字运算
    MyComplex& operator+=(const MyComplex& c1);
    MyComplex& operator-=(const MyComplex& c1);
    MyComplex& operator*=(const MyComplex& c1);
    MyComplex& operator/=(const MyComplex& c1);

    MyComplex operator ++(int);//右加加//返回值为原来的

    MyComplex& operator ++();//左加加//返回值为加后的值
    ~MyComplex();

private:
    double real;
    double imag;
};
MyComplex operator+(const MyComplex& c1, const MyComplex&  c2);
MyComplex operator-(const MyComplex& c1, const MyComplex&  c2);
MyComplex operator*(const MyComplex& c1, const MyComplex&  c2);
MyComplex operator/(const MyComplex& c1, const MyComplex&  c2);
MyComplex operator^(const MyComplex& c1, const double & c2);
MyComplex operator^(const MyComplex& c1, const MyComplex&  c2);

MyComplex Exp(const MyComplex & c);
MyComplex Ln (const MyComplex &);
ostream & operator <<(ostream& o,const MyComplex& c);

#endif // MyComplex_H
