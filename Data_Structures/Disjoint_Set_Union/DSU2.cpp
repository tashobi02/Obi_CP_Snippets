#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
const lli N = 1e5 + 10;
lli parent[N];
lli rank_[N];
void make(lli v) {
    parent[v] = v;
    rank_[v] = 0;
}
lli find(lli v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);  // Path Compression
}
void Union(lli a, lli b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank_[a] <= rank_[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
        }
        if (rank_[a] == rank_[b]) {
            rank_[b]++;
        }
    }
}
void print_parent(lli n) {
    for (lli i = 0; i < n; i++) {
        cout << parent[i] << "(" << rank_[i] << ") ";
    }
    cout << endl;
}
int main() {
    fast();
    lli n;
    cin >> n;
    for (lli i = 0; i < n; i++) {
        make(i);
    }
    while (true) {
        lli type;
        cin >> type;
        if (type == 1) {
            print_parent(n);
        } else if (type == 2) {
            lli x;
            cin >> x;
            cout << find(x) << endl;
        } else if (type == 3) {
            lli u, v;
            cin >> u >> v;
            Union(u, v);
            print_parent(n);
        } else if (type == 4) {
            print_parent(n);
        } else {
            break;
        }
    }
    return 0;
}
