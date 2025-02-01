#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n;
    cin >> n;
    lli x = (lli)sqrt(n);
    lli y = (lli)sqrt(n / 2);
    lli res = x + y;
    cout << n - res << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    lli ti = 1;
    while (t--) {
        cout << "Case " << ti++ << ": ";
        soln();
    }
}
// Author: tashobi_02 //