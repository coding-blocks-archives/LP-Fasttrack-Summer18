// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <climits>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int minStepsRec(int arr[], int be, int n, int memoPad[]) {
    if (be == n - 1) {
        return 0;
    }

    if (memoPad[be] != -1) return memoPad[be];
    /*
    if (be > n - 1){
        return INT_MAX;
    }*/

    int ans = 1e6;

    int nStepsICanMoveForward = arr[be];
    for (int i = 1; i <= nStepsICanMoveForward; ++i) {
        int nextBox = be + i;
        if (nextBox < n) {
            int stepsReq = minStepsRec(arr, nextBox, n, memoPad) + 1;
            ans = min(ans, stepsReq);
        }
    }
    memoPad[be] = ans;
    return ans;
}

int minStepsDP(int arr[], int n){
    int* dp = new int[n];
    for(int i = 0; i < n; ++i){
        dp[i] = 1e6;
    }
    dp[0] = 0;

    for(int curBox = 0; curBox < n - 1; ++curBox){
        for(int step = 1; step <= arr[curBox] && step + curBox < n; ++step){
            dp[curBox + step] = min(dp[curBox] + 1, dp[curBox + step]);
        }
    }
    int ans = dp[n - 1];
    delete [] dp;
    return ans;

}


int main() {
    int arr[100];
    int n; cin >> n;
    inputArr(arr, n);

    int* memoPad = new int[n];
    for(int i = 0; i < n; ++i) memoPad[i] = -1;

    int ans = minStepsRec(arr, 0, n, memoPad);
    // int ans = minStepsDP(arr, n);

    cout << ans << endl;

}