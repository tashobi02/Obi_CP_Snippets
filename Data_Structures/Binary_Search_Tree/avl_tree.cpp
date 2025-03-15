#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
struct Node {
    lli key;
    Node *left;
    Node *right;
    lli height;
    Node(lli k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};
lli height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *temp = x->right;
    // Starts rotation
    x->right = y;
    y->left = temp;
    // Save heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *temp = y->left;
    // Starts rotation
    y->left = x;
    x->right = temp;
    // Save heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
lli getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}
Node *insert(Node *node, lli key) {
    if (node == nullptr)
        return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    lli balance = getBalance(node);
    if (balance > 1 && key < node->left->key)  // LL
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)  // RR
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {  // LR
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {  // RL
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void soln() {
    Node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 35);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    preOrder(root);
    return;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
}