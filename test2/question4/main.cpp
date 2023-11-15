#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::getline;
using std::string;
using std::to_string;

// Matrix Class
class Matrix
{
    // Public variables and functions
    public:
        // Constructor, default size is 3x3
        Matrix(int sizeX = 3, int sizeY = 3)
        {
            // Set private variables with input variables
            SizeX = sizeX;
            SizeY = sizeY;
            Length = SizeX * SizeY;

            // Call public functions to create the matrix and set all zeros
            this->init();
            this->clear();
        }
        // Function to create the matrix
        void init()
        {
            Mat = new int[Length];
        }
        // Function to set all entries in matrix to zero
        void clear()
        {
            // Iterate over the y axis of matrix
            for (int a = 0; a < SizeY; a++)
            {
                // Iterate over x axis of matrix
                for (int b = 0; b < SizeX; b++)
                {
                    // Calculate the index and set to 0
                    Mat[(a*SizeY) + b] = 0;
                }
            }
        }
        // Function to get an entry in the matrix
        int get(int iX, int iY)
        {
            // Return nothing if the index is out of bounds on x or y
            if (iX > SizeX || iX < 0 || iY > SizeY || iY < 0)
            {
                return 0;
            }
            // Return the index from the matrix
            return Mat[(iY*SizeY) + iX];
        }
        // Function to set an entry in the matrix
        void set(int iX, int iY, int value)
        {
            // Return nothing if the index is out of bounds on x or y
            if (iX > SizeX || iX < 0 || iY > SizeY || iY < 0)
            {
                return;
            }
            // Set the calculated index in the matrix to the value
            Mat[(iY*SizeY) + iX] = value;
        }
        // Static function to check if two matrices are the same size
        static bool checkMatrixSize(Matrix* a, Matrix* b)
        {
            // Check for the same size in x and in y and return that bool
            return (a->sizeX() == b->sizeX()) && (a->sizeY() == b->sizeY());
        }
        // Static function to add two matrices
        static Matrix* add(Matrix* a, Matrix* b)
        {
            // Check to make sure the matrices are the same size
            // If they aren't return an empty default matrix
            if (!checkMatrixSize(a, b)) return new Matrix();
            // Create the return matrix
            Matrix* returnMat = new Matrix(a->sizeX(), a->sizeY());
            // Iterate over the y axis
            for (int y = 0; y < returnMat->sizeY(); y++)
            {
                // Iterate over the x axis
                for (int x = 0; x < returnMat->sizeX(); x++)
                {
                    // Use the individual matrices get functions
                    // Add the two values and set that in the return matrix
                    returnMat->set(x, y, a->get(x, y) + b->get(x, y));
                }
            }
            // Return the result matrix
            return returnMat;
        }
        // Static function to subtract two matrices
        static Matrix* subtract(Matrix* a, Matrix* b)
        {
            // Check to make sure the matrices are the same size
            // If they aren't return an empty default matrix
            if (!checkMatrixSize(a, b)) return new Matrix();
            // Create the return matrix
            Matrix* returnMat = new Matrix(a->sizeX(), a->sizeY());
            // Iterate over the y axis
            for (int y = 0; y < returnMat->sizeY(); y++)
            {
                // Iterate over the x axis
                for (int x = 0; x < returnMat->sizeX(); x++)
                {
                    // Use the individual matrices get functions
                    // Subtract the two values and set that in the return matrix
                    returnMat->set(x, y, a->get(x, y) - b->get(x, y));
                }
            }
            // Return the result matrix
            return returnMat;
        }
        // Static function to multiply two matrices
        static Matrix* multiply(Matrix* a, Matrix* b)
        {
            // Check that matrix a's sizeX is the same as b's sizeY
            // and that matrix a's sizeY is the same is b's sizeX
            // If it isn't return an empty default matrix
            if ((a->sizeX() != b->sizeY()) && (a->sizeY() != b->sizeX()))
            {
                return new Matrix();
            }
            // Init the result matrix
            Matrix* returnMat = new Matrix(a->sizeY(), a->sizeY());

            // Iterate through the y axis size of the result matrix
            for (int y = 0; y < a->sizeY(); y++)
            {
                // Iterate through the x axis size of the result matrix
                for (int x = 0; x < b->sizeX(); x++)
                {
                    // Init the value to set
                    int value = 0;
                    // Iterate through the columns and rows for the dot product
                    for (int aX = 0; aX < a->sizeX(); aX++)
                    {
                        // Add this result to the value
                        value += a->get(aX, y) * b->get(x, aX);
                    }
                    // Set the value in the result matrix
                    returnMat->set(x, y, value);
                }
            }
            // Return the result matrix
            return returnMat;
        }
        // This function returns a string representing the matrix
        string toString()
        {
            // This will be the returned string
            string output = "";
            // Iterate over the y axis
            for (int a = 0; a < SizeY; a++)
            {
                // Add the beginning of the line to output
                output += "[ ";
                // Iterate over the x axis
                for (int b = 0; b < SizeX; b++)
                {
                    // Add the current entry to output
                    output += to_string(Mat[(a*SizeY) + b]) + " ";
                }
                // Add the end of the line to output
                output += "]\r\n";
            }
            // Return the output string
            return output;
        }
        
