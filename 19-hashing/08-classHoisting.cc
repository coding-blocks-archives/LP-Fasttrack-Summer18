// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Foo {
    const char c;
    Foo(x):c(x){}
    void f1();
    void f2();
};

void Foo::f1() {f2();}
void Foo::f2() {};

int main() {

}