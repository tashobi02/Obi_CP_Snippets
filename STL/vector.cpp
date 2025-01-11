#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
// Vectors are like arrays but they can be resized
// and have many more functions
// They are also slower than arrays
// but offers more flexibility
int main() {
    vector<lli> v = {1, 2, 3, 4, 5};
    cout << "Size: " << v.size() << endl;
    cout << "Max size: " << v.max_size() << endl;
    // max_size is the maximum number of elements that the vector can hold
    for (lli i = 0; i < (lli)v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    v.push_back(6);  // add 6 to the end of the vector
    cout << "Size: " << v.size() << endl;
    auto it = v.begin();  // iterator pointing to the beginning of the vector
    auto it2 = v.end();   // iterator pointing to the end of the vector
    cout << "First element: " << *it << endl;
    cout << "Last element: " << *(it2 - 1) << endl;
    v.pop_back();  // remove the last element of the vector
    v.pop_back();  // again popping
    cout << "Size: " << v.size() << endl;
    auto it3 = v.end();  // iterator pointing to the end of the vector
    cout << "Last element: " << *(it3 - 1) << endl;
}
