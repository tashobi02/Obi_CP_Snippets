#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// finding all divisors of a number in a optimized way
void soln() {
    lli n;
    cin >> n;
    vector<lli> divisors;
    for (lli i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    for (auto x : divisors) cout << x << " ";
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //