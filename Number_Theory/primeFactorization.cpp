#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e7 + 10;
lli pF[N];
// pre-computing all prime factors from 1 to N
// Complexity O(Nlog(N))
void primeFactor() {
    for (lli i = 2; i < N; i++) pF[i] = i;
    for (lli i = 2; i < N; i++)
        for (lli j = i; j < N; j += i) pF[j] = min(pF[j], i);
}
void soln() {
    lli n;
    cin >> n;
    unordered_map<lli, lli> primeFactorization;
    while (n > 1) {
        lli sp = pF[n];
        primeFactorization[sp]++;
        n /= sp;
    }
    for (auto& [prime, exponent] : primeFactorization) {
        cout << prime << "^" << exponent << " ";
    }
    cout << enl;
}
int main() {
    fast();
    primeFactor();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //