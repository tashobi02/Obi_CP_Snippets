#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Using Kahn's algorithm
vector<lli> topologicalSort(vector<vector<lli>> &lis, lli v) {
    vector<lli> inDegree(v, 0);
    for (lli i = 0; i < v; i++) {
        for (auto j : lis[i]) {
            inDegree[j]++;
        }
    }
    queue<lli> q;
    for (lli i = 0; i < v; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<lli> ans;
    while (!q.empty()) {
        lli node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto j : lis[node]) {
            inDegree[j]--;
            if (inDegree[j] == 0) {
                q.push(j);
            }
        }
    }
    if ((lli)ans.size() != v) {
        return {};
    }
    return ans;
}
void soln() {
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> lis(n);
    for (lli i = 0; i < m; i++) {
        lli u, v;
        cin >> u >> v;
        lis[u].push_back(v);
    }
    vector<lli> ans = topologicalSort(lis, n);
    if (ans.empty()) {
        // Graph Contains Cycle, cannot be sorted
        cout << "[ ]" << enl;
        return;
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
