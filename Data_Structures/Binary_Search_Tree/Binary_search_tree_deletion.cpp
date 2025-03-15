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
    Node* left;
    Node* right;
    Node* parent;
    Node(lli item) {
        key = item;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

Node* insert(Node* node, lli key) {
    if (node == NULL) {
        return new Node(key);
    }
    if (node->key == key) {
        return node;
    }
    if (node->key < key) {
        Node* rightChild = insert(node->right, key);
        node->right = rightChild;
        rightChild->parent = node;
    } else {
        Node* leftChild = insert(node->left, key);
        node->left = leftChild;
        leftChild->parent = node;
    }
    return node;
}

Node* search(Node* root, lli key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

Node* minimum(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void transplant(Node*& root, Node* u, Node* v) {
    if (u->parent == NULL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

Node* tree_delete(Node*& root, lli key) {
    Node* z = search(root, key);
    if (z == NULL)
        return root;
    if (z->left == NULL) {
        transplant(root, z, z->right);
    } else if (z->right == NULL) {
        transplant(root, z, z->left);
    } else {
        Node* y = minimum(z->right);
        if (y->parent != z) {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void levelorder(Node* root) {
    if (root == NULL)
        return;
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node* current = Q.front();
        Q.pop();
        cout << current->key << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
    }
}

lli findHeight(Node* node) {
    lli lh, rh;
    if (node == NULL)
        return -1;
    else {
        lh = findHeight(node->left);
        rh = findHeight(node->right);
    }
    return max(lh, rh) + 1;
}
void soln() {
    lli n, x;
    Node* root = NULL;
    cin >> n;
    for (lli i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            root = new Node(x);
        } else {
            insert(root, x);
        }
    }
    cout << "Inorder: ";
    inorder(root);
    cout << enl << "Preorder: ";
    preorder(root);
    cout << enl << "Postorder: ";
    postorder(root);
    cout << enl << "Levelorder: ";
    levelorder(root);
    cout << enl << "Height of the tree: " << findHeight(root) << enl;
    lli deleteKey;
    cout << "Enter key to delete: ";
    cout.flush();
    cin >> deleteKey;
    root = tree_delete(root, deleteKey);
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
    return 0;
}
