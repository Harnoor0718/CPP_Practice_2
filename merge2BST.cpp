void inorder(Node* root, vector<int> &arr) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node* buildBSTFromSorted(vector<int> &arr, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = st + (end - st) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildBSTFromSorted(arr, st, mid - 1);
    root->right = buildBSTFromSorted(arr, mid + 1, end);
    return root;
}

Node* merge2BST(Node* root1, Node* root2) {
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> temp;
    int i = 0, j = 0;


    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            temp.push_back(arr1[i++]);
        } else {
            temp.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) {
        temp.push_back(arr1[i++]);
    }
    while (j < arr2.size()) {
        temp.push_back(arr2[j++]);
    }

    return buildBSTFromSorted(temp, 0, temp.size() - 1);
}
