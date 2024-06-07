#include<iostream>
using namespace std;

class SparseMatrix {
    int matrix[100][100], n_rows, n_cols;
    int sparse[100][3];
public:
    void get_matrix();
    void create_sparsematrix();
    void display();
};

void SparseMatrix::get_matrix() {
    cout << "Enter the number of rows = ";
    cin >> n_rows;
    cout << endl << "Enter the number of columns = ";
    cin >> n_cols;

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            cout << "Enter element [" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
        }
    }
    create_sparsematrix();
}

void SparseMatrix::create_sparsematrix() {
    int k = 1;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = n_rows;
    sparse[0][1] = n_cols;
    sparse[0][2] = k - 1;
}

void SparseMatrix::display() {
    cout << "  ROWS  COLUMNS  VALUES";
    for (int i = 0; i <= sparse[0][2]; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << "  " << sparse[i][j];
        }
    }
}

int main() {
    SparseMatrix m;
    int ch;
    do {
        cout << endl<<"1 for get matrix" << endl << "2 for display" << endl << "3 for exit" << endl;
        cout<<"Enter your choice=";
        
        cin >> ch;
        switch (ch) {
        case 1:
            m.get_matrix();
            break;
        case 2:
            m.display();
            break;
        case 3:
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    } while (ch != 3);

    return 0;
}

