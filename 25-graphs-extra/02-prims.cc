// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Graph {
    vector < vector<pair<int, int> > > adjList;
    int sze;
public:
    Graph(int n) {
        sze = n + 1;
        adjList.resize(sze);
    }

    void addEdge(int src, int dest, int wt) {
        adjList[src].push_back(make_pair(dest, wt));
        adjList[dest].push_back(make_pair(src, wt));
    }

    void print() {
        cout << "\nGRAPH BEGINS-----------\n";
        for (int vtx = 1; vtx < sze; ++vtx) {
            auto& neighbourListOfCurVtx = adjList[vtx];
            cout << vtx << ": ";
            for (int i = 0; i < neighbourListOfCurVtx.size(); ++i) {
                cout << neighbourListOfCurVtx[i].first << "("
                     << neighbourListOfCurVtx[i].second << ")"
                     << " ";
            }
            cout << endl;
        }
        cout << "GRAPH ENDS--------------\n";
    }

    class comparePair {
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            // in pq elements are popped from the back
            if (a.second < b.second) return false;
            return true;
        }
    };

    int primMST() {
        typedef pair<int, int> Edge;
        priority_queue<Edge, vector<Edge>, comparePair> minHeap;

        int src = 9;
        // minHeap.push(make_pair(0, 0)); // HERE is the culprit, (src, 0) and not (0, 0)
        minHeap.push(make_pair(src, 0));
        vector<bool> taken(sze, false);
        int cost = 0;

        while (minHeap.empty() == false) {
            Edge curEdge = minHeap.top(); minHeap.pop();
            int curVtx = curEdge.first;
            int curWt = curEdge.second;
            if (taken[curVtx] == true) {
                continue;
            }
            else {
                taken[curVtx] = true;
                cost += curWt;
            }
            const vector<Edge>& nbrList = adjList[curVtx];
            for (int i = 0; i < nbrList.size(); ++i) {
                Edge nbrEdge = nbrList[i];
                int nbrVtx = nbrEdge.first;
                int nbrWt = nbrEdge.second;
                if (taken[nbrVtx] == false) {
                    minHeap.push(nbrEdge);
                }
            }
        }
        return cost;
    }
};

int main() {
    int nVtx, nEdges ; cin >> nVtx >> nEdges;
    Graph g(nVtx);
    for (int i = 0; i < nEdges; ++i) {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        g.addEdge(src, dest, wt);
    }
    g.print();
    int ans = g.primMST();
    cout << ans;
}