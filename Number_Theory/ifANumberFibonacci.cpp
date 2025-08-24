#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
bool isPerfectSquare(lli n) {
    lli root = sqrt(n);
    return (root * root == n);
}
bool isFibonacci(lli n) {
    if (n == 0)
        return true;
    lli a = 0, b = 1, c = 1;
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }
    return (c == n || isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4));
}
void soln() {
    lli n;
    cin >> n;
    if (isFibonacci(n))
        cout << "YES" << enl;
    else
        cout << "NO" << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //