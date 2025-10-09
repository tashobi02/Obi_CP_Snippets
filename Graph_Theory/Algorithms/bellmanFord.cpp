#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
#define INF 1e18
const lli N = 2e6 + 10;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
vector<tuple<lli, lli, lli>> edges; // {u, v, weight}
vector<lli> dist(N + 1, INF);
bool bellmanFord(lli n, lli start) {
    dist[start] = 0;
    for (lli i = 1; i < n; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // Detect negative cycle
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false; // Negative cycle found
        }
    }
    return true;
}
void soln() {
    lli n, m;
    cin >> n >> m;
    edges.clear();
    fill(dist.begin(), dist.begin() + n + 1, INF);
    for (lli i = 0; i < m; i++) {
        lli u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    lli start = 1; // default starting node
    if (bellmanFord(n, start)) {
        for (lli i = 1; i <= n; i++) {
            if (dist[i] != INF)
                cout << dist[i] << " ";
        }
    } else {
        cout << "Negative weight cycle detected!" << enl;
    }
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}

// Author: tashobi_02 //
