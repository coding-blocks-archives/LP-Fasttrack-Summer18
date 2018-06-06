// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
template<typename T>
void print(const T& c) {
    cout << "X" << c << "X" << endl;
}

int main() {
    char c = 'a';
    int b = 12;

    if (cin) cout << "cin is 1 " << endl;
    else cout << "cin is 0" << endl;

    cin >> b;
    print(b);
    print(cin);
    cin.get(c);

    if (cin) cout << "cin is 1 " << endl;
    else cout << "cin is 0" << endl;



    print(c);

    // cin >> c;
    cin.get(c);
    print(c);

    // cin >> c;
    cin.get(c);
    print(c);

}