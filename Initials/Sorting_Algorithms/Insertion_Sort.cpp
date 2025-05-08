#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void insertionSort(lli arr[], lli n) {
    for (lli i = 1; i < n; i++) {
        lli x = arr[i];
        lli j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
void soln() {
    lli n;
    cin >> n;
    lli arr[n];
    for (lli i = 0; i < n; i++) cin >> arr[i];
    insertionSort(arr, n);
    for (lli i = 0; i < n; i++) cout << arr[i] << " ";
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //