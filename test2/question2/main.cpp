#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::getline;
using std::string;

// This is the gradebook class
class GradeBook
{
    // Public methods and variables
    public:
        // Default constructor, does nothing
        GradeBook()
        {
        }
        // Display a message for the course
        void displayMessage(string course)
        {
            // Set the current course to the input course
            current_course = course;
            // Output the welcome message
            cout << "Thank you for joining '";
            cout << current_course;
            cout << "', we hope you have a good semester" << endl;
        }

    // Private variables
    private:
        string current_course;

};

// Main function
int main()
{
    cout << endl;
    // Create a test gradebook
    GradeBook fallSemester;

    // Test the displayMessage function
    fallSemester.displayMessage("CCET4690");

    cout << endl;
    return 0;
}
