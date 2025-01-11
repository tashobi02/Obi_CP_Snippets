#include <bits/stdc++.h>
using namespace std;

// Function to print the contents of the unordered_map
void print(unordered_map<int, string> &m) {
    cout << "Unordered Map Size: " << m.size() << endl;
    for (auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
    cout << endl;
}

int main() {
    /* an unordered_map is like a data structure of dictionary type that stores
    elements in itself. It contains successive pairs (key, value), which
    allows fast retrieval of an individual element based on its unique key */
    unordered_map<int, string> m;

    // Insert elements into the unordered_map
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "xyz";

    // Find a specific key in the map
    auto it = m.find(5);  // O(1) average time complexity
    cout << "Finding key 5:\n";
    if (it == m.end()) {
        cout << "No value found for key 5" << endl;
    } else {
        cout << "Key 5 found: " << it->first << " " << it->second << endl;
    }
    cout << endl;

    // Check existence of a key using count()
    cout << "Using count() to check key existence:\n";
    if (m.count(3)) {
        cout << "Key 3 exists\n";
    } else {
        cout << "Key 3 does not exist\n";
    }
    if (m.count(10)) {
        cout << "Key 10 exists\n";
    } else {
        cout << "Key 10 does not exist\n";
    }
    cout << endl;

    // Erase an element by key
    cout << "Erasing key 3:\n";
    m.erase(3);  // O(1) average time complexity
    print(m);

    // Insert elements using insert()
    cout << "Inserting new key-value pair:\n";
    m.insert({10, "new_value"});
    print(m);

    // Access a value by key (creates the key if it doesn’t exist)
    cout << "Accessing and modifying key 2:\n";
    m[2] = "created";  // Creates key 2 and assigns value "created"
    cout << "Value for key 2: " << m[2] << endl;
    print(m);

    // Check if unordered_map is empty
    cout << "Checking if the map is empty: ";
    cout << (m.empty() ? "Yes" : "No") << endl;

    // Clear all elements
    cout << "Clearing the map:\n";
    m.clear();
    cout << "Size after clear: " << m.size() << endl;

    return 0;
}
