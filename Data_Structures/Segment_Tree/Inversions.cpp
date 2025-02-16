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
/* Given an array of integers a1, a2, a3, ...., an, find the
number of pairs 1 <= j <= n such that ai > aj.
Constraints 1 <= n <= 1e5 and 1 <= ai <= 1e9. */
void soln() {
    lli n;
    cin >> n;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++) cin >> arr[i];
    orderedSet<lli> os;
    lli ct = 0;
    for (lli i = 0; i < n; i++) {
        ct += os.order_of_key(arr[i]);
        os.insert(arr[i]);
    }
    cout << ct << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
