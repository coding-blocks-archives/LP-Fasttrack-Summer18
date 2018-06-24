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
                  (root->right ? root->data == root->right->data : true);

    return isRoot && isSameValSubTree(root->left) && isSameValSubTree(root->right);
}


int cntSameValSubTree(TreeNode* root) {
    if (root == NULL) return 0;

    int x = cntSameValSubTree(root->left);
    int y = cntSameValSubTree(root->right);
    bool isRootSameValSubtree = isSameValSubTree(root); // computationally expensive
    return x + y + (isRootSameValSubtree ? 1 : 0);
}

class Pair {
public:
    int cnt;
    bool isSameValSubTree;
    Pair(int c, bool isSameVal) {
        cnt = c;
        isSameValSubTree = isSameVal;
    }
};

Pair cntSameValSubTree2(TreeNode* root) {
    if (root == NULL) {
        return Pair(0, true);
    }

    Pair x = cntSameValSubTree2(root->left);
    Pair y = cntSameValSubTree2(root->right);

    Pair curAns(0, true);
    curAns.isSameValSubTree = (root->left ? root->data == root->left->data : true) &&
                              (root->right ? root->data == root->right->data : true) &&
                              x.isSameValSubTree &&
                              y.isSameValSubTree;

    curAns.cnt = x.cnt + y.cnt + (curAns.isSameValSubTree ? 1 : 0);
    return curAns;
}


bool isSameValSubTree2(TreeNode* root, int& cnt) {
    // isSameValSubTree2 tells if the tree starting at root is a same value subtree
    // or not AND also update the cnt of same value subtrees in the tree starting at root
    
    if (root == NULL) {
        return true;
    }

    bool isLeft = isSameValSubTree2(root->left, cnt);
    bool isRight = isSameValSubTree2(root->right, cnt);

    bool isRootSameVal = (root->left ? root->data == root->left->data : true) &&
                         (root->right ? root->data == root->right->data : true) &&
                         isLeft && isRight;

    if (isRootSameVal) { ++cnt; }
    return isRootSameVal;
}

int cntSameValSubTree3(TreeNode* root){
    // wrapper function
    int cnt = 0;
    isSameValSubTree2(root, cnt);
    return cnt;
}

int main() {
    TreeNode* root = createTree();
    inorder(root); cout << endl << "=====" << endl;
    // int ans = cntSameValSubTree(root);
    // cout << ans;

    // Pair p = cntSameValSubTree2(root);
    // cout << p.cnt << " " << p.isSameValSubTree;

    // int cnt = 0;
    // bool ans = isSameValSubTree2(root, cnt);
    // cout << ans << " " << cnt;;

    int ans = cntSameValSubTree3(root);
    cout << ans;

}