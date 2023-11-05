#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Class to represent a student
class Student
{
    private:
        // Private information about the student
        string StudentName;
        int RollNumber;
        int Age;

    public:
        // Nothing to do in the constructor
        Student()
        {

        }

        // Set the student data
        void setStudentData(string _studentName, int _rollNumber, int _age)
        {
            // Set each private value to be the corresponding input value
            StudentName = _studentName;
            RollNumber = _rollNumber;
            Age = _age;
        }

        // Getter functions for the private values
        string getStudentName()
        {
            return StudentName;
        }

        int getRollNumber()
        {
            return RollNumber;
        }

        int getAge()
        {
            return Age;
        }
};

int main()
{
    // Testing data
    string name = "Weston Shakespear";
    int roll = 5;
    int age = 25;

    // Output testing data
    cout << "Creating a student with the name '" << name;
    cout << "', the roll number '" << roll;
    cout << "', and the age of '" << age << "'" << endl;

    // This is the object
    Student weston;

    // Set the object values
    weston.setStudentData(name, roll, age);
    
    // Output object values using built in functions
    cout << "Created a student with the name '" << weston.getStudentName();
    cout << "', the roll number '" << weston.getRollNumber();
    cout << "', and the age of '" << weston.getAge() << "'" << endl;
}
