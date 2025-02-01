#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// How to check if a number is a <= 1e100000 and it is divisible by b <= 1e9
void soln() {
    string a;
    lli b;
    cin >> a >> b;
    lli n = a.size();
    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        ans = (ans * 10 + (a[i] - '0')) % b;
    }
    if (ans == 0)
        cout << "Yes" << enl;
    else
        cout << "No" << enl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //