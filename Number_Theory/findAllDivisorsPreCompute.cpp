#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// finding all divisors of a number in a optimized way
// you can also pre-ccompute them upto 1e6
const lli N = 1e6 + 10;
vector<vector<lli>> divisors(N);
void findAllDivisors() {
    for (lli i = 1; i < N; i++) {
        for (lli j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }
}
void soln() {
    lli n;
    cin >> n;
    for (auto x : divisors[n]) {
        cout << x << " ";
    }
    cout << enl;
}
int main() {
    fast();
    findAllDivisors();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //