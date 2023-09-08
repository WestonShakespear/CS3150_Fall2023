#include <stdio.h>

void swap(int *a, int *b);
void arrayOp(int array[], int size, int *minimum, int *maximum, int *average);

void main()
{
    printf("Part Two:\n");


    //----------------------------------SECTION 1-----------------------------//

    printf("Create a C program that defines a function to swap two integers\n");

    // Test 1
    int a = 2;
    int b = 3;

    printf("Integer A is %d and Integer B is %d\t", a, b);
    swap(&a, &b);
    printf("Integer A is %d and Integer B is %d\n\n", a, b);
    
    // Test 2
    a = 4;
    b = 7;

    printf("Integer A is %d and Integer B is %d\t", a, b);
    swap(&a, &b);
    printf("Integer A is %d and Integer B is %d\n\n", a, b);

    // Test 3
    a = 402;
    b = 730;

    printf("Integer A is %d and Integer B is %d\t", a, b);
    swap(&a, &b);
    printf("Integer A is %d and Integer B is %d\n\n", a, b);

    // Test 4
    a = -999;
    b = 123;

    printf("Integer A is %d and Integer B is %d\t", a, b);
    swap(&a, &b);
    printf("Integer A is %d and Integer B is %d\n\n", a, b);


    //----------------------------------SECTION 2-----------------------------//

    printf("Write a C program that uses functions to perform the following ");
    printf("operations on an array of integers\n");

    int ar1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ar2[] = {203, 485, 2283, 291, 4854, 5849, 345, 254, 554};
    int ar3[] = {4, 66, 79, 24, 36, 34, 22, 334, 573};
    int ar4[] = {56, 33, 57, 89, 23, 32, 33, 67, 35};


    // Test 1
    int size = sizeof(ar1) / sizeof(ar1[0]);
    printf("The array contains {");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", ar1[i]);
    }
    printf("}\n");

    int minimum = 0;
    int maximum = 0;
    int average = 0;

    arrayOp(ar1, size, &minimum, &maximum, &average);

    printf(
        "\tThe minimum is: %d\n\tThe maximum is: %d\n\tThe average is: %d\n\n",
        minimum,
        maximum,
        average);

    // Test 2
    size = sizeof(ar2) / sizeof(ar2[0]);
    printf("The array contains {");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", ar2[i]);
    }
    printf("}\n");

    minimum = 0;
    maximum = 0;
    average = 0;

    arrayOp(ar2, size, &minimum, &maximum, &average);

    printf(
        "\tThe minimum is: %d\n\tThe maximum is: %d\n\tThe average is: %d\n\n",
        minimum,
        maximum,
        average);

    // Test 3
    size = sizeof(ar3) / sizeof(ar3[0]);
    printf("The array contains {");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", ar3[i]);
    }
    printf("}\n");

    minimum = 0;
    maximum = 0;
    average = 0;

    arrayOp(ar3, size, &minimum, &maximum, &average);

    printf(
        "\tThe minimum is: %d\n\tThe maximum is: %d\n\tThe average is: %d\n\n",
        minimum,
        maximum,
        average);

    // Test 4
    size = sizeof(ar4) / sizeof(ar4[0]);
    printf("The array contains {");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", ar4[i]);
    }
    printf("}\n");

    minimum = 0;
    maximum = 0;
    average = 0;

    arrayOp(ar4, size, &minimum, &maximum, &average);

    printf(
        "\tThe minimum is: %d\n\tThe maximum is: %d\n\tThe average is: %d\n\n",
        minimum,
        maximum,
        average);

}



// Create a C program that defines a function to swap two integers. The program 
// should include:
//     - A function to perform the swap.
//     - A function prototype.
//     - A main function that demonstrates the swap by taking two integers 
//       as input and displaying the swapped values.
void swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}

// Write a C program that uses functions to perform the following operations
// on an array of integers:
//     - Calculate the sum of all elements.
//     - Find the maximum and minimum values.
//     - Calculate the average of the elements.
//     - Display these results in the main function.
void arrayOp(int array[], int size, int *minimum, int *maximum, int *average)
{
    *minimum = __INT_MAX__;
    *maximum = -1 * __INT_MAX__;

    for (int i = 0; i < size; i++)
    {
        *average += array[i];

        if (array[i] < *minimum)
        {
            *minimum = array[i];
        }
        else if (array[i] > *maximum)
        {
            *maximum = array[i];
        }
    }
    *average = *average / size;
}
