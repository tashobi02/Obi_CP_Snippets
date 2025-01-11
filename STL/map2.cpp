#include <bits/stdc++.h>
using namespace std;
void print(map<int, string> &m) {
    cout << m.size() << endl;
    for (auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
}
int main() {
    map<int, string> m;
    int n;
    cin >> n;
    // In map, you can do independent indexing
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x;
        cin >> s;
        m[x] = s;
    }
    int e;
    cin >> e;
    auto it = m.find(e);  // O(log(n))
    if (it == m.end()) {
        cout << "No value" << endl;
    } else {
        cout << it->first << " " << it->second << endl;
    }
    print(m);
}