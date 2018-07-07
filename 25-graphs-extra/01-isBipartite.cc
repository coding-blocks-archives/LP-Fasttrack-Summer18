// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
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

    bool isBipartite() {
        int src = 1;

        enum color {NOCOLOR = 0, RED = 1, YELLOW = 2};
        // vector<color> vtxColor(sze, NOCOLOR);

        vector<color> vtxColor(sze);
        for (int i = 0; i < sze; ++i) vtxColor[i] = NOCOLOR;

        queue<int> q;

        q.push(src);
        vtxColor[src] = RED;

        while (q.empty() == false) {
            int curVtx = q.front(); q.pop();
            const vector<int>& nbrList = adjList[curVtx];

            for (int i = 0; i < nbrList.size(); ++i) {
                int curNbr = nbrList[i];

                color nbrColor = vtxColor[curVtx] == RED ? YELLOW : RED;

                if (vtxColor[curNbr] == NOCOLOR) {
                    vtxColor[curNbr] = nbrColor;
                    q.push(curNbr);
                }
                else if (vtxColor[curNbr] != nbrColor) {
                    return false;
                }
            }
        }
        return true;
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
    int ans = g.isBipartite();
    cout << ans;

}