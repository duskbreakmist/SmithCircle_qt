#include "mycomplex.h"

MyComplex::MyComplex(double x, double y) {
    real = x;
    imag = y;
}
MyComplex::MyComplex(MyComplex& c) {
    real = c.getreal();
    imag = c.getimag();
}
MyComplex::MyComplex(const MyComplex& c) {
    real = c.real;
    imag = c.imag;
}

double MyComplex::getreal()const {
    return real;
}
double MyComplex::getimag()const {
    return imag;
}
double MyComplex::getmodel()const {
        return (real * real + imag * imag);
}
double MyComplex::getlen()const {
    return pow((real * real + imag * imag), 0.5);
}
double MyComplex::getang()const {
    double len = pow((real * real + imag * imag), 0.5);

    return imag>0?acos(real/len):-acos(real / len);
}

void MyComplex::show()const {
    cout << real << (imag<0?"-":"+") << abs(imag) << 'i' << endl;
}
void MyComplex::setreal(double x) {
    real = x;
}
void MyComplex::setimag(double y) {
    imag = y;
}
//////////////////////////
MyComplex::~MyComplex() {
}
double MyComplex::operator[](int x) {
    if (x == 1) {
        return real;
    }
    if (x == 2) {
        return imag;
    }
}
MyComplex MyComplex::operator ++(int) {
    MyComplex c;
    c = *this;
    *this = *this+1	;
    return c;
}
MyComplex& MyComplex::operator ++() {
    *this = *this + 1;
    return *this;
}
/////////////////////////
MyComplex& MyComplex::operator+=(const MyComplex& c1) {
    MyComplex c(c1.getreal() + real, c1.getimag() + imag);
    *this = c;
    return *this;
}
MyComplex& MyComplex::operator-=(const MyComplex& c2) {
    MyComplex c(real + c2.getreal(), imag -c2.getimag());
    *this = c;
    return *this;
}
MyComplex& MyComplex::operator*=(const MyComplex& c2){
    double
        x1 = real,
        y1 = imag,
        x2 = c2.getreal(),
        y2 = c2.getimag();
    MyComplex c(x1 * x2 - y1 * y2, x1 * y2 + x2 * y1);
    *this = c;
    return *this;
}
MyComplex& MyComplex::operator/=(const MyComplex& c2) {
    double
        x1 = real,
        y1 = imag,
        x2 = c2.getreal(),
        y2 = c2.getimag(),
        len = c2.getmodel();
    double
        x = (x1 * x2 + y1 * y2) / len,
        y = (y1 * x2 - y2 * x1) / len;
    MyComplex c(x, y);
    *this = c;
    return *this;
}
//////////////////////////
MyComplex operator+(const MyComplex& c1,const MyComplex& c2) {
    MyComplex c(c1.getreal()+c2.getreal(),c1.getimag()+c2.getimag());
    return c;
}
MyComplex operator-(const MyComplex& c1,const MyComplex& c2) {

    MyComplex c(c1.getreal() - c2.getreal(), c1.getimag() - c2.getimag());
    return c;
}
MyComplex operator*(const MyComplex& c1,const MyComplex& c2) {
    double
        x1 = c1.getreal(),
        y1 = c1.getimag(),
        x2 = c2.getreal(),
        y2 = c2.getimag();
    MyComplex c(x1*x2-y1*y2,x1*y2+x2*y1);
    return c;
}
MyComplex operator/(const MyComplex& c1,const MyComplex& c2) {
    double
        x1 = c1.getreal(),
        y1 = c1.getimag(),
        x2 = c2.getreal(),
        y2 = c2.getimag(),
        len = c2.getmodel();
    double
        x = (x1 * x2 + y1 * y2)/len,
        y = (y1 * x2 - y2 * x1)/len;
    MyComplex c(x, y);
    return c;
}
MyComplex operator^(const MyComplex& c1,const  double& c2) {//ÊµÊýÃÝ
    double
        x1 = c1.getreal(),
        y1 = c1.getimag(),
        len = c1.getmodel(),
        ang = c1.getang();

    double
        len2 = pow(len, c2 / 2),
        ang2 = ang * c2,
        x = len2 * cos(ang2),
        y = len2 * sin(ang2);


    MyComplex c(x, y);
    return c;
}
MyComplex operator^(const MyComplex& c1,const MyComplex& c2) {//¸´ÊýÃÝ
    double
        x2 = c2.getreal(),
        y2 = c2.getimag(),

        len = c1.getlen(),
        ang = c1.getang();

    MyComplex Eh = Exp(x2 * ang);
    MyComplex Lenh = Exp(Ln(len) * c2);
    return Eh*Lenh;
}
MyComplex Exp(const MyComplex& z) {
    double
        len = exp(z.getreal()),
        imag=z.getimag();

    MyComplex c(len * cos(imag), len * sin(imag));
    return c;
}
MyComplex Ln( const MyComplex& z) {
    double x = log(z.getlen());
    MyComplex a(x,z.getang());
    return a;

}
ostream& operator <<(ostream& o,const MyComplex& c) {
    if (c.getreal() == 0 && c.getimag() == 0) { o << "0"; }
    else {
        o << c.getreal() << (c.getimag() > 0 ? "+" : "-") << fabs(c.getimag()) << "i";
    }
    return o;
}


