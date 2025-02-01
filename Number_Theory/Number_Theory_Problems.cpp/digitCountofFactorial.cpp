#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// digits of n!
void soln() {
    lli n;
    cin >> n;
    long double ct = 0;
    for (lli i = 1; i <= n; i++) {
        ct += log10(i);
    }
    cout << (lli)(ct + 1) << enl;
}
int main() {
    fast();
    lli t;
    cin >> t;
    while (t--) soln();
}
