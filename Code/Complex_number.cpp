#include <iostream>
#include <cmath>

using namespace std ;

class Complex
{
    private :
        double real ;
        double imag ;
    public :
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
        Complex operator + (const Complex &c2) const ;
        Complex operator - (const Complex &c2) const ;
        Complex operator * (const Complex &c2) const ;
        Complex operator / (const Complex &c2) const ;

        Complex &operator += (const Complex &c2)
        {
            real += c2.real ;
            imag += c2.imag ;
            return *this ;
        }

        Complex &operator -= (const Complex &c2)
        {
            real -= c2.real ;
            imag -= c2.imag ;
            return *this ;
        }

        Complex &operator ++()
        {
            ++real ;
            ++imag ;
            return *this ;
        }



        void display() const ;

        double norm() const { return sqrt(real * real + imag * imag) ; }
};

Complex Complex::operator + (const Complex &c2) const
{
    return Complex(real + c2.real, imag + c2.imag) ;
}

Complex Complex::operator - (const Complex &c2) const
{
    return Complex(real - c2.real, imag - c2.imag) ;
}

Complex Complex::operator * (const Complex &c2) const
{
    return Complex(real * c2.real - imag * c2.imag, real * c2.imag + imag * c2.real) ;
}

Complex Complex::operator / (const Complex &c2) const
{
    double tmp = c2.real * c2.real + c2.imag * c2.imag ;
    return Complex((real * c2.real + imag * c2.imag) / tmp, (imag * c2.real - real * c2.imag) / tmp) ;
}

void Complex::display() const
{
    cout << "(" << real << ", " << imag << ")" << endl ;
}




int main()
{
    cout<<"nice to meet all of you"<<endl;
    cout<<"nice to meet all of you"<<endl;
    return 0;
}