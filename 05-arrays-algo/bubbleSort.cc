// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mySwap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void inputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

void outputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; ++i){
        for(int cur = 0; cur < n - i - 1; ++cur){
            if (arr[cur] > arr[cur + 1]){
                mySwap(arr[cur], arr[cur + 1]);
            }
        }
    }
}

int main(){
    int arr[10];
    int n; cin >> n;
    inputArr(arr, n);
    bubbleSort(arr, n);
    outputArr(arr, n);

}