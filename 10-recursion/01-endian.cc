// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <bitset>
using namespace std;

void printBinary(char x){

    for(int i = 0; i < 8; ++i){
        if (x & 1) {
            cout << 1;
        }
        else {
            cout << 0;
        } 
        // if (i == 15) cout << endl;
        x = x >> 1;
    }
    cout << endl;
}


int main(){
    int x = 1 << 30;
    // bitset<32> num(x);
    // cout << num;

    char* ptr = (char*)&x;
    for(int i = 0; i < 4; ++i){
        printBinary(*ptr);
        ++ptr;        
    }
}