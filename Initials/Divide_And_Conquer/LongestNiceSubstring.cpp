#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
string longestNiceSubstring(string s) {
    lli sz = s.size();
    if (sz < 2)
        return "";
    set<char> sc;
    for (lli i = 0; i < sz; i++)
        sc.insert(s[i]);
    for (lli i = 0; i < sz; i++) {
        char c = s[i];
        if (sc.find(tolower(c)) != sc.end() && sc.find(toupper(c)) != sc.end()) {
            continue;
        }
        string s1 = longestNiceSubstring(s.substr(0, i));
        string s2 = longestNiceSubstring(s.substr(i + 1));
        return s1.size() >= s2.size() ? s1 : s2;
    }
    return s;
}
void soln() {
    string s;
    cin >> s;
    cout << longestNiceSubstring(s) << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //