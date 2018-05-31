// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int num; cin >> num;

    int mul = 1;    // initialiser
    int cnt = 0;

    // for(; num / mul > 0; mul = mul * 10){
    //     ++cnt;
    // }

    while(num / mul > 0){   // condition check
        ++cnt;
        mul = mul * 10;     // update
    }

    cout << cnt;
}