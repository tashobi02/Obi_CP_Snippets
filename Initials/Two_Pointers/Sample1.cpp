#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Constant Window
/* Imagine an array of n size and an integer k. You are asked to find
the maximum possible sum of consecutive k elements from the array.
Brute force solution would be O(n*k)
*/
void soln() {
    lli n, k;
    cin >> n >> k;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++) cin >> arr[i];
    // Calculate the sum of the first k elements
    lli sum = 0;
    for (lli i = 0; i < k; i++) sum += arr[i];
    lli mx = sum;
    lli l, r;  // l = left, r = right
    // Slide the window and calculate sums
    for (lli i = 1; i <= n - k; i++) {
        l = i - 1;
        r = i + k - 1;
        sum = sum - arr[l] + arr[r];
        mx = max(mx, sum);
    }
    cout << mx << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //