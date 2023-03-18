#ifndef CIRCLE_H
#define CIRCLE_H

#include <qpoint.h>
#include <math.h>
//#include "complex.h"
class circle
{
public:
    circle();
    circle(double,double,double);

    double x;
    double y;
    double r;

    int getcross(circle c2, QPoint& p1,QPoint& p2);

    QPointF getnear(QPointF p1);
};

#endif // CIRCLE_H
