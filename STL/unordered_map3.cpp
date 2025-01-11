#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, string> umap;  // Complexity O(1)
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        umap[key] =
            "Value" + to_string(key);  // Assign a value (e.g., Value<key>)
    }

    // Print the elements of the unordered_map
    cout << "Elements in unordered_map: " << endl;
    for (const auto& pr : umap) {
        cout << pr.first << " -> " << pr.second << endl;
    }
    cout << endl;

    /* A bucket in unordered_map is a logical grouping of elements based on
     * their hash values. */

    // bucket_count() - Returns the total number of buckets in the hash table
    cout << "Total number of buckets: " << umap.bucket_count() << endl;

    // bucket(key) - Returns the bucket index of a specific key
    cout << "Bucket index for each element:" << endl;
    for (const auto& pr : umap) {
        cout << "Key " << pr.first << " is in bucket " << umap.bucket(pr.first)
             << endl;
    }
    cout << endl;

    // bucket_size(n) - Returns the number of elements in the nth bucket
    cout << "Bucket sizes:" << endl;
    for (size_t i = 0; i < umap.bucket_count(); i++) {
        cout << "Bucket " << i << " has " << umap.bucket_size(i) << " elements"
             << endl;
    }
    cout << endl;

    // load_factor() - Returns the average number of elements per bucket
    cout << "Load factor: " << umap.load_factor() << endl;

    // max_load_factor() - Returns or sets the maximum load factor
    cout << "Max load factor: " << umap.max_load_factor() << endl;

    // rehash(n) - Resizes the number of buckets to at least n while
    // redistributing the elements
    umap.rehash(2 * umap.bucket_count());
    cout << "Total number of buckets after rehash: " << umap.bucket_count()
         << endl;

    // Check bucket index after rehash
    cout << "Bucket index after rehash:" << endl;
    for (const auto& pr : umap) {
        cout << "Key " << pr.first << " is in bucket " << umap.bucket(pr.first)
             << endl;
    }
}

// Sample Case 1:
/* 40
59 80 14 77 48 92 43 14 92 64 43 18 13 74 88 75 76 73 81 31 12 98 31 12 70 34 62
21 94 46 82 49 76 22 21 56 38 81 34 10
*/
