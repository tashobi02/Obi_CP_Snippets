#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e5 + 10;
vector<vector<lli>> graph(N);
vector<bool> visited(N, false);
vector<lli> discovery(N, 0), finishing(N, 0), parent(N, -1);
map<pair<lli, lli>, string> edgeType;
lli tct = 0;
void classify_edge(lli u, lli v) {
    if (!visited[v]) {
        edgeType[{u, v}] = "Tree Edge";
    } else if (finishing[v] == 0) {
        edgeType[{u, v}] = "Back Edge";
    } else if (discovery[u] < discovery[v]) {
        edgeType[{u, v}] = "Forward Edge";
    } else {
        edgeType[{u, v}] = "Cross Edge";
    }
}
void DFS(lli v, vector<pair<lli, lli>>& edges) {
    visited[v] = true;
    discovery[v] = ++tct;
    cout << v << " ";
    for (lli neighbor : graph[v]) {
        classify_edge(v, neighbor);
        if (!visited[neighbor]) {
            parent[neighbor] = v;
            DFS(neighbor, edges);
        }
    }
    finishing[v] = ++tct;
}
void soln() {
    lli n, e;
    cin >> n >> e;
    for (lli i = 1; i <= n; i++) {
        graph[i].clear();
        visited[i] = false;
        discovery[i] = finishing[i] = 0;
        parent[i] = -1;
    }
    edgeType.clear();
    vector<pair<lli, lli>> edges;
    for (lli i = 0; i < e; i++) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        edges.emplace_back(u, v);
    }
    cout << "Adjacency List:" << enl;
    for (lli i = 1; i <= n; i++) {
        cout << i << ": ";
        for (lli j : graph[i]) {
            cout << j << " ";
        }
        cout << enl;
    }
    cout << "DFS order: ";
    for (lli i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i, edges);
        }
    }
    cout << enl;
    cout << "Timestamps of Vertex(discovery/finishing):" << enl;
    for (lli i = 1; i <= n; i++) {
        cout << i << "(" << discovery[i] << "/" << finishing[i] << ")" << enl;
    }
    cout << "Edge classification:" << enl;
    for (auto& [u, v] : edges) {
        cout << u << " " << v << ": " << edgeType[{u, v}] << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
    return 0;
}
