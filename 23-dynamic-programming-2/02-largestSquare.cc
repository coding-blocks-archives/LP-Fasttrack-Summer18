// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputMat(int mat[][100], int m, int n){
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cin >> mat[r][c];
        }
    }
}
void outputMat(int mat[][100], int m, int n){
    cout << "\n-----MAT Begins----\n";
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

int maxSideOfSquare(int grid[][100], int m, int n){
    int bestSide = 0;
    int dp[100][100] = {};

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if (i == 0 or j == 0) {
                dp[i][j] = grid[i][j] == 1 ? 1 : 0;
            }
            else {
                int ansForCurrentCell = 0;
                if (grid[i][j] == 1){
                    ansForCurrentCell = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
                dp[i][j] = ansForCurrentCell;
            }
            bestSide = max(bestSide, dp[i][j]);
        }
    }
    outputMat(dp, m, n);
    return bestSide;
}



int main(){
    int grid[100][100];
    int n, m; cin >> m >> n;
    inputMat(grid, m, n);
    int ans = maxSideOfSquare(grid, m, n);
    cout << ans;
}