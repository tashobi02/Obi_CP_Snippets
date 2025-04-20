#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
lli const N = 2e5 + 10;
vector<lli> color(N);
vector<lli> parent(N);
bool cycle;
void DFS(lli u, vector<vector<lli>> &g) {
    color[u] = 1;
    for (auto v : g[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            DFS(v, g);
        } else if (color[v] == 1) {
            cycle = true;
        }
    }
    color[u] = 2;
}
void soln() {
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> graph(n + 1);
    for (lli i = 0; i < m; i++) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    cycle = false;
    for (lli i = 1; i <= n; i++) {
        if (color[i] == 0)
            DFS(i, graph);
    }
    cout << (cycle ? "YES" : "NO") << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //