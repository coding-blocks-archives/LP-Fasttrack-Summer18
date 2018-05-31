// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
/*
1
01
101
*/

#include <iostream>
using namespace std;
/*int main(){
    int nLines;
    cin >> nLines;

    for(int curLine = 1; curLine <=  nLines; ++curLine){
        int valToBePrinted;          // ??;
        if (curLine % 2 == 1){
            valToBePrinted = 1;
        }
        else {
            valToBePrinted = 0;
        }

        // print curLine jitni values
        for(int i = 1; i <= curLine; ++i){
            cout << valToBePrinted << " ";
            valToBePrinted = valToBePrinted == 1 ? 0 : 1;
        }
        cout << endl;
    }   
}*/

int main(){
    int nLines;
    cin >> nLines;

    for(int curLine = 1; curLine <=  nLines; ++curLine){
        int valToBePrinted = curLine % 2;        

        // print curLine jitni values
        for(int i = 1; i <= curLine; ++i){
            cout << valToBePrinted << " ";
            valToBePrinted = 1 - valToBePrinted;
            // valToBePrinted = !valToBePrinted;
        }
        cout << endl;
    }   
}
