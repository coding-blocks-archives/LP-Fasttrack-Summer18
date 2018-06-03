// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int binToDec(int num){
    int ans = 0;
    int faceVal = 1;
    while(num > 0){
        int rem = num % 2;
        int quo = num / 2;
        ans = faceVal * rem + ans;
        faceVal = faceVal * 10;
        num = quo;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int res = binToDec(n);
    cout << n << "---->" << res << endl;   
}