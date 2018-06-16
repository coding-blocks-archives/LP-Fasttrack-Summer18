// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; ++i){
        for(int cur = 0; cur < n - i - 1; ++cur){
            if (arr[cur] > arr[cur + 1]){
                mySwap(arr[cur], arr[cur + 1]);
            }
        }
    }
}

void printPermutations(char arr[], int be){
    if (arr[be] == '\0'){
        // push the permutation into the vector

        return;
    }

    for(int pos = be; arr[pos] != '\0'; ++pos){
        swap(arr[pos], arr[be]);
        printPermutations(arr, be + 1);
        swap(arr[pos], arr[be]);
    }
}


int main(){
    
}