// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    char arr_c[100];
    int  arr_i[100];

    // cin >> arr_i;
    // cin >> arr_c;
    // cout << arr_c;

    cin.getline(arr_c, 100, '?');
    cout << "X" << arr_c << "X" << endl;             // by design, contents will be printed
    // cout << arr_i << endl;
}