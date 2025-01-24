#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

/*
You are given an array of n - 1 integers which are in the range between 1 and n.
All numbers appear exactly once, except one number, which is missing. Find this
missing number.
*/

void soln() {
    lli n;
    cin >> n;
    vector<lli> nums(n - 1);
    for (lli i = 0; i < n - 1; i++) cin >> nums[i];

    lli xor_find = 0;

    // XOR all numbers from 1 to n
    for (lli i = 1; i <= n; i++) {
        xor_find ^= i;
    }

    // XOR all elements in the array
    for (lli i = 0; i < n - 1; i++) {
        xor_find ^= nums[i];
    }

    cout << xor_find << enl;  // Result is the missing number
}

int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}
// Author: tashobi_02 //
