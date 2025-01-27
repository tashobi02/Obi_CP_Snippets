#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
lli binary_search(vector<lli> vec, lli lo, lli hi, lli x) {
    while (lo <= hi) {
        lli mid = lo + (hi - lo) / 2;
        if (vec[mid] == x)
            return mid;
        else if (vec[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}
lli lower_bound(vector<lli>& v, lli e) {
    lli lo = 0, hi = v.size() - 1;
    lli mid;
    while (lo <= hi) {
        lli mid = lo + (hi - lo) / 2;
        if (v[mid] < e)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    if (v[lo] >= e)
        return lo;
    if (v[hi] >= e)
        return hi;
    return -1;
}
lli upper_bound(vector<lli>& v, lli e) {
    lli lo = 0, hi = v.size() - 1;
    lli mid;
    while (lo <= hi) {
        lli mid = lo + (hi - lo) / 2;
        if (v[mid] <= e)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    if (v[lo] >= e)
        return lo;
    if (v[hi] >= e)
        return hi;
    return -1;
}
void soln() {
    lli n;
    cin >> n;
    vector<lli> vec(n);
    for (lli i = 0; i < n; i++) cin >> vec[i];
    lli x;
    cin >> x;
    lli y = binary_search(vec, 0, n - 1, x);
    cout << y << endl;
}
int main() {
    fast();
    lli t = 1;
    cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
