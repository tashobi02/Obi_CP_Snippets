#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
#define INF 1e18
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
vector<vector<pair<lli, lli>>> adj(N);
vector<bool> visited(N, false);
priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>> pq;
lli Prims(lli vertices, lli edges, vector<vector<lli>>& edgeList) {
    for (lli i = 0; i < vertices; i++) {
        adj[i].clear();
        visited[i] = false;
    }
    while (!pq.empty())
        pq.pop();
    for (lli i = 0; i < edges; i++) {
        lli u = edgeList[i][0] - 1;
        lli v = edgeList[i][1] - 1;
        lli w = edgeList[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    lli ans = 0;
    lli visCt = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        ans += cost;
        visCt++;
        for (auto [neighbor, weight] : adj[u]) {
            if (!visited[neighbor]) {
                pq.push({weight, neighbor});
            }
        }
    }
    if (visCt != vertices) {
        cout << "IMPOSSIBLE" << enl;
        return -1;
    }
    return ans;
}
void soln() {
    lli v, e;
    cin >> v >> e;
    vector<vector<lli>> edges(e, vector<lli>(3));
    for (lli i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    lli mstCost = Prims(v, e, edges);
    if (mstCost != -1)
        cout << mstCost << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
