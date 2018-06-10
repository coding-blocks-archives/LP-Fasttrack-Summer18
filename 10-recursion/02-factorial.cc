// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {                       // base case
        return 1;
    }
    int smallFact = factorial(n - 1);   // recurrence relation
    int nfact = smallFact * n;
    return nfact;
}

int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int prevFib = fib(n - 1);
    int superPrev = fib(n - 2);
    return prevFib + superPrev;
}

void printInc(int n) {
    if (n <= 0) return;
    printInc(n - 1);
    cout << n << " ";
}

void decPrint(int n) {
    if (n <= 0) return;

    cout << n << " ";
    decPrint(n - 1);
}

void printDig(int dig) {
    char numerals[][10] {
        "zero",
        "one", "two", "three",
        "four", "five", "six",
        "seven", "eight", "nine",
    };
    cout << numerals[dig];
}

void printNum(int n) {
    if (n == 0) return;

    int unitDig = n % 10;
    int remNum = n / 10;
    printNum(remNum);   // twoXzeroXfourX
    printDig(unitDig);  // we have to print eightX
    cout << " ";
}

void displayArr(int arr[], int n) {
    if (n == 0) return;

    cout << arr[n - 1] << " ";
    displayArr(arr, n - 1);
}

void bubbleSort(int arr[], int be, int en){ // [be,en]
    if (be >= en){
        return;
    }

    bubbleSort(arr, be + 1, en);
    if (arr[be] > arr[be + 1]){
        swap(arr[be], arr[be + 1]);
        bubbleSort(arr, be + 1, en);
    }

}


int main() {
    // int n;
    // cin >> n;
    // int ans = factorial(n);
    // cout << ans;

    // int n;
    // cin >> n;
    // int ans = fib(n);
    // cout << ans;

    // int n;
    // cin >> n;
    // decPrint(n);

    // int num;
    // cin >> num;
    // printNum(num);

    // int arr[] = {1, 2, 3};
    // displayArr(arr, 3);

    int arr[] = {5, 4 , 1, 3, 2};
    bubbleSort(arr, 0, 4);
    void outputArr(int arr[], int n); // fn declaration
    outputArr(arr, 5);
}


void outputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}