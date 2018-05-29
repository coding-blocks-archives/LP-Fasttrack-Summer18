// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int num;
    cin >> num;

    // if (num % 2 == 0 or num % 7 == 0){
    //     cout << "Yes! " << num << " is divisible by either 2 or 7";
    // }   
    // else {
    //     cout << " No!";
    // }

    bool isEven = true;         // num % 2 == 0 ? true : false
    if (num % 2 == 0){
        isEven = true;
    }
    else {
        isEven = false;
    }

}