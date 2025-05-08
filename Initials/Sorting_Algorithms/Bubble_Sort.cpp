#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void bubbleSort(lli arr[], lli n) {
    for (lli i = 0; i < n - 1; i++) {
        for (lli j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void soln() {
    lli n;
    cin >> n;
    lli arr[n];
    for (lli i = 0; i < n; i++) cin >> arr[i];
    bubbleSort(arr, n);
    for (lli i = 0; i < n; i++) cout << arr[i] << " ";
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //