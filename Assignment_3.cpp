#include <iostream>
#include <stdexcept>

using namespace std;
//class Element as an element in sparse matrix
class Element {
public:
    int value; 
    int row;
    int col;
    Element* next;
//constructor
    Element(int val, int rowNo, int column){
        value = val;
        row   = rowNo;
        col   = column; 
        next  = nullptr;
    }
};

class Matrix {
private:
    int rows;
    int cols;
    Element** head;
//constructor to  initialize values
public:
    Matrix(int row, int column){
        rows = row;
        cols = column;
        head = new Element*[rows]();
    }

void AddElement(int value, int row, int col) {
    Element* new_Element = new Element(value, row, col);
     //If first Node
     if (!head[row]) {
            head[row] = new_Element;
      } else { //Add node at the end of the list
            Element* current = head[row];
            while (current->next) {
                current = current->next;
            }
            current->next = new_Element; 
        }
    }

    void PrintMatrix() {
        for (int row = 0; row < rows; ++row) {
            Element* current = head[row];
            int rowElements[cols] = {0};
            //collect all rows into row elements into rowElements
            while (current) {
                rowElements[current->col] = current->value;
                current = current->next;
            }
            //print all collected elements
            for (int col = 0; col < cols; ++col) {
                cout << rowElements[col] << " ";
            }
            cout << std::endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter no of rows: ";
    cin >> rows;
    cout << "Enter no of columns: ";
    cin >> cols;

    Matrix matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cout << "Enter the value at row " << i << " and column " << j << ": ";
            cin >> value;
            if (value !=0){
                matrix.AddElement(value, i, j);
            }
        }
    }

    cout << "-----------Sparse Matrix-----------\n";
    matrix.PrintMatrix();

    return 0;
}
