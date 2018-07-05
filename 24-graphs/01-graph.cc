// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Graph{
    vector<vector<int> > adjList;
    int sze;
public:
    Graph(int n){
        sze = n + 1;
        adjList.resize(sze);
    }

    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void print(){
        
    }
};



int main(){
    
}