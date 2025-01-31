#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/* The sigma function of a positive integer n is the sum of the positive
  divisors of n. This is usually σ(n) using the greek letter sigma. */
// Complexity: O(sqrt(n)*log(k))
lli sigma(lli n, lli k) {
    lli sum = 1;
    for (lli i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            lli tempSum = 1, term = 1;
            while (n % i == 0) {
                n /= i;
                term *= pow(i, k);
                tempSum += term;
            }
            sum *= tempSum;
        }
    }
    if (n > 1)
        sum *= (1 + pow(n, k));
    return sum;
}
void soln() {
    lli n, k;
    cin >> n >> k;
    cout << sigma(n, k) << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //