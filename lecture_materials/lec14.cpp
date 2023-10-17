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

cout << a << b << c;
// write a hello world program
// write a program that reads in a string and prints it out
// write a program that reads in a string and prints out the number of characters in the string
// write a program that reads in a string and prints out the number of words in the string
// write a program that reads in a string and prints out the number of vowels in the string
cout << "hello world" << endl;
string s;
cin >> s;
cout << s << endl;
cout << s.length() << endl;
int count = 0;
for(int i = 0; i < s.length(); i++)
{
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        count++;
}
cout << count << endl;
// write a program that does ai chess
// write a program that does tic tac toe
int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int *p = &a;
    int *q = &b;
    int *r = &c;
    int *s = &d;
    int *t = &a;
    int *u = &b;
    int *v = &c;
    int *w = &d;
    int *x = &a;
    int *y = &b;
    int *z = &c;
    int *aa = &d;
    int *ab = &a;
    int *ac = &b;
    int *ad = &c;
    int *ae = &d;
    int *af = &a;
    int *ag = &b;
    int *ah = &c;
    int *ai = &d;
    int *aj = &a;
    int *ak = &b;
    int *al = &c;
    int *am = &d;
    int *an = &a;
    int *ao = &b;
    int *ap = &c;
    int *aq = &d;
    int *ar = &a;
    int *as = &b;
    int *at = &c;
    int *au = &d;
    int *av = &a;
    int *aw = &b;
    int *ax = &c;
    int *ay = &d;
    int *az = &a;
    int *ba = &b;
    int *bb = &c;
    int *bc = &d;
    int *bd = &a;
    int *be = &b;
    int *bf = &c;
    int *bg = &d;
    int *bh = &a;
    int *bi = &b;
    int *bj = &c;
    int *bk = &d;
    int *bl = &a;
    int *bm = &b;
    int *bn = &c;
    int *bo = &d;
    int *bp = &a;
    int *bq = &b;
    int *br = &c;
    int *bs = &d;
    int *bt = &a;
    int *bu = &b;
    int *bv = &c;
    int *bw = &d;
    int *bx = &a;
    int *by = &b;
    int *bz = &c;
    int *ca = &d;
    int *cb = &a;

    int *cc = &b;
}

// write a program that can hack compters
int 