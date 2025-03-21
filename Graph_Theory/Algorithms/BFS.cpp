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
void BFS(lli start, vector<vector<lli>>& graph) {
    queue<lli> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        lli v = q.front();
        cout << v << " ";
        q.pop();
        for (auto i = graph[v].begin(); i != graph[v].end(); ++i) {
            if (!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}
int main() {
    fast();
    lli n, e;
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
    BFS(start, graph);
    return 0;
}

// Author: tashobi_02 //
