#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// pre-computing all prime numbers from 1 to N
// Complexity O(Nloglog(N))
const lli N = 1e7 + 10;
bool isPrime[N];
lli lp[N], hp[N];
void sievePrime() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false, isPrime[1] = false;
    for (lli i = 2; i <= N; i++) {
        if (isPrime[i]) {
            lp[i] = i, hp[i] = i;
            for (lli j = i * 2; j <= N; j += i) {
                isPrime[j] = false;
                if (lp[j] == 0)
                    lp[j] = i;
                hp[j] = i;
            }
        }
    }
}
void soln() {
    lli n;
    cin >> n;
    cout << isPrime[n] << enl;
}
int main() {
    fast();
    sievePrime();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //