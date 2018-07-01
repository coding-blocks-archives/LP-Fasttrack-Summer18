// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int waysToDecode(char arr[], int be) {
    if (arr[be] == '\0') {
        return 1; //?????
    }

    int curSingleChar = arr[be];
    if (curSingleChar == '0') return 0;

    int waysWithSingleChar = 1 * waysToDecode(arr, be + 1);
    int waysWithDoubleChar = 0;

    if (arr[be + 1] != '\0') {
        int nextChar = arr[be + 1];
        int num = (curSingleChar - '0') * 10 + (nextChar - '0');

        if (num <= 26) {
            waysWithDoubleChar = 1 * waysToDecode(arr, be + 2);
        }
    }
    return waysWithSingleChar + waysWithDoubleChar;
}

int waysToDecode2(char arr[]) {
    int n = strlen(arr);
    if (n == 0) return 0;

    int* dp = new int[n];
    fill(dp, dp + n, 0);

    dp[n - 1] = 1;  // 1 2 3

    for (int i = n - 2; i >= 0; --i) {
        int curSingleChar = arr[i];
        if (curSingleChar == '0') {dp[i] = 0; continue;}
        int waysWithSingleChar = dp[i + 1];
        int waysWithDoubleChar = 0;
        if (i + 1 < n) {
            int nextChar = arr[i + 1];
            int num = (curSingleChar - '0') * 10 + (nextChar - '0');
            if (num <= 26) waysWithDoubleChar = i + 2 < n ? dp[i + 2] : 1;
        }
        dp[i] = waysWithSingleChar + waysWithDoubleChar;
    }
    int ans = dp[0];
    delete [] dp;
    return ans;
}


int main() {
    char arr[100];
    cin >> arr;

    int ans = waysToDecode2(arr);
    cout << ans;
}