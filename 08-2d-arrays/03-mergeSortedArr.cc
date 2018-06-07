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

void mergeSortedArr(int res[], int x[], int y[], int n, int m) {
    int i = 0;  // ptr to cur element of x
    int j = 0;  // ptr to cur element of y
    int k = 0;  // ptr to cur element of res

    while (i < n && j < m) {
        if (x[i] < y[j]) {
            res[k] = x[i];
            ++k;
            ++i;
        }
        else {
            res[k] = y[j];
            ++k; ++j;
        }
    }
    // copy rem elements      
    while (i < n) {
        res[k] = x[i];
        ++k; ++i;
    }

    while(j < m){
        res[k] = y[j];
        ++k;
        ++j;
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    int x[100], y[100], res[200];
    inputArr(x, n);
    inputArr(y, m);
    mergeSortedArr(res, x, y, n, m);
    outputArr(res, m + n);
}