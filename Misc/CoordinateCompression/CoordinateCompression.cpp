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
    set<lli> se;
    for (auto x : arr)
        se.insert(x);
    map<lli, lli> mp;
    lli id = 0;
    for (auto x : se) {
        mp[x] = ++id;
    }
    for (lli i = 0; i < n; i++) {
        arr[i] = mp[arr[i]];
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