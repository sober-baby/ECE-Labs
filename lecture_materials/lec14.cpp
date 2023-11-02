//opeartor overloading
// we can also overload unary operators
Complex Complex::operator-()
{
    return Complex(-real, -imag);
}

// a = -b = b.operator-();

//Complex c;
//cout << c;
//overloading << >> operators  
//cout << a = <<(cout,a)
ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.real << " + " << c.imag << "i";
    if(c.imag < 0)
        out << c.real << " - " << -c.imag << "i";
    else
        out << c.real << " + " << c.imag << "i";
    return out; 
}

//consider cout << "result is" << c << "for sure";
//we want this to be equiv to
//cout << "result is";
//cout << c;
//cout << "for sure";

//Note:
//operator << can not be a member of any class
//because it would have to be a member function of ostream
//but you cannot change that class
//make operator << a friend of the class
           complex Complex{
            public;
            friend ostream &operator<<(ostream &, const Complex &);
           }

//operator =     a.operator=(b) <=> a = b; a = b = c;   

Complex& Complex::operator=(const Complex &y)
          {
              real = y.real;
              imag = y.imag;
              return *this; //pointer to the object itself
          }

//Note:
//the left hand side of a=b is being modified so opeartor = is not declared as const
//"this" is a ptr to obj on which method was invoked
//and hence "*this" is a reference to the object itself


