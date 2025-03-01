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
void DFS(lli v, vector<vector<lli>>& graph) {
    visited[v] = true;
    cout << v << " ";
    for (auto next = graph[v].begin(); next != graph[v].end(); ++next) {
        if (!visited[*next])
            DFS(*next, graph);
    }
}
int main() {
    fast();
    lli n, e;  // n = nodes, e = edges
    cin >> n >> e;
    vector<vector<lli>> graph(n + 1);
    lli nodes, neighbor;
    for (lli i = 0; i < e; i++) {
        cin >> nodes >> neighbor;
        graph[nodes].push_back(neighbor);
        graph[neighbor].push_back(nodes);
    }
    lli start;
    cin >> start;
    DFS(start, graph);
    return 0;
}
// Author: tashobi_02 //
