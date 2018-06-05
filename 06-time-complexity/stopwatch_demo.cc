// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void func1(int n){
    // prints "X" n times
    cout << "\nExecuting func1" << endl;
    for(int i = 0; i < n; ++i){
        // cout << "X";
    }
}

void func2(long long n){
    // prints "X" n times
    cout << "\nExecuting func2" << endl;
    for(int i = 0; i < n * n; ++i){
         if (i < n) {
            // cout << "X";
        }
    }
}

void printTimeInSec(int start){
    cout << fixed << setprecision( 6 ) << 
        "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n"; 
}

int main(){
    int x; 
    cin >> x;

    int start1 = clock();
    func1(x);
    printTimeInSec(start1);

    int start2 = clock();
    func2(x);    
    printTimeInSec(start2);
}