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
lli countDivisorsOfFactorial(lli n) {
    lli divisorCount = 1;
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
        // Apply divisor function formula: (e1 + 1) * (e2 + 1) * ...
        divisorCount *= (exponent + 1);
    }
    return divisorCount;
}
void soln() {
    lli n;
    cin >> n;
    cout << countDivisorsOfFactorial(n) << enl;
}
int main() {
    fast();
    sievePrime();
    lli t;
    cin >> t;
    while (t--) soln();
    return 0;
}
