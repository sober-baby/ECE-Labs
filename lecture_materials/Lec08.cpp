/*
Constructors:

What if we declare a variable, Person x; ,and never call setAge() method within it?

x.age will be uninitialized (has random numbers in the memory)

Constructors are special methods that are called automatically when an object is instantiated. They are never
explicitly invoked by any function.

They have the same name as the class. They return no value, has no return type, not even void.
They must be public

To define a constructor for class Person:
- in Person.h: add public method Person()

class Person {
    private:
        string name;
        int age;
    public:
        void setName(string)
    

    Public();
}

- in person.cpp, add:

Person:: Person() {
    name = "";
    age = 0;
}

With the constructor defined,name, age will also be defined.

Person *pp; Person() is not called
Reason: we are defining a pointer, not a Person

pp = new Person; // new returns a pointer to pp, but after it is instantiated by constructor function
*/


/*
Multiple Constructors
- Sometimes we wish to initialize objects differently
- We can define different constructors
- They all have the same name but have different parameter signatures

// Different Parameter Signatures
Person:: Person (string n) {
    name = n;
    age = 0;
}

Person:: Person (string n, int a) {
    name = n;
    age = a;
}

- Which constructor is called is determined by argument types when instantiated

Person x; // Person() is called
Person y("Suzy"); // Person(string n) is called
Person *pp = new Person("Bill", 5) // Person(string n, int a) is called

Having different function with the same name but different argument signature is called function overloading.
(Basically the above 3 constructors)

// Always should have it, but its not an error not to have it
For any class A, its "default constructor" is A(); which is generated for you if you dont define any constructors

***************If you define a constructor, say A(int), then no default constructor is generated.**************
***************So if you dont explicitly define a default constructor, code will cause an error.***************

Example:
A x; // will cause an error

*/

/*
Destructors
- Complement of constructors

Clean up stuff when object is destroyed
called automatically when object is destroyed
name of destructor

Person:: ~Person();
*/