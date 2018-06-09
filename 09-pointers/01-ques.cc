// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
#define print(x)    cout << (#x) << "\t\t: " << (x) << endl

int func2(int* arr){

}

int func1(int arr[]){

}

int main(){
    int x = 10;
    int* ptr = &x;
    // print(ptr);         // xaddress blah! blah!
    // print(*ptr);        // 10
    // print(x);           // 10
    // // print(x == ptr);    // error!!! because diff data types
    // print(x == *ptr);   // true

    // int* ptr2 = 10;         // wrong!! 10 is an integer NOT an address
    // print(ptr2);           // some garbage address  
    // print(*ptr2);      

    // int* ptr3 = NULL;       // correct. 0 means 0 addresss and not 0 value
    // print(ptr3);            // 0
    // print(*ptr3);           // 

    // int* x, y;  // 1 pointer
    // int* x, *y; // 2 pointers

    int iarr[5] = {10, 20, 30, 40, 50};
    // print(arr);     // arr is address of array      
    // print(&arr[0]); // address of the first element of array
    // print(&arr);    // arr is address of ARRAY
    // print(arr[0]);  // arr[0]
    // print((&arr[3]) - (&arr[0]));
  
    // char carr[5] = "abcd";
    // print(&iarr[2]);
    // print(carr[2]);
    // print((int*)&carr[2]);
    // print(&iarr[3]-&iarr[1]);
    // print(&carr[3]-&carr[1]);

    func1(iarr);
    func2(iarr);

}