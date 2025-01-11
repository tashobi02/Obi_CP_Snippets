#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Maps are associative containers that store elements in a mapped fashion.
    Each element has a key value and a mapped value. No two mapped values can
    have the same key values. */
    map<int, string> m;

    // Insert elements
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4, "afg"});
    m.insert({6, "xyz"});  // Another way to insert

    // Iterate and print map elements
    cout << "Map elements:\n";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    // Demonstrate find() function
    cout << "\nUsing find():\n";
    auto it = m.find(5);
    if (it != m.end()) {
        cout << "Found key 5 with value: " << it->second << endl;
    } else {
        cout << "Key 5 not found\n";
    }

    // Demonstrate count() function
    cout << "\nUsing count():\n";
    cout << "Count of key 3: " << m.count(3)
         << endl;  // Will be 1 since key exists
    cout << "Count of key 10: " << m.count(10)
         << endl;  // Will be 0 since key doesn't exist

    // Erase a key-value pair
    cout << "\nUsing erase():\n";
    m.erase(5);  // Remove key 5
    cout << "After erasing key 5:\n";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    // Demonstrate lower_bound() and upper_bound()
    cout << "\nUsing lower_bound() and upper_bound():\n";
    auto lb = m.lower_bound(3);  // First key >= 3
    if (lb != m.end()) {
        cout << "Lower bound of 3: " << lb->first << " " << lb->second << endl;
    }

    auto ub = m.upper_bound(3);  // First key > 3
    if (ub != m.end()) {
        cout << "Upper bound of 3: " << ub->first << " " << ub->second << endl;
    }

    // Size of the map
    cout << "\nSize of the map: " << m.size() << endl;

    // Check if map is empty
    cout << "Is the map empty? " << (m.empty() ? "Yes" : "No") << endl;

    return 0;
}
