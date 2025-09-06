#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// ---------------- Build Tree from Preorder ----------------
Node* buildTreeHelper(vector<int>& preorder, int& idx) {
    if (idx >= preorder.size() || preorder[idx] == -1) {
        idx++;
        return nullptr;
    }
    Node* root = new Node(preorder[idx++]);
    root->left = buildTreeHelper(preorder, idx);
    root->right = buildTreeHelper(preorder, idx);
    return root;
}

Node* buildTree(vector<int>& preorder) {
    int idx = 0;
    return buildTreeHelper(preorder, idx);
}

// ---------------- Kth Level of a Binary Tree ----------------
void KthLevel(Node* root, int K) {
    if (root == nullptr) {
        return;
    }
    if (K == 1) {
        cout << root->val << " ";
        return;
    }
    KthLevel(root->left, K - 1);
    KthLevel(root->right, K - 1);
}

int main() {
    vector<int> preorder = {1, 2, 7, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    int k = 3; // root = level 1
    cout << "Nodes at level " << k << ": ";
    KthLevel(root, k);
    cout << endl;

    return 0;
}
