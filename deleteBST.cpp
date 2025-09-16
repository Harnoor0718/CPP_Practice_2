#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(key < root->data){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for(int val : arr){
        root = insert(root, val);
    }
    return root;
}

Node* getInorderSuccessor(Node* root){
    while(root != NULL && root->left != NULL ){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->left = delNode(root->left, key);
    }
    else if(key > root->data){
        root->right = delNode(root->right, key);
    }
    else {
        // key == root
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        } else { // 2 children
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
    }
    return root;
}

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);
    cout<<"before : ";
    inorder(root);
    cout<<endl;
    root = delNode(root, 6);
    cout<<"after : ";
    inorder(root);
    cout<<endl;
    return 0;
}
