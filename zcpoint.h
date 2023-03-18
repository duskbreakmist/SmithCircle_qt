#ifndef ZCPOINT_H
#define ZCPOINT_H

#include "circle.h"
#include "mycomplex.h"
#include <QDebug>
class zcpoint
{
public:
    zcpoint();

    MyComplex reflect;//反射系数
    double x;   //反射系数实部
    double y;
    double r;   //反射系数模长
    double ro;//驻波系数

    MyComplex zl;//归一化阻抗
    MyComplex yl;//归一化导纳
    double zr;  //归一化电阻
    double zx;  //归一化电抗
//    std::complex<double> reflect=0;
//    std::complex<double> zl=0;
    //用不了，用std的就会报错error: expected nest



    bool ifdrawline;
    circle Cr;
    circle Cx;
    circle Cref;

    double ang;

    double getlen();
    double getzr();
    double getzx();

    void update();
    void updatebyz();
    void updatebyref();


    zcpoint getcrossZR();
    QString Tostring(int mode=0);

private:

};

#endif // ZCPOINT_H
