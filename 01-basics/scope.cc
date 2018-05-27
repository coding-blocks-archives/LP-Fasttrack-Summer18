// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int x = 1;

    int y = 2;
    {
        cout << x;
        int x = 10;
        cout << x << endl;
        cout << y << endl;
    }
    // char x;
    cout << y
}