// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

void printPermute(char arr[], int be){
    if (arr[be] == '\0'){
        cout << arr << endl;
        return;
    }

    string s = arr;
    for(int pos = be; arr[pos] != '\0'; ++pos){
        swap(s[be], s[pos]);
        strcpy(arr, s.c_str());
        printPermute(arr, be + 1);
    }

}

int main(){
    char arr[100];
    cin >> arr;
    printPermute(arr, 0);

}