#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    vector<pair<int, int> > v_p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        v_p.push_back(pair<int, int>(x1, x2));
    }
    for (auto it = v_p.begin(); it != v_p.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    // (*it).first <=> (it->first)
    // (*it).second <=> (it->second)
    for (auto &value : v_p) {
        cout << value.first << " " << value.second << endl;
    }
}