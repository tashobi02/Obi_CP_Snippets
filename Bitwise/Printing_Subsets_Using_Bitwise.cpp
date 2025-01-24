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
    for (lli i = 0; i < n; i++) cin >> arr[i];
    lli subsets = 1 << n;
    for (lli i = 0; i < subsets; i++) {
        vector<lli> list;
        for (lli j = 0; j < n; j++) {
            if (i & (1 << j)) {
                list.push_back(arr[j]);
            }
        }
        for (lli x : list) {
            cout << x << " ";
        }
        cout << enl;
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //