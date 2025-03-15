#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
vector<lli> pi_array(string pattern) {
    lli n = pattern.length();
    vector<lli> pi(n);
    pi[0] = 0;
    for (lli i = 1; i < n; i++) {
        pi[i] = 0;
        lli j = pi[i - 1];
        while (j > 0 && pattern[j] != pattern[i]) {
            j = pi[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            pi[i] = j + 1;
        }
    }
    return pi;
}

void soln() {
    string text, match;
    cin >> text >> match;
    lli ct = 0;
    lli m = match.size();
    string merged = match + '#' + text;
    vector<lli> pi = pi_array(merged);
    for (lli x : pi) {
        cout << x << " ";
        if (x == m)
            ct++;
    }
    // cout << enl;
    cout << ct << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //