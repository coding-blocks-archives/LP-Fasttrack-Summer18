// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int x = 4;

    for(int i = 1; i < 10; ++i){
        if (i >= x){
            if (x){
                x = 5;
                break;
            }
            x = 6;
        }
        x = 7;
    }   
    cout << x;
}