/*
1
2 3
4 5 6
*/
// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int nLines; cin >> nLines;
    int val = 1;
    for(int curLine = 1; curLine <= nLines; ++curLine){
        for(int curVal = 1; curVal <= curLine; ++curVal){
            cout << val << " ";
            ++val;
        }
        cout << endl;
    }
}