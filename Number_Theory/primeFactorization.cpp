#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e7 + 10;
vector<lli> pF(N);
// Precomputing all smallest prime factors from 1 to N
// Complexity: **O(N log log N)**
void primeFactor() {
    iota(pF.begin(), pF.end(), 0);  // Fill pF[i] with i
    for (lli i = 2; i * i < N; i++) {
        if (pF[i] == i) {  // `i` is a prime
            for (lli j = i * i; j < N; j += i) {
                if (pF[j] == j)
                    pF[j] = i;  // Mark smallest prime factor
            }
        }
    }
}
void soln() {
    lli n;
    cin >> n;
    unordered_map<lli, lli> primeFactorization;
    while (n > 1) {
        lli sp = pF[n];  // Smallest prime factor
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
    lli t;
    // cin >> t;
    while (t--) soln();
    return 0;
}
// Author: tashobi_02 //
