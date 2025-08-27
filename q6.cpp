#include<iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, terms;
    Triplet *data;
};

SparseMatrix createMatrix() {
    SparseMatrix m;
    cout << "Enter rows, cols, number of non-zero terms: ";
    cin >> m.rows >> m.cols >> m.terms;
    m.data = new Triplet[m.terms];
    cout << "Enter row, col, value for each non-zero term:\n";
    for(int i = 0; i < m.terms; i++) {
        cin >> m.data[i].row >> m.data[i].col >> m.data[i].val;
    }
    return m;
}

void displayMatrix(SparseMatrix m) {
    int k = 0;
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++) {
            if(k < m.terms && m.data[k].row == i && m.data[k].col == j) {
                cout << m.data[k].val << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

SparseMatrix transpose(SparseMatrix m) {
    SparseMatrix t;
    t.rows = m.cols;
    t.cols = m.rows;
    t.terms = m.terms;
    t.data = new Triplet[t.terms];
    int index = 0;
    for(int c = 0; c < m.cols; c++) {
        for(int i = 0; i < m.terms; i++) {
            if(m.data[i].col == c) {
                t.data[index].row = m.data[i].col;
                t.data[index].col = m.data[i].row;
                t.data[index].val = m.data[i].val;
                index++;
            }
        }
    }
    return t;
}

SparseMatrix add(SparseMatrix a, SparseMatrix b) {
    if(a.rows != b.rows || a.cols != b.cols) {
        cout << "Addition not possible (different dimensions).\n";
        SparseMatrix empty = {0,0,0,nullptr};
        return empty;
    }
    SparseMatrix sum;
    sum.rows = a.rows;
    sum.cols = a.cols;
    sum.data = new Triplet[a.terms + b.terms];
    int i=0,j=0,k=0;
    while(i<a.terms && j<b.terms) {
        int aPos = a.data[i].row * a.cols + a.data[i].col;
        int bPos = b.data[j].row * b.cols + b.data[j].col;
        if(aPos < bPos) sum.data[k++] = a.data[i++];
        else if(aPos > bPos) sum.data[k++] = b.data[j++];
        else {
            int val = a.data[i].val + b.data[j].val;
            if(val != 0) sum.data[k++] = {a.data[i].row, a.data[i].col, val};
            i++; j++;
        }
    }
    while(i < a.terms) sum.data[k++] = a.data[i++];
    while(j < b.terms) sum.data[k++] = b.data[j++];
    sum.terms = k;
    return sum;
}

SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
    if(a.cols != b.rows) {
        cout << "Multiplication not possible (incompatible dimensions).\n";
        SparseMatrix empty = {0,0,0,nullptr};
        return empty;
    }
    SparseMatrix product;
    product.rows = a.rows;
    product.cols = b.cols;
    Triplet temp[1000]; // temporary storage for terms
    int k = 0;
    for(int i = 0; i < a.rows; i++) {
        for(int j = 0; j < b.cols; j++) {
            int sum = 0;
            for(int p = 0; p < a.terms; p++) {
                if(a.data[p].row == i) {
                    for(int q = 0; q < b.terms; q++) {
                        if(b.data[q].row == a.data[p].col && b.data[q].col == j) {
                            sum += a.data[p].val * b.data[q].val;
                        }
                    }
                }
            }
            if(sum != 0) {
                temp[k].row = i;
                temp[k].col = j;
                temp[k].val = sum;
                k++;
            }
        }
    }
    product.terms = k;
    product.data = new Triplet[k];
    for(int i = 0; i < k; i++) product.data[i] = temp[i];
    return product;
}

int main() {
    int choice;
    SparseMatrix A, B, R;
    do {
        cout << "\nSparse Matrix Operations:\n";
        cout << "1. Create Matrix A\n";
        cout << "2. Create Matrix B\n";
        cout << "3. Display Matrix A\n";
        cout << "4. Display Matrix B\n";
        cout << "5. Transpose Matrix A\n";
        cout << "6. Add A + B\n";
        cout << "7. Multiply A * B\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: A = createMatrix(); break;
            case 2: B = createMatrix(); break;
            case 3: cout << "Matrix A:\n"; displayMatrix(A); break;
            case 4: cout << "Matrix B:\n"; displayMatrix(B); break;
            case 5: 
                R = transpose(A);
                cout << "Transpose of A:\n";
                displayMatrix(R);
                delete[] R.data;
                break;
            case 6:
                R = add(A, B);
                if(R.terms > 0){
                    cout << "A + B:\n";
                    displayMatrix(R);
                    delete[] R.data;
                }
                break;
            case 7:
                R = multiply(A, B);
                if(R.terms > 0){
                    cout << "A * B:\n";
                    displayMatrix(R);
                    delete[] R.data;
                }
                break;
            case 8: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 8);

    delete[] A.data;
    delete[] B.data;
    return 0;
}
