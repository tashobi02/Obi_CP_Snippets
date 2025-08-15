#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
lli maxSubarraySum(vector<lli> arr, lli n) {
    lli res = arr[0];
    lli maxEnding = arr[0];
    for (lli i = 1; i < n; i++) {
        cout << res << " " << maxEnding << enl;
        maxEnding = max(arr[i], maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}
void soln() {
    lli n;
    cin >> n;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSubarraySum(arr, n) << enl;
}
int main() {
    fast();
    lli t = 1;
    //  cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //