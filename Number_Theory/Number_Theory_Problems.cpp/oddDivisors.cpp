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

void primeFactor() {
    iota(pF.begin(), pF.end(), 0);
    for (lli i = 2; i * i < N; i++) {
        if (pF[i] == i) {
            for (lli j = i * i; j < N; j += i) {
                if (pF[j] == j)
                    pF[j] = i;
            }
        }
    }
}

lli countOddDivisors(lli n) {
    unordered_map<lli, lli> primeFactorization;s
    lli original_n = n;

    while (n > 1) {
        lli sp = pF[n];
        primeFactorization[sp]++;
        n /= sp;
    }

    lli oddDivisors = 1;
    for (auto &[prime, exponent] : primeFactorization) {
        if (prime != 2) {
            oddDivisors *= (exponent + 1);
        }
    }

    return oddDivisors;
}

void soln() {
    lli n;
    cin >> n;
    cout << countOddDivisors(n) << enl;
}

int main() {
    fast();
    primeFactor();
    lli t = 1;
    while (t--) soln();
    return 0;
}
