#include "zcpoint.h"

zcpoint::zcpoint()
{
    reflect = MyComplex(0.5,0.5);
    updatebyref();
//    x = 0.5;
//    y = 0.5;
//    r = 0;
//    zr = 0;
//    zx = 0;
    ifdrawline = true;

    update();
}
void zcpoint::updatebyref(){
    zl = (1.0 + reflect)/(1.0 - reflect);
    zr = zl.getreal();
    zx = zl.getimag();

    x = reflect.getreal();
    y = reflect.getimag();
    r = reflect.getlen();
    ro = (1+r)/(1-r);
    yl = 1/zl;
}
void zcpoint::updatebyz(){

    reflect = (zl-1)/(zl+1);
    x = reflect.getreal();
    y = reflect.getimag();
    r = reflect.getlen();
    ro = (1+r)/(1-r);

    zr = zl.getreal();
    zx = zl.getimag();
    yl = 1/zl;
}
void zcpoint::update(){

    Cr.r = abs(1/(1+zr));
    Cr.x = zr/(1+zr);
    Cr.y = 0;
//    qDebug()<<","<<Cr.r<<","<<Cr.x<<","<<Cr.y<<",";
    Cx.r = abs(1/zx);
    Cx.x = 1;
    Cx.y = 1/zx;

    Cref.r = r;
    ang = reflect.getang();
}
double zcpoint::getlen()
{
    return r;
}
double zcpoint::getzr()
{

    return zr;
}

double zcpoint::getzx()
{
    return zx;
}

QString zcpoint::Tostring(int mode)
{
    switch (mode) {

    case 0://阻抗
        return (QString::number(x,'g',4)+ (y>0?"+":"") +QString::number(y,'g',4) + "j");
        break;
    case 1:
        return (QString::number(zr,'g',4)+ (zx>0?"+":"") +QString::number(zx,'g',4) + "j");
        break;
    case 2: //导纳
        return (QString::number(yl.getreal(),'g',4)+ (y<0?"+":"") +QString::number(yl.getimag(),'g',4) + "j");
        break;
    default:
        return "error";
        break;
    }
    return "d";
}