        // Getter functions for private variables
        int* mat() { return Mat; }
        int length() { return Length; }
        int sizeX() { return SizeX; }
        int sizeY() { return SizeY; }
    
    // Private variables 
    private:
        int* Mat;
        int Length;
        int SizeX;
        int SizeY;
};


// Main function
int main()
{
    // Test the simple functions
    int sizeX = 4;
    int sizeY = 4;

    Matrix* matrix = new Matrix(sizeX, sizeY);

    cout << endl;
    cout << "Testing basic matrix functionality" << endl;
    cout << "-------------------" << endl;
    
    cout << "Matrix length: " << matrix->length() << endl;
    cout << "Matrix: " << endl << matrix->toString() << endl;

    int y = 0;
    cout << "Setting each value: " << endl;
    for (int a = 0; a < sizeY; a++)
    {
        for (int b = 0; b < sizeX; b++)
        {
            matrix->set(b, a, y++);
        }
    }

    cout << "Matrix: " << endl << matrix->toString() << endl;

    cout << "Getting each value: " << endl;
    for (int a = 0; a < sizeY; a++)
    {
        for (int b = 0; b < sizeX; b++)
        {
            cout << matrix->get(b, a) << " ";
        }
    }
    cout << endl;

    // Test addition
    cout << "Testing addition" << endl;
    cout << "-------------------" << endl;
    Matrix* matrixA = new Matrix(sizeX, sizeY);
    Matrix* matrixB = new Matrix(sizeX, sizeY);

    y = 0;
    cout << "Setting each value: " << endl;
    for (int a = 0; a < sizeY; a++)
    {
        for (int b = 0; b < sizeX; b++)
        {
            matrixA->set(b, a, y++);
            matrixB->set(b, a, y++);
        }
    }
    cout << matrixA->toString() << endl;
    cout << "+" << endl;
    cout << matrixB->toString() << endl;

    Matrix* matrixC = Matrix::add(matrixA, matrixB);
    cout << "=" << endl;
    cout << matrixC->toString() << endl;


    // Test subtraction
    cout << "Testing subtraction" << endl;
    cout << "-------------------" << endl;
    
    cout << matrixA->toString() << endl;
    cout << "-" << endl;
    cout << matrixB->toString() << endl;

    Matrix* matrixD = Matrix::subtract(matrixA, matrixB);
    cout << "=" << endl;
    cout << matrixD->toString() << endl;

    // Test multiplication
    cout << "Testing multiplcation" << endl;
    cout << "-------------------" << endl;
    Matrix* matrixE = new Matrix(3, 2);
    Matrix* matrixF = new Matrix(2, 3);

    y = 0;
    cout << "Setting each value: " << endl;
    for (int a = 0; a < sizeY; a++)
    {
        for (int b = 0; b < sizeX; b++)
        {
            matrixE->set(a, b, y++);
            matrixF->set(b, a, y++);
        }
    }
    
    cout << matrixE->toString() << endl;
    cout << "*" << endl;
    cout << matrixF->toString() << endl;

    Matrix* matrixG = Matrix::multiply(matrixE, matrixF);
    cout << "=" << endl;
    cout << matrixG->toString() << endl;

    return 0;
}
