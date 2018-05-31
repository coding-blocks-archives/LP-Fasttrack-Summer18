// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int factorial(int n){        // function definition
    int nFact = 1;
    for(int i = 1; i <= n; ++i){
        nFact = nFact * i;
    }
    return nFact;
}


int main(){
    int n; 
    int r;
    cin >> n >> r;

    // int factorial(int n);   // function declaration
    int nFact = factorial(n);  // function usage/ calling
    int rFact = factorial(r);
    int nrFact = factorial(n - r);

    int ncr = nFact / (rFact * nrFact);
    cout << ncr;
    return 0;   // means successful termination   
}


