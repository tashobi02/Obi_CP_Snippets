#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n, n1, n2;
    lli p1 = 2, p2 = 5;
    cin >> n;
    n1 = n2 = n;
    lli z1 = 0, z2 = 0;
    while (n1) {
        z1 += n1 / p1;
        n1 /= p1;
    }
    while (n2) {
        z2 += n2 / p2;
        n2 /= p2;
    }
    cout << min(z1, z2) << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //