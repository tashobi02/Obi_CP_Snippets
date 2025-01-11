#include <bits/stdc++.h>
using namespace std;
// Iterators are objects that are used to access elements of a container.
int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        v.push_back(e);
    }
    // .begin() points to the first element of the vector
    // .end() points to the last element of the vector
    vector<int>::iterator it;
    it = v.begin();
    for (it = v.begin(); it != v.end(); it++) {
        cout << (*it) << " ";
    }
    // another for loop variation
    // range based loops
    for (int value : v) {
        cout << value << " ";
    }
}