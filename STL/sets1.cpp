#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Sets are a type of associative container in which each element has to be
     unique because the value of the element identifies it. */
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        st.insert(e);
    }
    for (const auto& s : st) {
        cout << s << " "; /* This will only show the distinct elements in
                          sorted order */
    }
    cout << endl;
    cout << "size: " << st.size() << endl;
    set<int, greater<int>> st2(
        st.begin(), st.end());  // st will be in st2 but in reverse order
    for (const auto& s : st2) {
        cout << s << " "; /* This will reverse the order of the elements */
    }
    cout << endl;

    // Show lower bound and upper bound for st
    int val;
    cout << "Enter value to find lower and upper bounds: ";
    cin >> val;
    auto lb_st = st.lower_bound(val);
    auto ub_st = st.upper_bound(val);
    cout << "Lower bound in st: "
         << (lb_st != st.end() ? to_string(*lb_st) : "Not found") << endl;
    cout << "Upper bound in st: "
         << (ub_st != st.end() ? to_string(*ub_st) : "Not found") << endl;

    // Show lower bound and upper bound for st2
    auto lb_st2 = st2.lower_bound(val);
    auto ub_st2 = st2.upper_bound(val);
    cout << "Lower bound in st2: "
         << (lb_st2 != st2.end() ? to_string(*lb_st2) : "Not found") << endl;
    cout << "Upper bound in st2: "
         << (ub_st2 != st2.end() ? to_string(*ub_st2) : "Not found") << endl;

    //  usage of swap
    set<int> st3 = {10, 20, 30};
    cout << "Set st3 before swap: ";
    for (const auto& s : st3) {
        cout << s << " ";
    }
    cout << endl;
    st.swap(st3);
    cout << "Set st after swap: ";
    for (const auto& s : st) {
        cout << s << " ";
    }
    cout << endl;
    cout << "Set st3 after swap: ";
    for (const auto& s : st3) {
        cout << s << " ";
    }
    cout << endl;

    // erase function
    st.erase(st.begin());
    cout << "Set st after erase: ";
    for (const auto& s : st) {
        cout << s << " ";
    }
    cout << endl;
    cout << "Size of st after erase: " << st.size() << endl;
}