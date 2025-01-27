#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// find the length of longest substring without repeating characters
void soln() {
    string s;
    cin >> s;
    lli n = s.size();
    lli ans = 0;
    lli l = 0, r = 0;
    unordered_map<char, lli> mp;
    while (r < n) {
        if (mp.find(s[r]) != mp.end()) {
            l = max(l, mp[s[r]] + 1);
        }
        mp[s[r]] = r;
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //