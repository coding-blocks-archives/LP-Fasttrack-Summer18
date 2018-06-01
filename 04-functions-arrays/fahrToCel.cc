// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int initial, final, step;
    cout << "initial final step " << endl;
    cin >> initial >> final >> step;

    for(int fahr = initial; fahr <= final; fahr = fahr + step){
        double cel = (fahr - 32) * (5.0 / 9) ;
        cout << fahr << " " << cel;
        cout << endl;
    }
    
    return 0;
}