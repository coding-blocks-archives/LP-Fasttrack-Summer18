// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    // n!, r!, n-r!

    int n, r;
    cin >> n >> r;

    // n!
    int nFact = 1;
    for (int curNum = 1; curNum <= n; ++curNum) {
        nFact = nFact * curNum;
    }

    // r !
    int rFact = 1;
    for(int curNum = 1; curNum <= r; ++curNum){
        rFact = rFact* curNum;
    }

    // n - r !
    int nrFact = 1;
    for(int curNum = 1; curNum <= (n-r); ++curNum){
        nrFact = nrFact * curNum;
    }

    int ans = nFact / (rFact * nrFact); 
    cout << ans;
}