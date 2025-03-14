#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/* A (n*m) grid where you can traverse through if there are 0's and 1's
are blocks, your job is to find if you can reach from top left to bottom right
*/
vector<lli> dx = {1, -1, 0, 0};
vector<lli> dy = {0, 0, 1, -1};
bool canReach(vector<vector<lli>> &grid) {
    lli n = grid.size(), m = grid[0].size();
    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        return false;
    queue<pair<lli, lli>> q;
    q.push({0, 0});
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1)
            return true;
        for (lli d = 0; d < 4; d++) {
            lli nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0 &&
                !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}
void soln() {
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> grid(n, vector<lli>(m));
    for (lli i = 0; i < n; i++)
        for (lli j = 0; j < m; j++) cin >> grid[i][j];
    cout << (canReach(grid) ? "YES" : "NO") << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //