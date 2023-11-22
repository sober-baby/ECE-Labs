//pointer to functions
T a[10]; //pointer to first element of array
T*  b = a; //valid, 
T x=b[3]; //valid, x is a copy of a[3]

//pointer to function is the address of the first instruction of the function
//E.g. Given a function:
RT fct (ArgType arg){ ... }
//Address of function fct() is &fct 
//to declear a var that holds a ptr to this function
RT (*f)(ArgType arg); //*f name of *variable* that holds a ptr to a function with 1 argument of type ArgType and return type RT
*f = &fct; //assign address of fct to f

//                    shape
//                 /     |      \
//              rect   circle   squigly
//                                  \
//                                  function that can parse squigly input returns a ptr to a newly instantiated squigly obj;
// Shape DB   arry of pters to shapes 
// method - register NewShape(string name, pointer to a parse function specific to squigly)
//                              "Squigly"   ptr to Squigl's parse fct
// >create squigly 3 4 1 2 6

class Polygon{
    protected:
        double width, height;
    public:
        void set_values(double a, double b){width=a; height=b;}
};

class Recetangle: public Polygon{
    public double area(){return width*height;}
};

class Triangle: public Polygon{
    public double area(){return width*height/2;}
};

Rectangle rect;
Triangle trgl;
Polygon * ppoly1 = &rect;
Polygon * ppoly2 = &trgl;
ppoly1->set_values(1,2);
ppoly2->set_values(3,4);
cout << rect.area() << endl; //2
cout << trgl.area() << endl; //6

cout << ppoly1->area() << endl; //compile error
cout << ppoly2->area() << endl; //compile error

//virtual functions
Modify class Polygon{
    protected:
        double width, height;
    public:
        void set_values(double a, double b){width=a; height=b;}
        virtual double area(){return 0;}
}


// I cann now
cout << ppoly1->area() << endl; 
        //ptr to polygon but really points to rectangle a call is made to rectangles area()

        
