#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
struct custom_hash {
    static lli splitmix64(lli x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(lli x) const {
        static const lli FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<lli, lli, custom_hash> gp;
void soln() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++) {
        cin >> a[i];
        gp[a[i]]++;
    }
    for (lli i = 0; i < n; i++) {
        if (gp.find(a[i]) != gp.end()) {
            cout << "Element: " << a[i] << " has frequency: " << gp[a[i]] << endl;
            gp.erase(a[i]);
        }
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //