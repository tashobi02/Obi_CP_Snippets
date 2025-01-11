#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Multisets are a type of associative containers similar to the set, with
    the exception that multiple elements can have the same values. */
    int n;
    cin >> n;
    multiset<int> mst;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        mst.insert(e);
    }

    // Print the elements of mst
    cout << "Elements in multiset: ";
    for (const auto& e : mst) {
        cout << e << " ";
    }
    cout << endl;

    // begin() – Returns an iterator to the first element in the multiset
    cout << "First element: " << *mst.begin() << endl;

    // end() – Returns an iterator to the theoretical element that follows the
    // last element in the multiset
    cout << "Last element: " << *prev(mst.end()) << endl;

    // size() – Returns the number of elements in the multiset
    cout << "Size of multiset: " << mst.size() << endl;

    // max_size() – Returns the maximum number of elements that the multiset can
    // hold
    cout << "Max size of multiset: " << mst.max_size() << endl;

    // empty() – Returns whether the multiset is empty
    cout << "Is multiset empty? " << (mst.empty() ? "Yes" : "No") << endl;

    // insert(x) – Inserts the element x in the multiset
    mst.insert(5);
    cout << "Elements in multiset after inserting 5: ";
    for (const auto& e : mst) {
        cout << e << " ";
    }
    cout << endl;

    // clear() – Removes all the elements from the multiset
    mst.clear();
    cout << "Elements in multiset after clear: ";
    for (const auto& e : mst) {
        cout << e << " ";
    }
    cout << endl;
    cout << "Size of multiset after clear: " << mst.size() << endl;

    // insert elements again for erase demonstration
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        mst.insert(e);
    }

    // erase(x) – Removes all the occurrences of x
    mst.erase(5);
    cout << "Elements in multiset after erasing 5: ";
    for (const auto& e : mst) {
        cout << e << " ";
    }
    cout << endl;
}