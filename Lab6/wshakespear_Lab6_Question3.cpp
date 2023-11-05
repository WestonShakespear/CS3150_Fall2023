#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Book
{
    private:
        // Private book values
        string Title;
        string Author;
        int Year;

    public:

        // Empty constructor
        Book()
        {

        }

        // Set the book information
        void setBookInfo(string _title, string _author, int _year)
        {
            Title = _title;
            Author = _author;
            Year = _year;
        }

        // Return the book information as a formatted string
        string getBookInfo()
        {
            string begin = Title + Author;
            string end = std::to_string(Year);
            return begin + " " + end;
        }

        // Function to test if published before a certain year
        bool isPublishedBefore(int _year)
        {
            // Return the logical expression of whether or not the 
            // Year is less than the input _year
            return Year < _year;
        }
      

};

int main()
{
    // Test values
    string title = "Introduction to Watching Paint Dry";
    string author = "Weston Shakespear";
    int year = 2034;

    // Output information
    cout << "Creating the book by '" << author << "' called '" << title << "' and released in " << year << endl;

    // Create the book object
    Book myBook;

    // Set the book info
    myBook.setBookInfo(title, author, year);

    // output the book string
    cout << "The book string is: '" << myBook.getBookInfo() << "'" << endl;

    // Test the book published before function
    year += 5;
    if (myBook.isPublishedBefore(year))
    {
        cout << "The book was published before " << year << endl;
    }
    else
    {
        cout << "The book was not published before " << year << endl;
    }

}
