#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e6 + 10;
const lli MOD = 1e9 + 7;
lli factorial[N], inverseFactorial[N], modInverse[N];
void preCalculate_nCr() {
    factorial[0] = 1;
    for (lli i = 1; i < N; i++)
        factorial[i] = (1LL * i * factorial[i - 1] % MOD);
    modInverse[1] = 1;
    for (lli i = 2; i < N; i++) {
        modInverse[i] = (-(1LL * (MOD / i))) * modInverse[MOD % i] % MOD;
        modInverse[i] = (modInverse[i] + MOD) % MOD;
    }
    inverseFactorial[0] = 1;
    for (lli i = 1; i < N; i++)
        inverseFactorial[i] =
            (1LL * modInverse[i] * inverseFactorial[i - 1] % MOD);
}
lli nCr(lli n, lli r) {
    if (n < r || n < 0 || r < 0)
        return 0;
    else
        return (1LL * factorial[n] * inverseFactorial[n - r] % MOD *
                inverseFactorial[r] % MOD);
}
lli nPr(lli n, lli r) {
    if (n < r || n < 0 || r < 0)
        return 0;
    return (1LL * nCr(n, r) * factorial[r] % MOD);
}

void soln() {
    lli n, r;
    cin >> n >> r;
    cout << nCr(n, r) << enl;
}
int main() {
    fast();
    preCalculate_nCr();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //