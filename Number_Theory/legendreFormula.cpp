#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/* Given an integer n and a prime number p, find the largest x such
that p^x divides n! (x is called the order of n! with respect to p) */
void soln() {
    lli n, p;
    cin >> n >> p;
    lli ans = 0;
    while (n) {
        ans += n / p;
        n /= p;
    }
    cout << ans << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //