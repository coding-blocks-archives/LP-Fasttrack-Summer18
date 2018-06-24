// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

int sum(int x, int y) {}

bool compare(int x, int y) {
    return x > y;
}

template<class T, class Compare>
class Elephat{
    T a, 
    Compare obj;
    if (obj(x, c)){
        
    }
}


class CompareClass {
public:
    bool operator()(int x, int y) {
        return x > y;
    }
};

int main() {
    // priority_queue<int> pq;
    // pq.push(2);
    // pq.push(4);
    // pq.push(3);
    // cout << pq.top();

    // priority_queue<int, vector<int>, bool(*)(int, int)> minpq;
    priority_queue<int, vector<int>, CompareClass> minpq;
    // TODO defualt arg in C++

    CompareClass C;
    // C.compare(1, 3); 
    // C(1, 2);
}
