// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
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

int cnt;
void printSubset(int arr[], int n, int be, int subans[], int i){
    if (be == n){
        ++cnt; cout << cnt << ".\t";
        outputArr(subans, i);
        cout << endl;
        return;
    }

    subans[i] = arr[be];
    printSubset(arr, n, be + 1, subans, i + 1);
    printSubset(arr, n, be + 1, subans, i);
}


int main(){
    int arr[100];
    int n; cin >> n;
    inputArr(arr, n);   
    
    int subans[100];
    printSubset(arr, n, 0, subans, 0);
}