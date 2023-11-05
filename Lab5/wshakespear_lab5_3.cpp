// Import math with legacy support
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

float calculateArea(float radius);

int main()
{
    // Testing numbers
    float a = 1.0f;
    float b = 5.4f;
    float c = 9.5f;

    // Test and output
    cout << "The area of a circle with a radius of " << a << " is " << calculateArea(a) << endl;
    cout << "The area of a circle with a radius of " << b << " is " << calculateArea(b) << endl;
    cout << "The area of a circle with a radius of " << c << " is " << calculateArea(c) << endl;

    return 0;
}

float calculateArea(float radius)
{
    // Return pi r squared
    return M_PI * radius * radius;
}
