// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mySwap(int&a, int& b){
    int c = a;
    a = b;
    b = c;
}

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void outputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

int smallestElementIdx(int arr[], int be, int en){
    int smallestIdx = be;
    int cur = be; // represents currIdx and NOT cur Element
    while(cur <= en){
        if (arr[cur] < arr[smallestIdx]){
            // update smallestIdx. Why?? I have found a better element than smallestIdx
            smallestIdx = cur;
        }
        ++cur;
    }
    return smallestIdx;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n ; ++i) {
        int idx = smallestElementIdx(arr, i, n - 1);   // index of smallest element  
        mySwap(arr[i], arr[idx]);
    }
}



int main() {
    int arr[100];
    int n;
    cin >> n;
    inputArr(arr, n);
    selectionSort(arr, n);
    outputArr(arr, n);

}