#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e7 + 10;
vector<lli> arr(N);  // Input array (1-based indexing)
vector<lli> st(4 * N);
// Segment tree (4 times the size of arr for safe recursion)
// **Build function**: Constructs segment tree for range sum queries
void build(lli node, lli b, lli e) {
    if (b == e) {  // Leaf node case
        st[node] = arr[b];
        return;
    }
    lli l = 2 * node, r = 2 * node + 1;  // Left and right child indices
    lli mid = (b + e) / 2;
    build(l, b, mid);      // Build left subtree
    build(r, mid + 1, e);  // Build right subtree
    st[node] = st[l] + st[r];
}
// **Query function**: Returns the sum in range [i, j]
lli query(lli node, lli b, lli e, lli i, lli j) {
    if (b >= i && e <= j)
        return st[node];  // Fully inside range
    if (b > j || e < i)
        return 0;  // Completely outside range
    lli l = 2 * node, r = 2 * node + 1;
    lli mid = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
// **Update function**: Updates element at index i to x
void update(lli node, lli b, lli e, lli i, lli x) {
    if (b > i || e < i)
        return;              // Out of range, return
    if (b == e && b == i) {  // Leaf node update
        st[node] = x;
        return;
    }
    lli l = 2 * node, r = 2 * node + 1;
    lli mid = (b + e) / 2;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    st[node] = st[l] + st[r];  // Merge results after update
}
void soln() {
    lli n;
    cin >> n;
    for (lli i = 1; i <= n; i++) cin >> arr[i];  // Input array
    build(1, 1, n);                              // Build segment tree
    for (lli i = 0; i < (2 * n); i++) cout << st[i] << " ";
    cout << enl;
    lli q;
    cin >> q;
    while (q--) {
        lli x, y;
        cin >> x >> y;
        cout << query(1, 1, n, x, y) << enl;
    }
    cin >> q;
    while (q--) {
        lli i, x;
        cin >> i >> x;
        update(1, 1, n, i, x);
        for (lli i = 0; i < (2 * n); i++) cout << st[i] << " ";
        cout << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    while (t--) soln();
    return 0;
}
// Author: tashobi_02 //
