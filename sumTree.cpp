#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int sumTree(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;
    return root->data;
}

// Helper function for inorder traversal
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {


    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    cout << "Original inorder: ";
    inorder(root);
    cout << endl;

    sumTree(root);

    cout << "After sumTree inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}
