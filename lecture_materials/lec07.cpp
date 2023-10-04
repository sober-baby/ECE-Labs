// Recall structs

    struct person
    {
        string name;
        int age;
        double height;
    };

// allows def of new data types
// organizes related data elements into one unit
// struct def does not involve allocation of memory
// emeory is only allocated when struct is instantiated through the use of a variable

// struct variables
    person p1;
    person p2;
//element of struct are accessed with '.' operator
    p1.name = "John";
    p1.age = 21;
    p1.height = 1.8;
// or if dynamic
    person *pp = malloc(sizeof(person));
    pp->name = "John";
    pp->age = 21;
    pp->height = 1.8;
// classes expands structs by including both
// data and functions
// a class is also a datatype

class Person{
  private:  
    string name;
    int age;
    void setName(string); // refer to as methods or function methods
  public:
    void setAge(int);
    string getName();
    int getAge();
};

//why do this?
// - allows def of new datatypes
// -groups all fcts that access class data type

//Access controls
//restricts what can access what
//private: only members of the class can access
//public: anyone can access
//default: same as private
//good practice to make all data members private - encapsulation or data hiding

//code outside the class doesnt need to know how name is defined and doesnt need to (can be string, chatp[], (fname + lname), etc)
//allows us to change the implementation without affecting the code outside the class (as long as the interface is the same)
// -> limits code changes reguires -> reduces # errors
//increase productivity

//Invoke member functions
//member functions are invoked through an object
//object are created ("instantiated") when a var of the class type is declared (or dynamically allocated)

person *pp = new person; //instantiate a new person object
person x;
person y;

//methods are invoked through the '.' operator (or -> if dynamic)

    #include "Person.h"
    int main(){
        Person x, y;
        
    }

