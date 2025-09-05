#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Function to build tree from preorder vector
Node* buildTree(vector<int>& preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* newNode = new Node(preorder[idx]);
    newNode->left = buildTree(preorder);
    newNode->right = buildTree(preorder);

    return newNode;
}

// Level Order Traversal (for checking tree structure)
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

// ✅ Fixed topView function
void topView(Node* root) {
    if (!root) return;

    queue<pair<Node*, int>> q;   // node + horizontal distance
    map<int, int> m;             // hd → first node data

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* curr = p.first;
        int currHD = p.second;

        // store first node at each hd
        if (m.find(currHD) == m.end()) {
            m[currHD] = curr->data;
        }

        if (curr->left != NULL) {
            q.push({curr->left, currHD - 1});
        }
        if (curr->right != NULL) {
            q.push({curr->right, currHD + 1});
        }
    }

    // print map from leftmost to rightmost
    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    // Example: Preorder input with -1 as NULL indicator
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(preorder);

    cout << "Level Order Traversal of Tree:\n";
    levelOrder(root);

    cout << "\nTop View of Tree:\n";
    topView(root);

    return 0;
}
