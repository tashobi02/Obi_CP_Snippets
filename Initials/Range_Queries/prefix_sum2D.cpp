#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n, m, queries;
    cin >> n >> m >> queries;
    vector<vector<lli>> grid(n, vector<lli>(m));
    for (lli i = 0; i < n; i++)
        for (lli j = 0; j < m; j++) cin >> grid[i][j];
    vector<vector<lli>> gridSum(n, vector<lli>(m));
    gridSum[0][0] = grid[0][0];
    // Updating only the first row and column
    for (lli i = 1; i < m; i++) gridSum[0][i] = gridSum[0][i - 1] + grid[0][i];
    for (lli i = 1; i < n; i++) gridSum[i][0] = gridSum[i - 1][0] + grid[i][0];
    for (lli i = 1; i < n; i++) {
        for (lli j = 1; j < m; j++) {
            gridSum[i][j] = gridSum[i - 1][j] + gridSum[i][j - 1] -
                            gridSum[i - 1][j - 1] + grid[i][j];
        }
    }
    // for (lli i = 0; i < n; i++) {
    //     for (lli j = 0; j < m; j++) {
    //         cout << gridSum[i][j] << " ";
    //     }
    //     cout << enl;
    // }
    while (queries--) {
        lli x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // Convert 1-based to 0-based indexing
        x1--, y1--, x2--, y2--;
        lli ans = gridSum[x2][y2];
        if (x1 > 0)
            ans -= gridSum[x1 - 1][y2];
        if (y1 > 0)
            ans -= gridSum[x2][y1 - 1];
        if (x1 > 0 && y1 > 0)
            ans += gridSum[x1 - 1][y1 - 1];
        cout << ans << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //