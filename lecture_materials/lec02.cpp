#include <iostream>
using namespace std;
//everything in cpp is pass by value
//memory in function gets freed after the call
int addition (int a, int b)
{
  int r;
  r=a+b;
  return r;
}

int main ()
{
  int z;
  z = addition (5,3);
  cout << "The result is " << z;
}


// Pass by value vs Pass by pointer
    void bumpMark(int* mark) {
        if(*mark < 90)
            *mark += 10;
    }

int main() {
    int mark = 85;
    bumpMark(&mark);
    cout << mark << endl;
    return 0;
}

// Pass by reference

void bumpMark(int& mark) { // & means pass by reference. Referece is like an alias or alternate name to an existing variable
                            // reference is safter but less powerful
                            // reference cannot be reassigned, has to be assigned at initialization
                            // cannot be null
    if(mark < 90)
        mark += 10;
}