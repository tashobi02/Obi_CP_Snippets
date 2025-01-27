#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Longest substring with at most k distinct characters
void soln() {
    string s;
    cin >> s;
    lli n = s.size();
    lli k;
    cin >> k;
    lli ans = 0;
    lli l = 0, r = 0;
    unordered_map<char, lli> mp;
    while (r < n) {
        mp[s[r]]++;
        while ((lli)mp.size() > k) {
            mp[s[l]]--;
            if (mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        }
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