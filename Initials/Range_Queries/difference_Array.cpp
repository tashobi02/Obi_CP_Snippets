#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/* Given an array of N elements perform Q queries on it and print the final
array after performing all the queries. N <= 1e5, Q <= 1e5.
Every query is of the form Li, Ri, Xi.
The array is initialized to all zeroes. Add Xi form Li to Ri-th index and then
print the final array */
// Brute force soln is O(N*Q) which is inefficient
void soln() {
    lli n, queries;
    cin >> n >> queries;
    vector<lli> arr(n, 0);
    while (queries--) {
        lli l, r, x;
        cin >> l >> r >> x;
        // l--, r--; if 1 based index
        arr[l] += x;
        if (r + 1 < n)
            arr[r + 1] -= x;
    }
    vector<lli> pfs(n);
    pfs[0] = arr[0];
    for (lli i = 1; i < n; i++) pfs[i] = pfs[i - 1] + arr[i];
    for (lli i = 0; i < n; i++) cout << pfs[i] << " ";
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //