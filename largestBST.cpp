
class Info{
public:
    int min, max, sz;

    Info(int mi, int ma, int size){
        min = mi,
        max = ma,
        sz = size;
    }
};

Info helper(Node*root){
    if(root == NULL){
        return Info(INT_MAX, INT_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data < right.min ){
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSz = left.sz + right.sz + 1;

        return Info(currMin, currMax, currSz);
    }
    return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));++
}

int largestBSTinBT(Node* root){
    Info info = helper(root);
    return info.sz;
}
