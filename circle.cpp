#include "circle.h"
circle::circle(double a,double b ,double c)
{
    x = a;
    y = b;
    r = c;

}
circle::circle()
{
    x = 0;
    y = 0;
    r = 0;

}
QPointF circle::getnear(QPointF p1){

    QPointF temp = (p1- QPointF(x,y));
    if(temp.manhattanLength()<0.002){
        temp = QPointF(1,0);//防止到0
    }
    double len = sqrt(temp.rx()*temp.rx()+temp.ry()*temp.ry());
    temp *= r/len;
    return (QPointF(x,y)+temp);

}
int circle::getcross(circle c2, QPoint& p1,QPoint& p2){
    double d = sqrt((x-c2.x)*(x-c2.x)+(y-c2.y)*(y-c2.y));
    if(d>r+c2.r||d<abs(r-c2.r)){
        return 0;
    }
    if(d==0){
        return -1;
    }
    if((d==r+c2.r) ||(d==abs(r-c2.r))){


        return 1;
    }

    return 2;
}
