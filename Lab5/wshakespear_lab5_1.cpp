
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // The current size of the array
    int size = 5;

    // The array
    int *arr = new int[size];

    // Current array index
    int index = 0;

    // Infinite loop
    while (1==1)
    {
        // Prompt the user for a number
        cout << "Enter a number (< 0 to exit): ";

        // Put the number in the array
        cin >> arr[index];

        // Break if it's less than 0
        if (arr[index] < 0)
        {
            break;
        }

        // Increment the index
        index++;

        // Resize the array if the next value will be too big
        if (index == size)
        {
            // Create a copy array
            int *copy = new int[size];
            // Fill this array
            for (int i = 0; i < size; i++)
            {
                copy[i] = arr[i];
            }
            // Delete the old array
            delete[] arr;

            // Store the old size and get the new size
            int old_size = size;
            size *= 2;

            // Init the array with the new size
            arr = new int[size];
            // Fill the new array with the copied data
            for (int i = 0; i < old_size; i++)
            {
                arr[i] = copy[i];
            }
        }
        
    }

    // Output data and sum
    int sum = 0;

    cout << endl;
    cout << "{ ";
    for (int i = 0; i < index; i++)
    {
        cout << arr[i] << ", ";
        sum += arr[i];
    }
    cout << " }" << endl;

    // Calculate the average using the index
    float average = sum / index;

    // Output the sum
    cout << "The sum of the numbers is: " << sum << endl;

    // Output the average
    cout << "The average of the numbers is: " << average << endl;
    return 0;
}