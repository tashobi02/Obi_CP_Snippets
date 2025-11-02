#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// 4-direction movement arrays
// Counting the number of connected islands
lli fx[] = {+1, -1, +0, +0};
lli fy[] = {+0, +0, +1, -1};
lli n, m;
vector<vector<char>> grid;
vector<vector<bool>> vis;
bool valid(lli x, lli y) {
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == '1');
}
void DFS(lli x, lli y) {
    vis[x][y] = true;
    for (lli dir = 0; dir < 4; dir++) {
        lli nx = x + fx[dir];
        lli ny = y + fy[dir];
        if (valid(nx, ny))
            dfs(nx, ny);
    }
}
void soln() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    lli islands = 0;
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                dfs(i, j);
                islands++;
            }
        }
    }
    cout << islands << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
