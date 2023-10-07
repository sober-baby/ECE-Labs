#include <iostream>
class Complex
{
private:
    double real;
    double imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }
    double getReal() { return real; }
    double getImag() { return imag; }

}

int
main()
{
    Complex a(1, 1);
    Complex b(2, 2);
    Complex c;
    c = a + b;
    cout << a.getReal() << " " << a.getImag() << endl;
    // Operator overloading allows just that
}

// How to view operator
//  x + y <=> +(x,y)
//  x - y <=> -(x,y)
//  x * y <=> *(x,y)

Complex opearator+ (Complex x, Complex y)
{ // opeartor+ is defined outside the class, becuase of this we must call get real and get imag
    return Complex(x.getReal() + y.getReal(), x.getImag() + y.getImag());
}

// solution #2 passing in by reference
Complex opearator+(const Complex &x, const Complex &y)
{ // const specifies argument cannot be changed, same memory as you pass in the address
    return Complex(x.getReal() + y.getReal(), x.getImag() + y.getImag());
}

// solultion #3 Make operator a friend of the class
class Complex
{
public:
    friend Complex operator+(const Complex &, const Complex &);
} 

Complex operator(const Complex &x, const Complex &y)
{ // const specifies argument cannot be changed, same memory as you pass in the address
    return Complex(x.real + y.real, x.real + y.real);
}

// solution #4 Define operator+ as a member function 
class Complex{
    public:
        Complex operator+(const Complex &)const; // const at the end means this function cannot change the object
    // c = a + b is invoked on obj a with one arg named b ||| -> c = a.operator+(b)
}

// As a member function
Complex Complex::operator+(const Complex &y)const{
    return Complex(real + y.real, imag + y.imag); //refers to member datra of obj on which fct was invoked
}

// String s1 = "Hello";
// String s2 = "World";
//cout << s1 + s2 << endl; // prints "HelloWorld"
//s3 = s1 + s2; // s3 = "HelloWorld"

//How to a == b?
// bool operator==(const Complex& y)const{
    // return real == y.real && imag == y.imag;
//}
