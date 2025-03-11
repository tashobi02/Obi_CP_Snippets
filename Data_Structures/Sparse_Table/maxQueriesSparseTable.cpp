#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 2e6 + 10;
const lli M = 21;  // log2(N) ≈ 21
vector<vector<lli>> table(N, vector<lli>(M, 0));
void buildSparseTable(vector<lli>& arr, lli n) {
    for (lli i = 0; i < n; i++) table[i][0] = arr[i];
    for (lli j = 1; (1 << j) <= n; j++) {
        for (lli i = 0; (i + (1 << j) - 1) < n; i++) {
            table[i][j] =
                max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}
void soln() {
    lli n, q;
    cin >> n >> q;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++) cin >> arr[i];
    buildSparseTable(arr, n);
    while (q--) {
        lli l, r;
        cin >> l >> r;
        l--, r--;  // Convert to 0-based indexing
        lli p = (lli)log2(r - l + 1);
        lli k = (1 << p);
        lli ans = max(table[l][p], table[r - k + 1][p]);
        cout << ans << enl;
    }
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
    return 0;
}
