#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

struct Node {
    Node* links[2];
    Node() { links[0] = links[1] = nullptr; }
    bool containsKey(int bit) { return links[bit] != nullptr; }
    void put(int bit, Node* node) { links[bit] = node; }
    Node* get(int bit) { return links[bit]; }
};

class Trie {
   private:
    Node* root;

   public:
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(vector<int>& arr) {
    Trie trie;
    for (auto& it : arr) {
        trie.insert(it);
    }
    int maxI = 0;
    for (auto& it : arr) {
        maxI = max(maxI, trie.getMax(it));
    }
    return maxI;
}

void soln() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxXOR(arr) << enl;
}

int main() {
    fast();
    lli t = 1;
    while (t--) soln();
    return 0;
}
// Author: tashobi_02 //
