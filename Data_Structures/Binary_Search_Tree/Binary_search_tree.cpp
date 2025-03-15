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
    Node(lli item) {
        key = item;
        left = NULL;
        right = NULL;
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
        node->right = insert(node->right, key);
    } else {
        node->left = insert(node->left, key);
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

lli findHeightDiameter(Node* node, lli& diameter) {
    if (node == NULL)
        return 0;
    lli lh = findHeightDiameter(node->left, diameter);
    lli rh = findHeightDiameter(node->right, diameter);

    diameter = max(diameter, lh + rh);

    return max(lh, rh) + 1;
}

lli diameterBST(Node* node) {
    lli diameter = 0;
    findHeightDiameter(node, diameter);
    return diameter;
}

lli maxPathDown(Node* node, lli& maxi) {
    if (node == NULL)
        return 0;
    lli l = max(0LL, maxPathDown(node->left, maxi));
    lli r = max(0LL, maxPathDown(node->right, maxi));
    maxi = max(maxi, l + r + node->key);
    return max(l, r) + node->key;
}

lli maxPathSum(Node* node) {
    lli maxi = LLONG_MIN;
    maxPathDown(node, maxi);
    return maxi;
}
void soln() {
    lli n, x;
    Node* root;
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
    lli diameter = 0;
    cout << enl << "Height of the tree: " << findHeightDiameter(root, diameter)
         << enl;
    cout << "Diameter of the tree: " << diameterBST(root) << enl;
    cout << "Max Path Sum: " << maxPathSum(root) << enl;
    lli ss;
    cin >> ss;
    (search(root, ss) != NULL) ? cout << "Found" : cout << "Not Found";
    cout << enl;
}
int main() {
    fast();
    lli t = 1;
    // cin >> t;
    while (t--) soln();
    return 0;
}
