// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int factorial(int n){
    if (n == 0){                        // base case
        return 1;
    }
    int smallFact = factorial(n - 1);   // recurrence relation
    int nfact = smallFact * n;          
    return nfact;
}

int fib(int n){
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int prevFib = fib(n - 1);
    int superPrev = fib(n - 2);
    return prevFib + superPrev;
}

void printInc(int n){
    if (n <= 0) return;
    printInc(n - 1);
    cout << n << " ";
}


int main(){
    // int n;
    // cin >> n;
    // int ans = factorial(n);
    // cout << ans;   

    int n;
    cin >> n;
    int ans = fib(n);
    cout << ans;
}