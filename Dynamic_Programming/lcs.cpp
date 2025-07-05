#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 3030;
string a, b;
lli dp[N][N];
lli lcs(lli i, lli j) {
    if (i >= (lli)a.size() || j >= (lli)b.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    lli ans = lcs(i + 1, j);
    ans = max(ans, lcs(i, j + 1));
    if (a[i] == b[j]) {
        ans = max(ans, lcs(i + 1, j + 1) + 1);
    }
    return dp[i][j] = ans;
}
void soln() {
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << lcs(0, 0) << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //