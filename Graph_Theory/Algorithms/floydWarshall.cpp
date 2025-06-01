#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
#define INF LLONG_MAX
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void floydWarshall(vector<vector<lli>> &dist, lli n) {
    for (lli k = 1; k <= n; k++) {
        for (lli i = 1; i <= n; i++) {
            for (lli j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
void soln() {
    lli n, m, q;
    cin >> n >> m >> q;
    vector<vector<lli>> dist(n + 1, vector<lli>(n + 1, INF));
    for (lli i = 0; i < m; i++) {
        lli u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for (lli i = 1; i <= n; i++) dist[i][i] = 0;
    floydWarshall(dist, n);
    while (q--) {
        lli s, e;
        cin >> s >> e;
        if (dist[s][e] == INF)
            cout << -1 << enl;
        else
            cout << dist[s][e] << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
