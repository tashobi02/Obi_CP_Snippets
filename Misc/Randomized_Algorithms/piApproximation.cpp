#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli ct = 0;
    lli T = 10000000;
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_real_distribution<long double> dist(-1.0, 1.0);
    for (lli i = 0; i < T; i++) {
        long double a = dist(rng);
        long double b = dist(rng);
        long double sp = (a * a) + (b * b);
        if (sp <= 1.0L)
            ct++;
    }
    long double pi = 4.0L * ct / (long double)T;
    cout << setprecision(10) << fixed << pi << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
