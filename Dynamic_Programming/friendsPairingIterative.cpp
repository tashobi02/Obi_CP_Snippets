#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
lli fp[N];
void soln() {
    memset(fp, -1, sizeof fp);
    fp[1] = 1;
    fp[2] = 2;
    lli n;
    cin >> n;
    for (lli i = 3; i <= n; i++) {
        fp[i] = fp[i - 1] + (i - 1) * fp[i - 2];
    }
    cout << fp[n] << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //