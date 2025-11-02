#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// 8 possible directions
// Minimal steps to reach to bottom right from top left avoiding obstacles
lli fx[] = {+1, -1, +0, +0, +1, +1, -1, -1};
lli fy[] = {+0, +0, +1, -1, +1, -1, +1, -1};
lli n, m;
bool valid(lli nx, lli ny) {
    return nx >= 0 && ny >= 0 && nx < n && ny < m;
}
void soln() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (lli i = 0; i < n; i++)
        for (lli j = 0; j < m; j++)
            cin >> grid[i][j];
    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
        cout << -1 << enl;
        return;
    }
    queue<pair<lli, lli>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (lli dir = 0; dir < 8; dir++) {
            lli nx = x + fx[dir];
            lli ny = y + fy[dir];
            if (valid(nx, ny) && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << dist[n - 1][m - 1] << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
