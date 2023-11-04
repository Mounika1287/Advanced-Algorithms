#include <iostream>
using namespace std;
// Structure of sparse 
struct SparseMat
{
    int rows, cols, count;
    int **values;
};
// Declare and initialize sparsematrix and return sparse matrix
SparseMat getSparseMat()
{
    int rows, cols;
    cout << "Total number of rows: ";
    cin >> rows;
    cout << "Total the number of columns: ";
    cin >> cols;
    SparseMat matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.count = 0;

    matrix.values = new int *[rows * cols];
    for (int i = 0; i < rows * cols; i++)
    {
        // create array to store non zero value 
        matrix.values[i] = new int[3]; 
    }
//return matrix
    return matrix;
}

void addNum(SparseMat &matrix, int row, int col, int num)
{
    if (num != 0)
    {
        matrix.values[matrix.count][0] = row;
        matrix.values[matrix.count][1] = col;
        matrix.values[matrix.count][2] = num;
        matrix.count++;
    }
}
// return number at a position
int getNum(SparseMat &matrix, int row, int col)
{
    int val = 0;
    for (int i = 0; i < matrix.count; i++)
    {
        if (matrix.values[i][0] == row && matrix.values[i][1] == col)
        {
            return matrix.values[i][2];
        }
    }
    return 0; 
}

int main()
{
    SparseMat matrix = getSparseMat();

    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            int value;
            cout << "Enter value at row " << i << " and column " << j << ": ";
            cin >> value;
            addNum(matrix, i, j, value);
        }
    }

    cout << "Sparse Matrix:" << std::endl;
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            cout << getNum(matrix, i, j) << " ";
        }
         cout << std::endl;
    }

    return 0;
}
