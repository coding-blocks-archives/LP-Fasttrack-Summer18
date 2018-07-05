// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int> > adjList;
    int sze;
public:
    Graph(int n) {
        sze = n + 1;
        adjList.resize(sze);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void print() {
        cout << "\nGRAPH BEGINS-----------\n";
        for (int vtx = 1; vtx < sze; ++vtx) {
            const vector<int>& neighbourListOfCurVtx = adjList[vtx];
            cout << vtx << ": ";
            for (int i = 0; i < neighbourListOfCurVtx.size(); ++i) {
                cout << neighbourListOfCurVtx[i] << ",";
            }
            cout << endl;
        }
        cout << "\nGRAPH ENDS--------------\n";
    }

    void dfs(int src, vector<bool>& isVisited){
        cout << src << " ";
        isVisited[src] = true;

        auto& ngbrList = adjList[src];
        for(int i = 0; i < ngbrList.size(); ++i){
            int curNgbr = ngbrList[i];
            if (isVisited[curNgbr] == false){
                dfs(curNgbr, isVisited);
            }
        }
    }

    void dfs(int src){
        vector<bool> isVisited(sze);
        dfs(src, isVisited);
    }


};

int main() {
    int nVtx, nEdges ; cin >> nVtx >> nEdges;
    Graph g(nVtx);
    for (int i = 0; i < nEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
    g.print();
    g.dfs(1);
}