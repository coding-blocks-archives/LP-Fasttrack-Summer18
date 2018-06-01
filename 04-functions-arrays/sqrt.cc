// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int mySqrt(int num){
    // int root = 0;
    // while(root * root <= num) {
    //     ++root;
    // }
    // return root - 1;

    int root;
    for(root = 0; root * root <= num; ++root);
    return root - 1;

}

int main() {
    int num;
    cin >> num;

    int ans = mySqrt(num);
    cout << ans << endl;;

}