// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createTree(){
    int x; cin >> x;
    if (x == -1) return NULL;

    TreeNode* root = new TreeNode(x);
    // cout << "Enter left child of " << x << " ";
    root->left = createTree();
    // cout << "Enter right child of " << x << " ";
    root->right = createTree();
    return root;
}

void inorder(const TreeNode* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// TODO Do inorder traversal iteratively

int height(const TreeNode* root){
    if (root == NULL) return 0;
    int x = height(root->left);
    int y = height(root->right);
    return max(x, y) + 1;
}

int diameter(const TreeNode* root){
    if (root == NULL){
        return 0;
    }
    int left_dia = diameter(root->left);
    int right_dia = diameter(root->right);
    int curr_dia = height(root->left) + height(root->right) + 1;
    return max(max(left_dia, right_dia), curr_dia);
}

int main(){
    TreeNode* root = createTree();
    inorder(root); cout << endl;
    int ans = diameter(root);
    cout << ans;
    
}