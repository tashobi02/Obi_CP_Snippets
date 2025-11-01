#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Longest increasing subsequence
void soln() {
    lli n;
    cin >> n;
    vector<lli> arr(n + 1), dp(n + 1);
    arr[0] = 0, dp[0] = 0;
    for (lli i = 1; i <= n; i++)
        cin >> arr[i];
    for (lli i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (lli j = 1; j < i; j++) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    lli ans = 0;
    for (lli i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans + 1 << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //