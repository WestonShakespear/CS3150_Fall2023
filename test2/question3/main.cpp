#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::getline;
using std::string;


class Time
{
    // Public variables and methods
    public:
        Time(int _hour = 0, int _minute = 0, int _second = 0)
        {
            checkTime(_hour, _minute, _second);
            hour = _hour;
            minute = _minute;
            second = _second;
        }
        void setTime(int _hour = 0, int _minute = 0, int _second = 0)
        {
            checkTime(_hour, _minute, _second);
            hour = _hour;
            minute = _minute;
            second = _second;
        }
        void checkTime(int &hour, int &minute, int &second)
        {
            if (hour > 23) hour = 23;
            if (minute > 59) minute = 59;
            if (second > 59) second = 59;
        }
        void printUniversal()
        {
            // Pad and print the hour
            if (hour < 10)  cout << "0";
            cout << hour << ":";

            // Pad and print the minute
            if (minute < 10) cout << "0";
            cout << minute << ":";

            // Pad and print the second
            if (second < 10) cout << "0";
            cout << second << endl;
        }
        void printStandard()
        {
            // Figure out AM or PM
            int output_hour = hour;
            string sector = "AM";
            if (hour > 11)
            {
                sector = "PM";
                output_hour -= 12;
            }
            // Output the time
            // Pad and print the hour
            if (output_hour < 10)  cout << "0";
            cout << output_hour << ":";

            // Pad and print the minute
            if (minute < 10) cout << "0";
            cout << minute << ":";

            // Pad and print the second
            if (second < 10) cout << "0";
            cout << second;

            // Output AM or PM
            cout << " " << sector <<endl;
        }
    // Private variables and methods
    private:
        int hour;
        int minute;
        int second;
};


// Main function
int main()
{
    cout << endl;
    
    // Create the object
    Time *time = new Time(1, 2, 3);

    // Test the standard print function
    cout << "The current standard time: ";
    time->printStandard();
    cout << endl;

    // Test setting the time
    time->setTime(20, 5, 6);

    // Ouput the changed time with both print functions
    cout << "The current standard time: ";
    time->printStandard();
    cout << "The current universal time: ";
    time->printUniversal();
    cout << endl;

    // Test the checkTime function
    time->setTime(56, 100, 100);
    cout << "The current universal time: ";
    time->printUniversal();
    cout << endl;
    return 0;
}
