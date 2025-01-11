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
    }
    cout << endl;
    /* a bucket is a logical grouping of elements within the hash table. Hash
    tables distribute elements into multiple buckets based on the hash value of
     the element */
    // bucket_count() - Returns the total number of buckets in the hash table
    cout << "Total number of buckets: " << ust.bucket_count() << endl;

    // bucket(key) - Returns the bucket index of a specific key or element
    for (const auto& e : ust) {
        cout << "Element " << e << " is in bucket " << ust.bucket(e) << endl;
    }

    // bucket_size(n) - Returns the number of elements in the nth bucket
    for (size_t i = 0; i < ust.bucket_count(); i++) {
        cout << "Bucket " << i << " has " << ust.bucket_size(i) << " elements"
             << endl;
    }

    // load_factor() - Returns the average number of elements per bucket
    cout << "Load factor: " << ust.load_factor() << endl;

    // rehash(n) - Resizes the number of buckets to at least n while
    // redistributing the elements
    ust.rehash(2 * ust.bucket_count());
    cout << "Total number of buckets after rehash: " << ust.bucket_count()
         << endl;
    for (const auto& e : ust) {
        cout << "Element " << e << " is in bucket " << ust.bucket(e) << endl;
    }
}

// Sample Case 1:
/* 40
59 80 14 77 48 92 43 14 92 64 43 18 13 74 88 75 76 73 81 31 12 98 31 12 70 34 62
21 94 46 82 49 76 22 21 56 38 81 34 10
*/