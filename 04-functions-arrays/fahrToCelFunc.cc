// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

double fahrToCel(int elephant) {
   return (elephant - 32) * 5.0 / 9;
}

void printCel(int init, int final, int step){
    for(int f = init; f <= final; f = f + step){
        cout << f << '\t' << fahrToCel(f) << endl;
    }
}


int main() {
    int initial, final, step;
    cout << "initial final step " << endl;
    cin >> initial >> final >> step;
    printCel(initial, final, step);
    return 0;
}