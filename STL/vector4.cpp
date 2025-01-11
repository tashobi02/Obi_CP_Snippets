#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
void soln() {
    // Here we will see more direct and basic operations of vector
    // Insertions
    vector<lli> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    cout << "Vector after push_back: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
    // Resize
    vec.resize(5);
    cout << "Vector after resize to 5: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
    // Empty
    cout << "Is vector empty? " << (vec.empty() ? "Yes" : "No") << enl;
    // Operator[]
    cout << "Element at index 1 using operator[]: " << vec[1] << enl;
    // At
    cout << "Element at index 1 using at(): " << vec.at(1) << enl;
    // Front
    cout << "First element using front(): " << vec.front() << enl;
    // Back
    cout << "Last element using back(): " << vec.back() << enl;
    // Begin
    cout << "First element using begin(): " << *vec.begin() << enl;
    // End
    cout << "Element past the end using end(): " << *(vec.end() - 1) << enl;
    // Rbegin
    cout << "Last element using rbegin(): " << *vec.rbegin() << enl;
    // Rend
    cout << "Element before the first using rend(): " << *(vec.rend() - 1)
         << enl;
    // Insert
    vec.insert(vec.begin() + 1, 10);
    cout << "Vector after insert at position 1: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
    // Erase
    vec.erase(vec.begin() + 1);
    cout << "Vector after erase at position 1: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
    // Swap
    vector<lli> vec2 = {7, 8, 9};
    vec.swap(vec2);
    cout << "Vector after swap with vec2: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
    // Clear
    vec.clear();
    cout << "Vector after clear: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
    // Emplace
    vec.emplace(vec.begin(), 5);
    cout << "Vector after emplace at begin: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
    // Emplace_back
    vec.emplace_back(6);
    cout << "Vector after emplace_back: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
    // Assign
    vec.assign(3, 4);
    cout << "Vector after assign 3 elements of value 4: ";
    for (lli v : vec) cout << v << " ";
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //