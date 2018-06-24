// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createTree() {
    int x; cin >> x;
    if (x == -1) return NULL;

    TreeNode* root = new TreeNode(x);
    // cout << "Enter left child of " << x << " ";
    root->left = createTree();
    // cout << "Enter right child of " << x << " ";
    root->right = createTree();
    return root;
}

void inorder(const TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isSameValSubTree(TreeNode* root) {
    if (root == NULL) {return true;}

    bool isRoot = (root->left ? root->data == root->left->data : true) && /*law 2 broken*/
                  (root->right? root->data == root->right->data : true);

    return isRoot && isSameValSubTree(root->left) && isSameValSubTree(root->right);
}


int cntSameValSubTree(TreeNode* root) {
    if (root == NULL) return 0;

    int x = cntSameValSubTree(root->left);
    int y = cntSameValSubTree(root->right);
    bool isRootSameValSubtree = isSameValSubTree(root);
    return x + y + (isRootSameValSubtree ? 1 : 0);
}


int main() {
    TreeNode* root = createTree();
    inorder(root); cout << endl << "====="<< endl;
    int ans = cntSameValSubTree(root);
    cout << ans;

}