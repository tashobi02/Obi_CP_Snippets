#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e7 + 10;
vector<bool> visited(N);
vector<lli> color(N);
bool ok;
void DFS(lli v, vector<vector<lli>>& graph) {
    visited[v] = true;
    // cout << v << " ";
    for (auto next = graph[v].begin(); next != graph[v].end(); ++next) {
        if (!visited[*next]) {
            color[*next] = color[v] ^ 1;
            DFS(*next, graph);
        } else {
            if (color[*next] == color[v])
                ok = false;
        }
    }
}
void soln() {
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> graph(n + 1);
    while (m--) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ok = true;
    lli start;
    cin >> start;
    DFS(start, graph);
    for (lli i = 1; i <= n; i++) {
        if (!visited[i])
            DFS(i, graph);  // if the graph is not connected
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //