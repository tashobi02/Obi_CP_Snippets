#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
lli dp[N];
lli fib(lli n) {
    if (dp[n] != -1)
        return dp[n];
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}
void soln() {
    memset(dp, -1, sizeof(dp));
    lli n;
    cin >> n;
    cout << fib(n) << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //