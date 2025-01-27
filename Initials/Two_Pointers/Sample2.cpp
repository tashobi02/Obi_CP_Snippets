#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
// Largest Subarray type
/* Imagine a array of size n and an int k, you are asked
to find the length of subarray of which maximum possible sum is
lesser than k
*/
void soln() {
    lli n, k;
    cin >> n >> k;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++) cin >> arr[i];
    lli maxLen = 0, sum = 0, l = 0;
    // r = right, l = left
    for (lli r = 0; r < n; r++) {
        sum += arr[r];
        // Shrink the window if sum exceeds k
        while (sum > k) {
            sum -= arr[l];
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }
    cout << maxLen << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //