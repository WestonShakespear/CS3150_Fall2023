#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Rectangle
{
    private:
        // Private book values
        float Width;
        float Height;

    public:

        // Empty constructor
        Rectangle()
        {
        }

        // Set the dimensions
        void setDimensions(float _width, float _height)
        {
            Width = _width;
            Height = _height;
        }

        // Calculate the area
        float area()
        {
            return Width * Height;
        }

        // Calcaulte the perimeter
        float perimeter()
        {
            return ( 2*Width ) + ( 2*Height );
        }  
};

int main()
{  
    // Test values
    float width = 6.5;
    float height = 7.6;

    // Output information
    cout << "Creating a rectangle with a width of '" << width << "' and a height of '" << height << "'" << endl;

    // Create the rectangle object
    Rectangle myRectangle;

    // Set the dimensions
    myRectangle.setDimensions(width, height);

    // Output the area
    cout << "The area of the rectangle is '" << myRectangle.area() << "'" << endl;

    // Output the perimeter
    cout << "The perimeter of the rectangle is '" << myRectangle.perimeter() << "'" << endl;
   

}
