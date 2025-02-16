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
    vector<lli> st;
    SegmentTree(lli n) { st.resize(4 * n, 0); }
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
    lli query(lli node, lli b, lli e, lli i, lli j) {
        if (b > j || e < i)
            return -inf;
        if (b >= i && e <= j)
            return st[node];
        lli mid = (b + e) / 2;
        return query(lc, b, mid, i, j) + query(rc, mid + 1, e, i, j);
    }
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
        lli i, x;
        cin >> i >> x;
        st.update(1, 1, n, i, x);
        cout << "Segment Tree after update [" << i << "] with " << x << ": ";
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
// Author: tashobi_02 //
