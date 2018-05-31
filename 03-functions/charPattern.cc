// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void incPrint(int n){
    char val = 'A';             // char val = A;    // int x = y;
    for(int i = 0; i < n; ++i){
        cout << val;
        ++val;
    }
}

void decPrint(int n){
    char val = 'A' + n - 1;
    for(int i = 0; i < n; ++i){
        cout << val;
        --val;
    }
}

int main() {
    int nLines;
    cin >> nLines;

    for (int curLine = nLines; curLine >= 1; --curLine) {
        incPrint(curLine);
        decPrint(curLine);
        cout << endl;
    }

    return 0;
}