// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int divisor;
    int dividend;
    cin >> dividend >> divisor;

    if (divisor == 0) {
        cout << "Man! You entered zero divisor!" << endl;
    }
    else {
        double quotient = (double)dividend / divisor;
        cout << "Quotient is = " << quotient;
    }

}