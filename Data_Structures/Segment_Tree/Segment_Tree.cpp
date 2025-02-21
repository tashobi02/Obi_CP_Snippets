#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e7 + 10;
const lli inf = LLONG_MAX;
vector<lli> arr(N);  // Input array (1-based indexing)
vector<lli> st(4 * N);
// Segment tree (4 times the size of arr for safe recursion)
// **Build function**: Constructs segment tree for range sum queries
// For segment tree:
#define lc (2 * node)
#define rc ((2 * node) + 1)
void build(lli node, lli b, lli e) {
    if (b == e) {
        st[node] = arr[b];
        return;
    }
    lli mid = (b + e) / 2;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    st[node] = st[lc] + st[rc];
}
// **Query function**: Returns the sum in range [i, j]
lli query(lli node, lli b, lli e, lli i, lli j) {
    if (b >= i && e <= j)
        return st[node];
    if (b > j || e < i)
        return 0;
    lli mid = (b + e) / 2;
    return query(lc, b, mid, i, j) + query(rc, mid + 1, e, i, j);
}
// **Update function**: Updates element at index i to x
void update(lli node, lli b, lli e, lli i, lli x) {
    if (b > i || e < i)
        return;
    if (b == e && b == i) {
        st[node] = x;
        return;
    }
    lli mid = (b + e) / 2;
    update(lc, b, mid, i, x);
    update(rc, mid + 1, e, i, x);
    st[node] = st[lc] + st[rc];
}
void soln() {
    lli n;
    cin >> n;
    for (lli i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    cout << "Initial Segment Tree: ";
    for (lli i = 0; i < (2 * n); i++) cout << st[i] << " ";
    cout << endl;
    lli q;
    cin >> q;
    while (q--) {
        lli x, y;
        cin >> x >> y;
        cout << query(1, 1, n, x, y) << endl;
    }
    cin >> q;
    while (q--) {
        lli i, x;
        cin >> i >> x;
        update(1, 1, n, i, x);
        for (lli i = 0; i < (2 * n); i++) cout << st[i] << " ";
        cout << endl;
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
