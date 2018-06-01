// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

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

int serachArr(int arr[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}


int main() {
    int n; cin >> n;
    int arr[10];
    inputArr(arr, n);
    int x; cin >> x;
    int pos = serachArr(arr, n, x);
}