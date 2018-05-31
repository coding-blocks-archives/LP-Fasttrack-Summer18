// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
    1 * 2 * 3 * 4
    9 * 10 * 11 * 12
    13* 14* 15* 16
    5 * 6 * 7 * 8
*/

int main() {
    int nLines; cin >> nLines;

    for (int curLine = 0; curLine < nLines; curLine = curLine + 2) {
        for (int i = 1; i <= nLines; ++i) {
            int val = nLines * curLine + i;
            cout << val;
            if (i != nLines) cout << "*";
        }
        cout << endl;
    }

    int decStartVal = nLines % 2 == 0 ? nLines - 1 : nLines - 2;

    for (int curLine = decStartVal; curLine >= 1; curLine = curLine - 2) {
        for (int i = 1; i <= nLines; ++i) {
            int val = nLines * curLine + i;
            cout << val;
            if (i != nLines) cout << "*";
        }
        cout << endl;
    }

}