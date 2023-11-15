#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::getline;
using std::string;

// Template function getMin
// Finds the minimum number
template <class T>
T getMin(T _first, T _second)
{
    // Define the return value to be the first number
    T minimum = _first;
    // If the second is lower than the first change the minimum
    if (_second < _first)  minimum = _second;
    // Return the minimum
    return minimum;
}

// Main function
int main()
{
    cout << endl;
    // Test with integers
    cout << "Test with two integers" << endl;
    int a = 1;
    int b = 4;
    cout << "Min of " << a << " and " << b << ": " << getMin(a, b) << endl;
    cout << "Min of " << b << " and " << a << ": " << getMin(b, a) << endl;
    cout << endl;

    // Test with floats
    cout << "Test with two floats" << endl;
    float c = -12.0f;
    float d = 400.6f;
    cout << "Min of " << c << " and " << d << ": " << getMin(c, d) << endl;
    cout << "Min of " << d << " and " << c << ": " << getMin(d, c) << endl;
    cout << endl;

    // Test with doubles
    cout << "Test with two doubles" << endl;
    double e = 100.0;
    double f = 40.6;
    cout << "Min of " << e << " and " << f << ": " << getMin(e, f) << endl;
    cout << "Min of " << f << " and " << e << ": " << getMin(f, e) << endl;
    cout << endl;
    return 0;
}
