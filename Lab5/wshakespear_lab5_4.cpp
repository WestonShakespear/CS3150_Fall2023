#include <iostream>

#define CUBE(n) ( n * n * n )

using std::cout;
using std::endl;

inline int cube(int number);

int main()
{
    // Test inline
    int a = 6;
    int b = 7;

    cout << "The inline cube function for " << a << " is " << cube(a) << endl;
    cout << "The inline cube function for " << b << " is " << cube(b) << endl;


    // Test macro
    double c = 6;
    bool d = true;

    cout << "The macro cube function for " << c << " is " << CUBE(c) << endl;
    cout << "The macro cube function for " << d << " is " << CUBE(d) << endl;


    // Test macro

    return 0;
}

inline int cube(int number)
{
    return number * number * number;
}
