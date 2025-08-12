#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
vector<lli> arr;
vector<lli> merge(vector<lli>& l, vector<lli>& r) {
    lli n = l.size(), m = r.size();
    vector<lli> ans;
    lli i = 0, j = 0;
    while (i < n && j < m) {
        if (l[i] < r[j])
            ans.push_back(l[i++]);
        else
            ans.push_back(r[j++]);
    }
    while (i < n)
        ans.push_back(l[i++]);
    while (j < n)
        ans.push_back(r[j++]);
    return ans;
}
vector<lli> mergeSort(lli l, lli r) {
    if (l == r)
        return {arr[l]};
    lli mid = (l + r) >> 1;
    vector<lli> left = mergeSort(l, mid);
    vector<lli> right = mergeSort(mid + 1, r);
    return merge(left, right);
}
void soln() {
    lli n;
    cin >> n;
    arr.resize(n);
    for (lli i = 0; i < n; i++)
        cin >> arr[i];
    vector<lli> ans = mergeSort(0, n - 1);
    for (lli i = 0; i < n; i++)
        cout << ans[i] << " ";
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--)
        soln();
}
// Author: tashobi_02 //