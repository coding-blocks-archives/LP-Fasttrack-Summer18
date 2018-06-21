// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
using namespace std;

void printStk(stack<int>& stk){ 
    // pass by reference. Objects BY DEFAULT via Pass by Value
    while(stk.empty() == false){
        cout << stk.top() << " " ;
        stk.pop();
    }
    cout << endl;
}    

??? redundantParantheses(){}
vector<int> nearestLargest(){ // towards left
}
??? reverseStack2(){}
??? reverseStack1(){}
??? reverseStack0(){}

class SpecialStack{};



int main(){
    stack<int> s;

    int x; 
    while(true){
        cin >> x;
        if (x == -1)break;
        s.push(x);
    }
    printStk(s);  

}