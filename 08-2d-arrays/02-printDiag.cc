// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputMat(char mat[][10], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> mat[r][c];
        }
    }
}

void outputMat(char mat[][10], int m, int n) {
    cout << "\n-----MAT Begins----\n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

void printDiag(char mat[][10], int m, int n) {
    int minm = min(m, n);
    for (int i = 0; i < minm; ++i) {
        cout << mat[i][i] << " ";
    }
}


void printWave(char mat[][10], int m, int n) {
    for (int col = 0; col < n; ++col) {
        int sr = col % 2 == 0 ? 0 : m - 1;
        int er = col % 2 == 0 ? m - 1 : 0;
        int inc = col % 2 == 0 ? +1 : -1;
        while ((inc == 1 && sr <= er) ||  (inc == -1 && sr >= er)) {
            cout << mat[sr][col] << " ";
            sr = sr + inc;  // sr += inc
        }
    }
}



int main() {
    char mat[10][10];
    int m, n;
    cin >> m >> n;
    inputMat(mat, m, n);
    outputMat(mat, m, n);
    // printDiag(mat, m, n);
    printWave(mat, m, n);
}