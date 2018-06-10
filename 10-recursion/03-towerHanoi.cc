// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int cnt = 0;

void printStepForHanoi(int n, char src, char dest, char helper){
    if (n == 0) return;
    ++cnt;

    printStepForHanoi(n - 1, src, helper, dest);
    cout << "step " << cnt << " " << n << " :" << src << "-->" << dest << endl;
    printStepForHanoi(n - 1, helper, dest, src);
}

int main(){
    int n;
    cin>> n;
    printStepForHanoi(n, 'A', 'B','C');   
}