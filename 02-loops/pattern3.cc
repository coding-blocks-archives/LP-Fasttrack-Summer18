/*
   *
  ***
 *****
  ***
   *
*/
// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int nLines;
    cin >> nLines;

    int incLines = (nLines / 2) + 1;
    int decLines = nLines - incLines;

    // focusing on incPattern
    for (int curLine = 1; curLine <= incLines; ++curLine) {
        int nSpaces = incLines - curLine;
        int nStars = 2 * curLine - 1;
        for(int i = 1; i <= nSpaces; ++i) cout << " ";
        for(int i = 1; i <= nStars; ++i)  cout << "*";
        cout << endl;
    }

    // focusing on decPattern
    int nSpaces = 1;
    for(int curLine = decLines; curLine >= 1; --curLine){
        int nStars = 2 * curLine - 1;
        for(int i = 0; i < nSpaces; ++i) cout << " ";
        for(int i = 0; i < nStars; ++i)  cout << "*";
        cout << endl;
        ++nSpaces;
    }


}