// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <iomanip>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void outputMat(int mat[][100], int m, int n) {
    cout << "\n-----MAT Begins----\n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << setw(3) << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

int maxProfit(int price[], int n) {
    int dp[100][100];

    for (int len = 1; len <= n; ++len) {
        int year = n - len + 1;
        int windowSrt = 0;
        int maxWindowSrt = n - len;
        int windowEnd = windowSrt + len - 1;
        
        while (windowSrt <= maxWindowSrt) {
            int startBottleSell = year * price[windowSrt] + dp[windowSrt + 1][windowEnd];
            int endBottleSell = year * price[windowEnd] + dp[windowSrt][windowEnd - 1];
            dp[windowSrt][windowEnd] = max(startBottleSell, endBottleSell);
            ++windowSrt;  ++windowEnd;
        }
    }

    outputMat(dp, n, n);
    return dp[0][n - 1];
}


int main() {
    int price[100];
    int n; cin >> n;
    inputArr(price, n);
    int ans = maxProfit(price, n);
    cout << ans;
}