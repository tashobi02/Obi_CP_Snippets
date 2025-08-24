#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Function to find modular inverse of a with respect to m using Extended Euclidean Algorithm
lli inv(lli a, lli m) {
    lli m0 = m, t, q;
    lli x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}
// Chinese Remainder Theorem: Finds the smallest x that satisfies all given congruences
lli findMinX(vector<lli>& num, vector<lli>& rem, lli k) {
    lli prod = 1;
    for (lli i = 0; i < k; i++)
        prod *= num[i];

    lli result = 0;
    for (lli i = 0; i < k; i++) {
        lli pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
    return result % prod;
}
void soln() {
    lli n;
    cin >> n;
    vector<lli> num(n), rem(n);
    for (lli i = 0; i < n; i++)
        cin >> num[i];
    for (lli i = 0; i < n; i++)
        cin >> rem[i];
    cout << findMinX(num, rem, n) << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //
