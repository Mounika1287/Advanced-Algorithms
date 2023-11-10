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
    int maxRows;
    int maxCols;
    Element** head;
//constructor
public:
    Matrix(int row, int column){
        maxRows = row;
        maxCols = column;
        head = new Element*[maxRows]();
    }

    void AddElement(int value, int row, int col) {

        Element* new_Element = new Element(value, row, col);
        //If first Node
        if (head[row]) {
            Element* current = head[row];
            while (current->next) {
                current = current->next;
            }
            current->next = new_Element; 
        } else { //Add node at the end of the list
            head[row] = new_Element;
        }
    }

    void PrintMatrix() {
        for (int row = 0; row < maxRows; ++row) {
            Element* current = head[row];
            int rowElements[maxCols] = {0};
            //collect all maxRows into row elements into rowElements
            while (current) {
                rowElements[current->col] = current->value;
                current = current->next;
            }
            //print all collected elements
            for (int col = 0; col < maxCols; ++col) {
                cout << rowElements[col] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int maxRows, maxCols;
    cout << "Enter no of rows: ";
    cin >> maxRows;
    cout << "Enter no of columns: ";
    cin >> maxCols;

    Matrix matrix(maxRows, maxCols);

    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
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
