#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    // Vector can be formed using any data types like arrays;
    vector<string> vs = {"Hello", "World", "!"};
    cout << "Size: " << vs.size() << enl;
    for (lli i = 0; i < (lli)vs.size(); i++) {
        cout << vs[i] << " ";
    }
    // Vector can be resized during initialization
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (lli i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    // You can also use stl sort function to sort the vector
    sort(a.begin(), a.end());  // Sorting the vector in ascending order
    for (lli i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    // You can also use stl reverse function to reverse the vector
    reverse(a.begin(), a.end());
    for (lli i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
