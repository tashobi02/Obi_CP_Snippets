#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void selectionSort(lli arr[], lli n) {
    for (lli i = 0; i < n - 1; i++) {
        lli im = i;
        for (lli j = i + 1; j < n; j++) {
            if (arr[j] < arr[im])
                im = j;
        }
        if (im != i)
            swap(arr[i], arr[im]);
    }
}
void soln() {
    lli n;
    cin >> n;
    lli arr[n];
    for (lli i = 0; i < n; i++) cin >> arr[i];
    selectionSort(arr, n);
    for (lli i = 0; i < n; i++) cout << arr[i] << " ";
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}

// Author: tashobi_02 //