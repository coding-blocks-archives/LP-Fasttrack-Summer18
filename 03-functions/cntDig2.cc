// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int num;
    cin >> num;

    int cnt  = 0;
    while(num > 0){
        num = num / 10;
        ++cnt;
    }   
    cout << cnt;
}