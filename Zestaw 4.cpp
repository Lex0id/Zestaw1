#include <iostream>
using namespace std;
class ComplexNumber
{
private:
    double re;
    double im;
public:
    ComplexNumber(double re = 0, double im = 0)
    {
        this->re = re;
        this->im = im;
    }
    friend ostream& operator<<(ostream& output, const ComplexNumber& cn)
    {
        output << "(" << cn.re << ", " << cn.im << ")";
        return output;
    };
    
    friend istream& operator>>(istream& input, ComplexNumber& cn)
    {
        input >> cn.re >> cn.im ;
        return input;
    };
    
    friend bool operator==(const ComplexNumber& x, const ComplexNumber& y)
    {
        return ((x.re == y.re) && (x.im == y.im));
    };
    
    friend bool operator!=(const ComplexNumber& x, const ComplexNumber& y)
    {
        return !((x.re == y.re) && (x.im == y.im));
    };
    friend ComplexNumber operator+(const ComplexNumber& x, const ComplexNumber& y)
    {
        return (ComplexNumber(x.re + y.re, x.im + y.im));
    };
    friend ComplexNumber operator-(const ComplexNumber& x, const ComplexNumber& y)
    {
        return (ComplexNumber(x.re - y.re, x.im - y.im));
    };
    friend ComplexNumber operator*(const ComplexNumber& x, const ComplexNumber& y)
    {
        return (ComplexNumber((x.re*y.re) - (x.im*y.im), x.re*y.im + x.im*y.re));
    };
    friend ComplexNumber operator/(const ComplexNumber& x, const ComplexNumber& y)
    {
        return (ComplexNumber(((x.re*y.re) + (x.im*y.im))/(y.re * y.re + y.im * y.im), (x.im*y.re - x.re*y.im)/(y.re * y.re + y.im * y.im)));
    };
    ComplexNumber& operator = (ComplexNumber y)
    {
        this->re = y.re;
        this->im = y.im;
        return* this;
    };
    ComplexNumber& operator += (ComplexNumber y)
    {
        this->re += y.re;
        this->im += y.im;
        return* this;
    };
    ComplexNumber& operator -= (ComplexNumber y)
    {
        this->re -= y.re;
        this->im -= y.im;
        return* this;
    };
    ComplexNumber& operator *= (ComplexNumber y)
    {
        //x.re*y.im + x.im*y.re
        float im = this->im;
        float re = this->re;
        this->re =(this->re * y.re) - (this->im * y.im);
        this->im = (re * y.im) + (im * y.re);
        return* this;
    };
    ComplexNumber& operator /= (ComplexNumber y)
    {
        float im = this->im;
        float re = this->re;
        this->re = ((re*y.re) + (im*y.im))/(y.re * y.re + y.im * y.im);
        this->im = (im*y.re - re*y.im)/(y.re * y.re + y.im * y.im);
        return* this;
    };
    ComplexNumber& operator - ()
    {
        this->re = this->re*(-1);
        this->im = this->im*(-1);
        return* this;
    };
    ComplexNumber& operator ! ()
    {
        this->im = this->im*(-1);
        return* this;
    };
    ComplexNumber operator++(int)
    {
        ComplexNumber temp = *this;
        ++this->im;
        return temp;
    };
    ComplexNumber operator--(int)
    {
        ComplexNumber temp = *this;
        --this->im;
        return temp;
    };
    ComplexNumber operator++()
    {
        ComplexNumber temp = *this;
        ++this->re;
        return temp;
    };
    ComplexNumber operator--()
    {
        ComplexNumber temp = *this;
        --this->re;
        return temp;
    };
    //friend istream& operator>> (ostream& input, const ComplexNumber& cn);
};


int main()
{
    ComplexNumber a = ComplexNumber(1, 8);
    ComplexNumber b = ComplexNumber(2, 3);
    ComplexNumber c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a + b = "<< a + b<< endl<<endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a - b = "<< a - b<< endl<<endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a * b = "<< a * b<< endl<<endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a / b = "<< a / b<< endl<<endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a = b?: "<< (a == b) << endl<< endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a != b?: "<< (a != b) << endl<< endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a = b: "<< (a = b) << endl << endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a += b: "<< (a += b) << endl << endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a -= b: "<< (a -= b) << endl << endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a *= b: "<< (a *= b) << endl << endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "a /= b: "<< (a /= b) << endl << endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "-a: "<< -a << endl << endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "!a: "<< !a << endl << endl;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "postinkrementacja o 1 części zespolonej a: ";
    cout << a <<" "<< a++ <<" "<< a;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << endl;
    cout << endl;

    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "postdekrementacja o 1 części zespolonej a: ";
    cout << a <<" "<< a-- <<" "<< a;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << endl;
    cout << endl;

    cout << "postinkrementacja o 1 części rzeczywistej a: ";
    cout << a <<" "<< ++a <<" "<< a;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    cout << endl;
    cout << endl;

    cout << "default a: " << a << "b: "<< b <<endl;
    cout << "postdekrementacja o 1 części rzeczywistej a: ";
    cout << a <<" "<< --a <<" "<< a;
    a = ComplexNumber(1, 8);
    b = ComplexNumber(2, 3);
    c = ComplexNumber(0, 0);
    //c = (a * b);
    
    return 0;
}
