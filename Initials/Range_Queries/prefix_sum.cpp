#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n, queries;
    cin >> n >> queries;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++) cin >> arr[i];
    vector<lli> pfs(n);
    pfs[0] = arr[0];
    for (lli i = 0; i < n - 1; i++) {
        pfs[i + 1] = pfs[i] + arr[i + 1];
    }
    // for (lli i = 0; i < n; i++) cout << pfs[i] << " ";
    // cout << enl;
    while (queries--) {  // O(q)
        lli a, b;
        cin >> a >> b;
        cout << pfs[b - 1] - pfs[a - 1] + arr[a - 1] << enl;  // O(1)
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //