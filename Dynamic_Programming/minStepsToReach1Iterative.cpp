#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
lli steps[N];
void soln() {
    memset(steps, -1, sizeof steps);
    lli n;
    cin >> n;
    steps[1] = 0;
    for (lli i = 2; i <= n; i++) {
        lli ans = steps[i - 1] + 1;
        if (i % 2 == 0)
            ans = min(ans, steps[i / 2] + 1);
        if (i % 3 == 0)
            ans = min(ans, steps[i / 3] + 1);
        steps[i] = ans;
    }
    cout << steps[n] << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //