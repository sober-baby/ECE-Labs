
// can be put in header files
#include <iostream>
class Person{
    private:
        string name;
        int age;
    public:
        static int personCount;
}

    Person (){
        name = "",
        age = 0;
        personCount++;
        cout << "Person constructor called" << endl;
    }

    ~Person(){ // personCount is glob variable, created before main is called, initialized to 0, 
              //only one instance regardless of number of person obj instantiated
              //can access as Person::personCount
        personCount--;
        cout << "Person destructor called" << endl;
    }

// Arrays int a[3]; a[0] = 1, a[1] = 2, a[2] = 3, a[-1] = 2
// a is a pointer in reality = int * a = &(a[0])
// you cannot modify a to point to something else
// cout << *a; -> 1
// cont << *(a+1); ->2

// Array of ptrs
// int * a[2];
// int b = 3;
// int c = 4;
// a[0] = &c;
// a[1] = &b;
// what is the value of a[0] -> the address of c
// what happens when a[0] = a[1], what happens when *a[0] = *a[1] "overwrites 3 with 3"
// Allocating array

int * a = new int[3]; // a is a pointer to the first element of the array
*(a+1) = 6;
//or
a[1] = 6

//2D arrays
int a[5][10];
// = array of 1DArrays
int x = a[2][3];
//when deleting dyn allocated array use delete []a; 

void f(int i; int j){
    int a[i][j]; //complier error
    int *a = new int[i][j]; 
}

//errors to avoid
     int *p;
     int y;
     y = *p; //p is not initialized

    int x = 3;
    int *p = new int;
    p = &x; //memory leak, p is pointing to something else, cannot delete x

    int *p = new int;
    delete p;
    delete p; //double free error

    int x = 4;
    int *p;
    p = &x;
    delete p; //delete non dyn allocated memory, crashes program  