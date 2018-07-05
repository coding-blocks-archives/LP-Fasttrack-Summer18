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

    vector<int> dijkstraForShortestDistance(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, comparePair> pq;
        vector<int> dist(sze, -1);

        pq.push(make_pair(src, 0));

        while (pq.empty() == false) {
            pair<int, int> curPair = pq.top(); pq.pop();
            int curVtx = curPair.first;
            int distCurVtxFromSrc = curPair.second;

            if (dist[curVtx] == -1 or dist[curVtx] > distCurVtxFromSrc) {
                dist[curVtx] = distCurVtxFromSrc;
            }
            else { continue; }

            const auto& nbrList = adjList[curVtx];
            for (int i = 0; i < nbrList.size(); ++i) {
                auto curNbrVtxWt = nbrList[i];
                int curNbrVtx = curNbrVtxWt.first;
                int curNbrWt = curNbrVtxWt.second;
                // dist of curNbr from curVtx (in line 54)
                if (dist[curNbrVtx] != -1) continue;    // already visited
                int distCurNbrFrmSrc = curNbrWt + dist[curVtx];
                pq.push(make_pair(curNbrVtx, distCurNbrFrmSrc));
            }
        }
        return dist;
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
    int srcVtx; cin >> srcVtx;
    auto ans = g.dijkstraForShortestDistance(srcVtx);
    for(int i = 0; i < ans.size(); ++i){
        cout << i << " " << ans[i] << endl;
    }
}