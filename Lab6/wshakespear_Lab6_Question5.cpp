#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Employee
{
    private:
       string Name;
       int Id;
       string Department;

    public:
        // Constructor with values
        Employee(string _name, int _id, string _department)
        {
            Name = _name;
            Id = _id;
            Department = _department;

            cout << "Employee '" << Name << "' has been hired" << endl;
            cout << "Their id is '" << Id << "'" << endl;
            cout << "They work in the " << Department << " department" << endl;
        }

        // Destructor with message
        ~Employee()
        {
            cout << "Employee '" << Name << "' has left the company" << endl;
            cout << "Their id is '" << Id << "'" << endl;
            cout << "They worked in the " << Department << " department" << endl;
        }

        // Getter functions
        string getName()
        {
            return Name;
        }

        void printName()
        {
            cout << getName() << endl;
        }

        int getId()
        {
            return Id;
        }

        void printId()
        {
            cout << getId() << endl;
        }

        string getDepartment()
        {
            return Department;
        }

        void printDepartment()
        {
            cout << getDepartment() << endl;
        }


};

void createTestOne();
void createTestTwo();

int main()
{  
    // Run the test from functions so the destructor gets called
    createTestOne();
    createTestTwo();
}

void createTestOne()
{
    // Testing values
    string name = "Todd Peterson";
    int id = 4857623;
    string department = "Accounting";

    // Create the employee object
    Employee testEmployee(name, id, department);

    // Test the employee getters
    cout << "The employee name is " << testEmployee.getName() << endl;
    cout << "Name: ";
    testEmployee.printName();

    cout << "The employee id is " << testEmployee.getId() << endl;
    cout << "Id: ";
    testEmployee.printId();

    cout << "The employee department is " << testEmployee.getDepartment() << endl;
    cout << "Department: ";
    testEmployee.printDepartment();
    
}

void createTestTwo()
{
    // Testing values
    string name = "John Smith";
    int id = 294876;
    string department = "Shipping";

    // Create the employee object
    Employee testEmployee(name, id, department);

    // Test the employee getters
    cout << "The employee name is " << testEmployee.getName() << endl;
    cout << "Name: ";
    testEmployee.printName();

    cout << "The employee id is " << testEmployee.getId() << endl;
    cout << "Id: ";
    testEmployee.printId();

    cout << "The employee department is " << testEmployee.getDepartment() << endl;
    cout << "Department: ";
    testEmployee.printDepartment();
}
