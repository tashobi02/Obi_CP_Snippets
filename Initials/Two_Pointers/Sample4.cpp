#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/* In a array of 0 and 1, find the maximum consecutive 1's and you can flip 0 to
   1 k times */
void soln() {
    lli n, k;
    cin >> n >> k;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++) cin >> a[i];
    lli l = 0, r = 0, ans = 0, zeros = 0;
    while (r < n) {
        if (a[r] == 0)
            zeros++;
        while (zeros > k) {
            if (a[l] == 0)
                zeros--;
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //