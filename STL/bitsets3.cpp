#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/* let's say you have to distinct numbers in an array that is between
1 to 1e9 and you have to find it as fast as possible.
set, map still would be slow in this case
*/
void soln() {
    lli n;
    cin >> n;
    bitset<1000000001> vis;
    for (lli i = 0; i < n; i++) {
        lli x;
        cin >> x;
        vis[x] = true;
    }
    cout << vis.count() << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //