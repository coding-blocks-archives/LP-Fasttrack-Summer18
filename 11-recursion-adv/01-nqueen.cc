// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void clearBoard(char board[][100], int N){
    for(int i = 0; i < N; ++i){
        for(int c = 0; c < N; ++c){
            board[i][c] = 'X';
        }
    }
}


void outputMat(char mat[][100], int m, int n) {
    cout << "\n-----MAT Begins----\n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

bool canPlace(char board[][100], int r, int c, int dim) {
    for (int x = 0; x < r; ++x) {
        if (board[x][c] == 'Q') return false;
    }

    int rowDir[] = { -1, -1};
    int colDir[] = { +1, -1};
    for (int dir = 0; dir < 2; ++dir) {
        for (int dist = 1; dist < dim; ++dist) {
            int nextRow = r + dist * rowDir[dir];
            int nextCol = c + dist * colDir[dir];
            if ((nextRow < 0 || nextRow >= dim) || (nextCol < 0 || nextCol >= dim)){
                // out of the board
                break;
            } 
            if (board[nextRow][nextCol] == 'Q'){
                return false;
            }
        }
    }
    return true;
}


bool solveNQueen(char board[][100], int r, int dim) {
    if (r == dim) { // nothing to do. We are already successful
        return true;
    }

    for (int c = 0; c < dim; ++c) {
        bool check = canPlace(board, r, c, dim);
        if (check == true) {
            // place a queen here @ r,c
            board[r][c] = 'Q';
            bool status = solveNQueen(board, r + 1, dim);
            if (status == true) {   // means recursion was successful
                return true;        // we have got one configuration
            }
            // recursion was unsuccessful to solve the config
            board[r][c] = 'X';      // reset the changes made to the board
        }
    }

    // true was not returned even for a single cell in the r (ie current) row
    return false;   // not possible
}


int main() {
    int N;
    cin >> N;

    char board[100][100] = {};
    clearBoard(board, N);

    bool success = solveNQueen(board, 0, N);

    if (success) {
        outputMat(board, N, N);     // prints board
    }
    else {
        cout << "Sorry Man!! You dont have a kingdom to handle these queens." << endl;
    }
}