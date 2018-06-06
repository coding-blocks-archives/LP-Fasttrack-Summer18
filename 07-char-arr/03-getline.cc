// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
template<typename T>
void print(const T& c) {
    cout << "X" << c << "X" << endl;
}

int main(){
    int x; cin >> x;
    print(x);

    char arr[3]="";
    cin.getline(arr, 3);
    print(arr);

    cin.clear();    // reset cin

    char c='z';
    cin.get(c);
    print(c);   
}