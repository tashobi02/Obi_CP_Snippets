#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e6 + 10;
vector<lli> primes;
vector<bool> isPrime(N, true);
void sievePrime() {
    isPrime[0] = isPrime[1] = false;
    for (lli i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (lli j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
void soln() {
    lli n;
    cin >> n;
    unordered_map<lli, lli> primeFactorization;
    for (lli prime : primes) {
        if (prime > n)
            break;
        lli exponent = 0, power = prime;
        while (power <= n) {
            exponent += n / power;
            if (power > n / prime)
                break;
            power *= prime;
        }
        if (exponent > 0) {
            primeFactorization[prime] = exponent;
        }
    }
    lli z = 0, sz = primeFactorization.size();
    for (auto& [prime, exponent] : primeFactorization) {
        cout << prime << "(" << exponent << ")";
        z++;
        if (z < sz)
            cout << " * ";
    }
    cout << enl;
}
int main() {
    fast();
    sievePrime();
    lli t;
    cin >> t;
    lli ti = 1;
    while (t--) {
        cout << "Case " << ti++ << ": ";
        soln();
    }
    return 0;
}
