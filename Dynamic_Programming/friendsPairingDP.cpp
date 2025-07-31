#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// https://www.geeksforgeeks.org/dsa/friends-pairing-problem/
const lli N = 2e6 + 10;
lli dp[N];
lli fp(lli n) {
    if (dp[n] != -1)
        return dp[n];
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return dp[n] = fp(n - 1) + (n - 1) * fp(n - 2);
}
void soln() {
    memset(dp, -1, sizeof dp);
    lli n;
    cin >> n;
    cout << fp(n) << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //