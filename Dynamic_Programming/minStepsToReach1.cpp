#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// You are given a number n
// You can do three operations
// n--, n/=2 (if n % 2 == 0), n/=3 (if n % 3 == 0)
// What are the number of minimum opeartions to reach 1 from n
const lli N = 2e6 + 10;
lli steps[N];
lli minSteps(lli n) {
    if (n == 1)
        return 0;
    if (steps[n] != -1)
        return steps[n];
    lli ans = minSteps(n - 1) + 1;
    if (n % 2 == 0) {
        ans = min(ans, minSteps(n / 2) + 1);
    }
    if (n % 3 == 0) {
        ans = min(ans, minSteps(n / 3) + 1);
    }
    steps[n] = ans;
    return steps[n];
}
void soln() {
    memset(steps, -1, sizeof(steps));
    lli n;
    cin >> n;
    cout << minSteps(n) << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //  