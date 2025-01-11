#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_set<int> ust;  // Complexity O(1)
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        ust.insert(e);
    }

    // Print the elements of ust
    cout << "Elements in unordered_set: ";
    for (const auto& e : ust) {
        cout << e << " ";
    }  // The order of the elements is not sorted but in insertion order
    cout << endl;
    cout << "size: " << ust.size() << endl;
    int e;
    cin >> e;
    ust.insert(e);
    cout << "Elements in unordered_set: ";
    for (const auto& e : ust) {
        cout << e << " ";
    }
    cout << endl;
    cout << "size: " << ust.size() << endl;
}