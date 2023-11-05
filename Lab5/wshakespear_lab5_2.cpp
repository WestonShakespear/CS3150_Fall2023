#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // The amount of values to calculate
    int amount = 20;

    // The array to store the values
    int *arr = new int[amount];

    // The first two are 1
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i < amount; i++)
    {
        // The current value is the sum of the two previous
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    // Output information
    cout << "The first " << amount << " values of the fibonacci sequence are:" << endl;

    // Outuput the sequence
    for (int i = 1; i <= amount; i++)
    {
        cout << arr[i-1] << "  ->  ";
        if (i % 4 == 0) cout << endl;
    }

    cout << endl;
    // Delete the manually allocated memory
    delete[] arr;

    return 0;
}
