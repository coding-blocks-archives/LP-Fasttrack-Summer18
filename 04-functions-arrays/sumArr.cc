// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int sumArr(int arr[], int n){
    int res = 0;
    for(int i = 0; i < n; ++i){
        res = res + arr[i];
    }
    return res;
}

void update3(int arr[], int n){
    for(int i = 0; i < n; ++i){
        arr[i] = arr[i] + 3;
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[n + 2]; // compile time constant
    
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int ans = sumArr(arr, n);
    cout << ans;

    // update 3
    update3(arr, n);

    // print arr
    print(arr, n);

}