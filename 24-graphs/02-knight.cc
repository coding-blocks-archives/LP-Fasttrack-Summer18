// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minDistForKnight(int board[][100], int dim, int xSrc, int ySrc, int xDest, int yDest) {
    int rowDir[] = { +1, +2, +2, +1, -1,  -2, -2 , -1};
    int colDir[] = { +2, +1, -1, -2, -2, -1, +1, +2};

    // vector<vector<bool> > visited(dim, vector<bool>(dim, false));
    bool visited[100][100] = { false };
    int distFromSrc[100][100] = {0};
    queue<int> rCord, cCord;
    rCord.push(xSrc);
    cCord.push(ySrc);
    visited[xSrc][ySrc] = true;

    while (rCord.empty() == false) {
        int r = rCord.front(); rCord.pop();
        int c = cCord.front(); cCord.pop();
        if (r == xDest && c == yDest) return distFromSrc[r][c];

        for (int i = 0; i < 8; ++i) {
            int nextRow = r + rowDir[i];
            int nextCol = c + colDir[i];
            if (
                nextRow >= 0 && nextRow < dim &&
                nextCol >= 0 && nextCol < dim &&
                visited[nextRow][nextCol] == false
            ) {
                distFromSrc[nextRow][nextCol] = distFromSrc[r][c] + 1;
                visited[nextRow][nextCol] = true;
                rCord.push(nextRow);
                cCord.push(nextCol);
            }
        }
    }
    return -1;
}




int main() {
    int board[100][100] = {};
    int dim, xSrc, ySrc, xDest, yDest;
    cin >> dim >> xSrc >> ySrc >> xDest >> yDest;
    int ans = minDistForKnight(board, dim, xSrc, ySrc, xDest, yDest);
    cout << ans;

}