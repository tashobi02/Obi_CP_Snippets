#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
lli fib[N];
void soln() {
    memset(fib, -1, sizeof(fib));
    fib[0] = 0;
    fib[1] = 1;
    lli n;
    cin >> n;
    for (lli i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[n] << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //