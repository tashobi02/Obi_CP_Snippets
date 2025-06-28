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
lli parent[N];
lli rank_[N];
void make(lli v) {
    parent[v] = v;
    rank_[v] = 0;
}
lli find(lli v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]); // path compression
}
void Union(lli a, lli b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank_[a] < rank_[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
            if (rank_[a] == rank_[b]) {
                rank_[a]++;
            }
        }
    }
}
bool comparator(const vector<lli>& a, const vector<lli>& b) {
    return a[2] < b[2]; // ascending by weight
}
lli KruskalsMST(lli v, vector<vector<lli>>& edges) {
    sort(edges.begin(), edges.end(), comparator);
    lli cost = 0, ct = 0;
    for (auto& e : edges) {
        lli u = e[0], vv = e[1], w = e[2];
        if (find(u) != find(vv)) {
            Union(u, vv);
            cost += w;
            ct++;
            if (ct == v - 1)
                break;
        }
    }
    if (ct < v - 1)
        return -1; // Graph is disconnected
    return cost;
}
int main() {
    fast();
    lli v, e;
    cin >> v >> e;
    for (lli i = 0; i <= v; i++)
        make(i); // 1-based nodes
    vector<vector<lli>> edges;
    for (lli i = 0; i < e; i++) {
        lli u, vv, w;
        cin >> u >> vv >> w;
        edges.push_back({u, vv, w});
    }
    lli cost = KruskalsMST(v, edges);
    if (cost == -1)
        cout << "IMPOSSIBLE" << enl;
    else
        cout << cost << endl;
    return 0;
}
// Author: tashobi_02