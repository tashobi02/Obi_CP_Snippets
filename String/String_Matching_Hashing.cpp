#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

const lli BASE = 99991;  // Large Prime Number
const lli M = 1e9 + 9;

// Implementation of Rabin-Karp Algorithm
lli RK(const string& text, const string& pattern) {
    lli T = text.size();
    lli P = pattern.size();
    // Precomputing powers of BASE modulo M
    vector<lli> powers(max(T, P));
    powers[0] = 1;
    for (lli i = 1; i < (lli)powers.size(); i++) {
        powers[i] = (powers[i - 1] * BASE) % M;
    }
    // for (auto px : powers) {
    //  cout << px << " ";
    // }
    // cout << enl;
    // Computing prefix hashes for the text
    vector<lli> hash(T + 1, 0);
    for (lli i = 0; i < T; i++) {
        hash[i + 1] = (hash[i] + (text[i] - 'a' + 1) * powers[i]) % M;
    }
    // for (auto hh : hash) {
    //  cout << hh << " ";
    // }
    // cout << enl;
    // Computing hash of the pattern
    lli pattern_hash = 0;
    for (lli i = 0; i < P; i++) {
        pattern_hash = (pattern_hash + (pattern[i] - 'a' + 1) * powers[i]) % M;
    }
    // cout << pattern_hash << enl;
    // Counting occurrences of the pattern in the text
    lli count = 0;
    for (lli i = 0; i + P - 1 < T; i++) {
        lli current_hash = (hash[i + P] + M - hash[i]) % M;
        // cout << current_hash << enl;
        if (current_hash == pattern_hash * powers[i] % M) {
            count++;
        }
    }
    return count;
}

void soln() {
    string text, pattern;
    cin >> text >> pattern;
    lli ans = RK(text, pattern);
    cout << ans << enl;
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
    return 0;
}
// Author: tashobi_02 //
