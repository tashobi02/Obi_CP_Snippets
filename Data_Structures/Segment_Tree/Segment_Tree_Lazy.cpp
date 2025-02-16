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
vector<lli> arr(N);
#define lc (2 * node)
#define rc ((2 * node) + 1)
struct SegmentTree {
    vector<lli> st, lazy;
    SegmentTree(lli n) {
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
    // Lazy propagation: Push pending updates to children
    inline void push(lli node, lli b, lli e) {
        if (lazy[node] == 0)
            return;
        st[node] += lazy[node] * (e - b + 1);
        if (b != e) {
            lazy[lc] += lazy[node];
            lazy[rc] += lazy[node];
        }
        lazy[node] = 0;
    }
    inline lli combine(lli a, lli b) { return a + b; }
    inline void pull(lli node) { st[node] = st[lc] + st[rc]; }
    void build(lli node, lli b, lli e) {
        lazy[node] = 0;
        if (b == e) {
            st[node] = arr[b];
            return;
        }
        lli mid = (b + e) / 2;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(node);
    }
    void update(lli node, lli b, lli e, lli i, lli j, lli v) {
        push(node, b, e);
        if (j < b || e < i)
            return;
        if (i <= b && e <= j) {
            lazy[node] = v;
            push(node, b, e);
            return;
        }
        lli mid = (b + e) / 2;
        update(lc, b, mid, i, j, v);
        update(rc, mid + 1, e, i, j, v);
        pull(node);
    }
    lli query(lli node, lli b, lli e, lli i, lli j) {
        push(node, b, e);
        if (i > e || b > j)
            return 0;
        if (i <= b && e <= j)
            return st[node];
        lli mid = (b + e) / 2;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} st(N);
void soln() {
    lli n;
    cin >> n;
    for (lli i = 1; i <= n; i++) cin >> arr[i];
    st.build(1, 1, n);
    cout << "Initial Segment Tree: ";
    for (lli i = 1; i < (2 * n); i++) cout << st.st[i] << " ";
    cout << endl;
    lli q;
    cin >> q;
    while (q--) {
        lli x, y;
        cin >> x >> y;
        cout << "Query [" << x << ", " << y << "] -> "
             << st.query(1, 1, n, x, y) << endl;
    }
    cin >> q;
    while (q--) {
        lli i, j, x;
        cin >> i >> j >> x;
        st.update(1, 1, n, i, j, x);
        cout << "Segment Tree after update [" << i << ", " << j << "] with "
             << x << ": ";
        for (lli i = 1; i < (2 * n); i++) cout << st.st[i] << " ";
        cout << endl;
    }
}
int main() {
    fast();
    lli t = 1;
    while (t--) soln();
    return 0;
}
