#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/* Euler's phi function (which may be also called Euler's totient function) is a
function that gives us the number of positive integers less or equal to a given
integer n that are coprime to n. */
const lli N = 1e7 + 10;
vector<lli> phi(N);
void computeTotient() {
    iota(phi.begin(), phi.end(), 0);
    for (lli i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (lli j = i; j < N; j += i) {
                phi[j] = (phi[j] * (i - 1)) / i;
            }
        }
    }
}
void soln() {
    lli n;
    cin >> n;
    cout << phi[n] << enl;
}
int main() {
    fast();
    computeTotient();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
    return 0;
}

// Author: tashobi_02 //
/*
╧ò(1) = 1
╧ò(2) = 1
╧ò(3) = 2
╧ò(4) = 2
╧ò(5) = 4
╧ò(6) = 2
╧ò(7) = 6
╧ò(8) = 4
╧ò(9) = 6
╧ò(10) = 4
*/