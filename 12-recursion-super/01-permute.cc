// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int cnt = 0;

void printPermutations(char arr[], int be){
    if (arr[be] == '\0'){
        ++cnt;
        cout <<cnt << ".\t" << arr << endl;
        return;
    }

    for(int pos = be; arr[pos] != '\0'; ++pos){
        swap(arr[pos], arr[be]);
        printPermutations(arr, be + 1);
        swap(arr[pos], arr[be]);
    }
}

int main(){
    char arr[100];
    cin >> arr;
    
    printPermutations(arr, 0);   
}