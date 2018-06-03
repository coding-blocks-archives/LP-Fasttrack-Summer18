// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mySwap(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}

void mySwap1(int arr[]){
    int tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp; 
}

int main(){
    int a, b;
    cin >> a >> b;
    // mySwap(2, 3);  // WRONG!!!
    mySwap(a, b);
    cout << a << " " << b;

    // int arr[2] = {2, 3};
    // mySwap(arr);
    // cout << arr[0] << " " << arr[1];

}