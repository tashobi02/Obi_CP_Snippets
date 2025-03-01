#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e5 + 10;
vector<bool> visited(N, false);
vector<lli> parent(N, -1);
vector<lli> dist(N, -1);
void BFS(lli start, vector<vector<lli>>& graph) {
    queue<lli> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    while (!q.empty()) {
        lli v = q.front();
        q.pop();
        for (lli neighbor : graph[v]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = v;
                dist[neighbor] = dist[v] + 1;
            }
        }
    }
}
void soln() {
    lli n, e;
    cin >> n >> e;
    vector<vector<lli>> graph(n + 1);
    for (lli i = 0; i < e; i++) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    lli start;
    cin >> start;
    BFS(start, graph);
    for (lli i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
