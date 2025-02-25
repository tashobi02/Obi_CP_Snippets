#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) { return (links[ch - 'a']) != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void endMark() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie {
   private:
    Node* root;

   public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < (int)word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->endMark();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < (int)word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < (int)prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

    void display(Node* curr, string prefix) {
        if (curr->isEnd()) {
            cout << prefix << " ";
        }
        for (int i = 0; i < 26; i++) {
            if (curr->links[i] != NULL) {
                char nextChar = i + 'a';
                display(curr->links[i], prefix + nextChar);
            }
        }
    }

    void displayAll() { display(root, ""); }
};

void soln() {
    Trie trie;
    string line;

    getline(cin, line);
    stringstream ss1(line);
    string word;
    while (ss1 >> word) {
        trie.insert(word);
    }
    trie.displayAll();
    cout << endl;
    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> word) {
        cout << (trie.search(word) ? "T" : "F") << " ";
    }
    cout << endl;
}

int main() {
    fast();
    lli t = 1;
    while (t--) soln();
}
// Author: tashobi_02 //
