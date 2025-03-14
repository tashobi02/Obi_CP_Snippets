#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
lli getSum(vector<lli>& BITree, lli ix) {
    lli sum = 0;
    ix++;
    while (ix > 0) {
        sum += BITree[ix];
        ix -= ix & (-ix);
    }
    return sum;
}
void updateBIT(vector<lli>& BITree, lli n, lli ix, lli val) {
    ix++;
    while (ix <= n) {
        BITree[ix] += val;
        ix += ix & (-ix);
    }
}
vector<lli> constructBITree(vector<lli>& arr, lli n) {
    vector<lli> BITree(n + 1, 0);
    for (lli i = 0; i < n; i++) updateBIT(BITree, n, i, arr[i]);
    return BITree;
}
void soln() {
    lli n, q;
    cin >> n >> q;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++) cin >> arr[i];
    vector<lli> BITree = constructBITree(arr, n);
    while (q--) {
        lli f;
        cin >> f;  // f = 1 -> update value, f = 2 -> getSum of a range
        if (f == 1) {
            lli ix, x;
            cin >> ix >> x;
            ix--;  // if 1 based
            lli diff = x - arr[ix];
            arr[ix] = x;
            updateBIT(BITree, n, ix, diff);
        } else if (f == 2) {
            lli l, r;
            cin >> l >> r;
            l--, r--;  // if 1 based
            lli ans = getSum(BITree, r) - getSum(BITree, l - 1);
            cout << ans << enl;
        }
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
    return 0;
}
// Author: tashobi_02 //
