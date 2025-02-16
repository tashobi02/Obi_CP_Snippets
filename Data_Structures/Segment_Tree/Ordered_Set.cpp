#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
#define enl "\n"

template <typename T>
using orderedSet =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/*
find_by_order(k) → Returns an iterator to the k-th (0-based) smallest element.
order_of_key(x) → Returns the count of elements strictly smaller than x.
*/
void soln() {
    orderedSet<lli> os;
    lli n;
    cin >> n;
    for (lli i = 0; i < n; i++) {
        lli x;
        cin >> x;
        os.insert(x);
    }
    // Print elements in sorted order
    cout << "Ordered Set Elements: ";
    for (auto x : os) cout << x << " ";
    cout << enl;
    cout << "2nd smallest element: " << *os.find_by_order(1) << enl;
    cout << "Elements < 5: " << os.order_of_key(5) << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
