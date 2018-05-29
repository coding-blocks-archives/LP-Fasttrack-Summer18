// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    bool isPrime = true;        // isPrime will be true if num is prime

    for (int div = 2; div < num; ++div) {
        if (num % div == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime == true) {
        cout << num << " is prime";
    }
    else {
        cout << num << " is not prime";
    }
}