//Recall: inheritance

//derive class reveives all member variables and functions from base class
//derived class can extended base class with its own member vars and functions 
//derived calss can be used just like normal calss
//derived class D overrides a function of B
D d;
B b;
d.f();
B* bp = &d; //pointer to base class

B: boo(int i); //base class
D: boo(int i); //overrides B::boo(int i) 
//D d; //d.foo(3) -> D's boo(i) is invoked

//In contract to overloaded functions
B:foo(int i); //same name
D.foo(double d); //different parameters
D d;
d.foo(3); //invokes B::foo(int i)
d.foo(3.0); //invokes D::foo(double d)

//another class hierarchy: c++ iostreams 
//IOS-base -> IOS -> istream, ostream
//istream -> ifstream    ostream -> ofstream
//iostream is inherited from istream and ostream, multiple inheritance

//Data protection
//derived class cannot access private member variables of base class
// we want to be able to change private part of base class with out affecting derived class
//this can be restrictive so c++ introduces new access protection mechanism "protected"

class Class Name{
    public:
        //can be accessed by anyone
    protected:
        //can only by accessed by derived classes
    private:
        //can only be accessed by this class
};

//Accessing private members
class Base{
    private:
        int x;
    public:
        set(int_a){a=-a;}
        print(){cout << "Base a=" << a << endl;}

}

class Derived: public Base{
    private:
        int;    
    public:
        set(int_a, int_b){Base::set(_a); b=_b;}
        print(){Base::print(); cout << "Derived b=" << b << endl;}
}

//derived classes do not inherit 
//1. constructors
//2. copy constructors
//3. destructors
//4. overloaded assignment operators

// base <- derived Derived::Derived(); ->call constructor of base
//Derived:: Derived(.....): Base(....){} //call constructor of base
//code to init the added member data
//This code is executed after call Base()

//d   base member data and derived member data
//         |(base)       