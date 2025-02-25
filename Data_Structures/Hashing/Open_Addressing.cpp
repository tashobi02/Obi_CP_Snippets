#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

class HashTable {
   private:
    vector<lli> table;
    lli size, ct, cc;

    lli hash1(lli x) { return x % size; }
    lli hash2(lli x) { return 7 - (x % 7); }

    lli probe(lli x, lli i) {
        if (cc == 1)
            return (hash1(x) + i) % size;
        if (cc == 2)
            return (hash1(x) + i * i) % size;
        if (cc == 3)
            return (hash1(x) + i * hash2(x)) % size;
        return -1;
    }

   public:
    HashTable(lli cc, lli sz) : cc(cc), size(sz), ct(0) {
        table.assign(sz, -1);
    }

    void insert(lli x) {
        lli i = 0;
        while (i < 6) {
            lli index = probe(x, i);
            if (table[index] == -1) {
                table[index] = x;
                ct++;
                cout << "Inserted : Index - " << index << " (L.F = " << fixed
                     << setprecision(3) << (double)ct / size << ")" << enl;
                return;
            } else {
                cout << "Collision: Index - " << index << enl;
            }
            i++;
        }
        cout << "Input Abandoned" << enl;
    }
};

void soln() {
    lli cc, sz, q;
    cin >> cc >> sz >> q;
    HashTable hashTable(cc, sz);
    while (q--) {
        lli x;
        cin >> x;
        hashTable.insert(x);
    }
}

int main() {
    fast();
    lli t = 1;
    while (t--) soln();
    return 0;
}
// Author: tashobi_02 //
