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
vector<vector<lli>> graph(N);
void printPath(lli node) {
    vector<lli> path;
    while (node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for (lli i = 0; i < (lli)path.size(); i++) {
        if (i > 0)
            cout << "->";
        cout << path[i];
    }
    cout << enl;
}
void BFS(lli start, vector<pair<lli, lli>> &BFSTree) {
    queue<lli> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    cout << "BFS Order: ";
    while (!q.empty()) {
        lli v = q.front();
        cout << v << " ";
        q.pop();
        for (lli neighbor : graph[v]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = v;
                dist[neighbor] = dist[v] + 1;
                BFSTree.push_back({v, neighbor});
            }
        }
    }
    cout << enl;
}
void soln() {
    lli n, e, s;
    cin >> n >> e >> s;
    for (lli i = 1; i <= n; i++) {
        graph[i].clear();
        visited[i] = false;
        parent[i] = -1;
        dist[i] = -1;
    }
    vector<pair<lli, lli>> BFSTree;
    for (lli i = 0; i < e; i++) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << "Adjacency List:" << enl;
    for (lli i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto j : graph[i]) {
            cout << j << " ";
        }
        cout << enl;
    }
    BFS(s, BFSTree);
    cout << "Distance from source:" << enl;
    for (lli i = 1; i <= n; i++) cout << i << "(" << dist[i] << ") ";
    cout << enl;
    cout << "Paths from source:" << enl;
    for (lli i = 1; i <= n; i++) {
        if (dist[i] != -1) {
            cout << i << ": ";
            printPath(i);
        }
    }
    cout << "Edges of BFS tree:" << enl;
    for (auto edge : BFSTree) cout << edge.first << " " << edge.second << enl;
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
