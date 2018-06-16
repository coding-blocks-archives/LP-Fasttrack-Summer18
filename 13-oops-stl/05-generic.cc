// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class VectorInt{
    int arr[100];
};

class VectorChar{
    char arr[100];
};

template <typename T>
class Vector{
    T arr[100];
};

class Elephant{
    int wt;
    char name[100];
};


int main(){
    // VectorInt vint;   // container of ints
    // VectorChar vchar;   // container of chars

    Vector<int> v1;
    Vector<char> v2;   
    Vector<Elephant> v3;
}