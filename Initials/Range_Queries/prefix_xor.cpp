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
    vector<lli> xorSum(n);
    xorSum[0] = arr[0];
    for (lli i = 0; i < n - 1; i++) xorSum[i + 1] = xorSum[i] ^ arr[i + 1];
    // for (lli i = 0; i < n; i++) cout << xorSum[i] << " ";
    // cout << enl;
    while (queries--) {
        lli a, b;
        cin >> a >> b;
        cout << (xorSum[b - 1] ^ xorSum[a - 1] ^ arr[a - 1]) << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //