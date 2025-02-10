#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Precomputing all prime numbers from 1 to N
// Complexity O(N log log N)
const lli N = 1e7 + 10;
vector<bool> isPrime(N, true);
vector<lli> primes;
vector<lli> lp(N, 0), hp(N, 0);  // Remove these if space complexity occurs
void sievePrime() {
    isPrime[0] = false, isPrime[1] = false;
    for (lli i = 2; i <= N; i++) {
        if (isPrime[i]) {
            lp[i] = i, hp[i] = i;
            primes.push_back(i);
            for (lli j = i * 2; j <= N; j += i) {
                isPrime[j] = false;
                if (lp[j] == 0)
                    lp[j] = i;
                hp[j] = i;
            }
        }
    }
}
bool isPrimeL(lli n) {
    if (n < N)
        return isPrime[n];
    for (lli p : primes) {
        if (p * p > n)
            break;
        if (n % p == 0)
            return false;
    }
    return true;
}
void soln() {
    lli n;
    cin >> n;
    if (n > N)
        cout << (isPrimeL(n) ? "YES" : "NO") << enl;
    else
        cout << (isPrime[n] ? "YES" : "NO") << enl;
}
int main() {
    fast();
    sievePrime();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
    return 0;
}
// Author: tashobi_02 //
