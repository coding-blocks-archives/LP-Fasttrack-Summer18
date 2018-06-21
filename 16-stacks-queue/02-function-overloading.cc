// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
class Elephant{};

void sum(Elephant e1,Elephant e2){}
// void sum(int e1,int e2){}
void sum(double e1,double e2){}

int main(){
    Elephant e1, e2;
    sum(e1, e2);
    sum(2, 3.0);
}