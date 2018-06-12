// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int func(int arr[]){    // int *arr
    cout << sizeof(arr);
}

int main(){
    int * ptr = NULL;
    int arr[100];
    cout << sizeof (arr);

    func(arr);
    // func(ptr);    
}