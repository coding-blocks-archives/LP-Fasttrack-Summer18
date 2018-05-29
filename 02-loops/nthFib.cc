// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int superprev = 0;   
    int previous = 1;
    int cur = -1;   // sentinel

    if (n == 0) cur = superprev;
    if (n == 1) cur = previous;

    for(int i = 2; i <= n; ++i){
        cur = superprev + previous;
        superprev = previous;
        previous = cur;
    }
    cout << cur;

}