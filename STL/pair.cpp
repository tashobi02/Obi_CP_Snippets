#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    // Pair is a container that stores two values of different data types or
    // same types. Pair provides a way to store two heterogeneous objects as a
    // single unit. Pair can be assigned, copied and compared.
    pair<lli, string> p1;
    p1 = {2, "abcd"};
    cout << p1.first << " " << p1.second << endl;
    // Using iterators to access the first and second elements of the pair.
    pair<lli, lli> p2;
    cin >> p2.first >> p2.second;
    // This way you can input the values of the pair.
    cout << "p2.first: " << p2.first << " "
         << "p2.second: " << p2.second << endl;
    pair<lli, bool> p3 = {3, true};
    // You can combine different data types in a pair.
    cout << p3.first << " " << p3.second << endl;
}