Node* rightMostInLeftSubtree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}

Node* leftMostInRightSubtree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPredSucc(Node* root, int key){
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL){
        if(key < curr->data){
            succ = curr;
            curr = curr->left;
        } else if(key > curr->data){
            pred = curr;
            curr = curr->right;
        } else {
            if(curr->left != NULL){
                pred = rightMostInLeftSubtree(curr->left);
            }
            if(curr->right != NULL){
                succ = leftMostInRightSubtree(curr->right);
            }
            break;
        }
    }
    return {pred->data, succ->data};
}

