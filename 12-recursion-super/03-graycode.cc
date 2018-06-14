// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

void getGrayCodes(int n, vector<int>& v) {
    if (n == 0){
        v.push_back(0);
        return;
    }

    getGrayCodes(n - 1, v);
    for (int i = v.size() - 1; i >= 0; --i){
        int cur = v[i];
        int numWithOne = cur | (1 << (n - 1));
        v.push_back(numWithOne);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    getGrayCodes(n, ans);

    // for(int x : ans){
    //     cout << x << endl;
    // }
    cout << ans.size();
}