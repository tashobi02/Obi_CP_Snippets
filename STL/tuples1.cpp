#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    // Tuple is a container that can store multiple values of different data
    // types. Unlike a pair, a tuple can store more than two values.
    tuple<lli, string, double> t1;
    t1 = {1, "example", 3.14};
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;
    // You can access tuple elements using get<index>(tuple).

    // Using make_tuple to create a tuple.
    // Using auto to deduce the type of the tuple.
    /* auto is a keyword that tells the compiler to deduce the type of the
      variable */
    auto t2 = make_tuple(2, "sample", 42.0);
    cout << "t2: " << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2)
         << endl;

    // Modifying tuple elements using get<index>(tuple).
    get<0>(t2) = 5;  // Update the first element.
    get<1>(t2) = "updated";
    cout << "Updated t2: " << get<0>(t2) << " " << get<1>(t2) << " "
         << get<2>(t2) << endl;

    // Comparing tuples.
    tuple<lli, lli, lli> t3 = {1, 2, 3};
    tuple<lli, lli, lli> t4 = {1, 2, 4};
    cout << "t3 < t4: " << (t3 < t4) << endl;  // Compares lexicographically.

    // Unpacking tuple elements into separate variables.
    lli a;
    string b;
    double c;
    tie(a, b, c) = t1;  // `tie` extracts values from a tuple.
    cout << "Unpacked values from t1: " << a << " " << b << " " << c << endl;

    // Ignoring specific elements during unpacking using `ignore`.
    tie(a, b, ignore) = t1;  // Only unpack the first two elements.
    cout << "Partially unpacked values from t1: " << a << " " << b << endl;

    return 0;
}
