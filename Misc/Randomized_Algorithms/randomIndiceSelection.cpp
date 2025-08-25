#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void soln() {
    lli n;
    // lli gm = -1;
    cin >> n;
    lli iters = 1000;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++)
        cin >> arr[i];
    vector<lli> indices(n);
    iota(indices.begin(), indices.end(), 0); // filling with 0, 1, 2, 3... n - 1
    for (lli i = 0; i < iters; i++) {
        shuffle(indices.begin(), indices.end(), rng);
        vector<lli> sl;
        for (lli i = 0; i < n / 2; i++) { // choosing first half
            sl.push_back(arr[indices[i]]);
        }
        // lli g = sl[0];
        cout << "Iteration " << i + 1 << ": ";
        for (const lli& val : sl) {
            //    g = __gcd(g, val);
            cout << val << " ";
        }
        // gm = max(gm, g);
        cout << enl;
    }
    // cout << gm << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //