// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int inputMat(int mat[30][40], int nRows, int nCols) {
    for (int r = 0; r < nRows; ++r) {
        for (int c = 0; c < nCols; ++c) {
            // cout << "enter element " << r << " " << c << ": ";
            cin >> mat[r][c];
        }
    }
}

void outputMat(int mat[][40], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c)
        {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
}

// most significant dimension can be left out
void outputMatColWise(int mat[][40], int m, int n){
    for(int c = 0; c < n; ++c){
        for(int r = 0; r < m; ++r){
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
}


int main() {
    int mat[30][40][3];
    int m, n;
    cin >> m >> n;
    inputMat(mat, m, n);
    outputMatColWise(mat, m, n);
    return 0;
}