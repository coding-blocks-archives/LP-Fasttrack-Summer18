// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputMat(char mat[][100], int m, int n){
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cin >> mat[r][c];
        }
    }
}
void outputMat(char mat[][100], int m, int n){
    cout << "\n-----MAT Begins----\n";
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

void rotateClockwise1(char mat[][100], int n){
    // T(N) = O(2 * N2) 
    // transpose
    for(int r = 0; r < n; ++r){
        for(int c = r; c < n; ++c){
            swap(mat[r][c], mat[c][r]);
        }
    }

    // swap cols
    for(int r = 0; r < n; ++r){
        for(int sc = 0, ec = n - 1; sc < ec; ++sc, --ec){
            swap(mat[r][sc], mat[r][ec]);
        }
    }
}

void rotateClockwise2(char mat[][100], int n){
    for(int rot = 0; rot < n / 2; ++rot){
        for(int x = rot; x < n - rot - 1; ++x){
            char tmp = mat[rot][x];
            swap(tmp, mat[x][n-rot-1]);
            swap(tmp, mat[n-rot-1][n-x-1]);
            swap(tmp, mat[n-x-1][rot]);
            swap(tmp, mat[rot][x]);
        }
    }
}

int main(){
    char mat[100][100];
    int N;
    cin >> N;
    inputMat(mat, N, N);
    
    rotateClockwise2(mat, N);

    outputMat(mat, N, N);



}