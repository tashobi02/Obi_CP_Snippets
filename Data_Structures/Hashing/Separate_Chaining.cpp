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
    lli size, itemCount = 0;
    vector<list<lli>> table;

    lli hashFunction(lli key) { return key % size; }

   public:
    HashTable(lli s) : size(s), table(s) {}

    void insert(lli key) {
        table[hashFunction(key)].push_front(key);
        itemCount++;
    }

    bool search(lli key) {
        for (lli num : table[hashFunction(key)]) {
            if (num == key)
                return true;
        }
        return false;
    }

    void remove(lli key) {
        table[hashFunction(key)].remove(key);
        itemCount--;
    }

    double getLoadFactor() { return (double)itemCount / size; }

    lli getMaxLoadFactor() {
        lli maxLen = 0;
        for (const auto& lst : table) {
            maxLen = max(maxLen, (lli)lst.size());
        }
        return maxLen;
    }

    void display() {
        for (lli i = 0; i < size; i++) {
            cout << i << ": ";
            for (lli num : table[i]) {
                cout << num << " -> ";
            }
            cout << "NULL" << enl;
        }
        cout << "Load Factor: " << fixed << setprecision(2) << getLoadFactor()
             << enl;
        cout << "Maximum Chain Length: " << getMaxLoadFactor() << enl;
    }
};

void soln() {
    lli n, m;
    cin >> n >> m;
    HashTable ht(n);

    for (lli i = 0; i < m; i++) {
        lli op;
        lli x;
        cin >> op >> x;
        if (op == 1)
            ht.insert(x);
        else if (op == 2)
            cout << (ht.search(x) ? "Found" : "Not Found") << enl;
        else if (op == 3)
            ht.remove(x);
    }
    ht.display();
}

int main() {
    fast();
    lli t = 1;
    while (t--) soln();
    return 0;
}
// Author: tashobi_02 //
