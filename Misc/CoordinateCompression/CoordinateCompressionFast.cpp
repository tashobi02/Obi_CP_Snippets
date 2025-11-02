#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    lli n;
    cin >> n;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++)
        cin >> arr[i];
    vector<lli> v = arr;
    sort(v.begin(), v.end());
    // [9, 9, 10, 10, 100]
    // unique -> [9, 10, 100, 9, 10]
    // v.resize(3) -> [9, 10, 100]
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (lli i = 0; i < n; i++) {
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
        cout << arr[i] << " ";
    }
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //