/*
1
1 2 
1 2 3
*/
// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int nLines; cin >> nLines;

    for(int curLine = 1; curLine <= nLines; ++curLine){
        // think of just one line
        int nVal = curLine;
        for(int curVal = 1; curVal <= nVal; ++curVal){
            cout << curVal << " ";
        }
        cout << endl;
    }   
}