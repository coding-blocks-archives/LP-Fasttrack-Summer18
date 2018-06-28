// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* next;
    TreeNode(T x) {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

template<typename T>
TreeNode<T>* insertIntoBst(TreeNode<T>* root, int x) {
    if (root == NULL) {
        root = new TreeNode<T>(x);
        return root;
    }

    if (x > root->data) {
        root->right = insertIntoBst(root->right, x);
        return root;
    }
    else {
        // insert into left since x is less than root
        root->left = insertIntoBst(root->left, x);
        return root;
    }
}

template<typename T>
void printBst(TreeNode<T>* root) {
    if (root == NULL) return;
    printBst(root->left);
    cout << root->data << " ";
    printBst(root->right);
}

template<typename T>
TreeNode<T>* createBst(T stopper) {
    T x;
    TreeNode<T>* root = NULL;
    while (true) {
        cin >> x;
        if (x == stopper) break;
        root = insertIntoBst(root, x);
    }
    return root;
}

template<typename T>
TreeNode<T>* findElementBst(TreeNode<T>* root, T key) {
    if (root  == NULL) return NULL;
    if (root->data == key) return root;
    if (key < root->data) {
        // search in the left
        return findElementBst(root->left, key);
    }
    // else search in the right
    return findElementBst(root->right, key);
}

TreeNode<int>* findLcaBst1(TreeNode<int>* root, int x, int y) {
    // returns NULL if BOTH Nodes are NOT found, else return LCA
    if (root == NULL) return NULL;

    if (x < root->data && y < root->data) {
        return findLcaBst1(root->left, x , y);
    }
    if (x > root->data && y > root->data) {
        return findLcaBst1(root->right, x, y);
    }

    if (findElementBst(root, x) && findElementBst(root, y)) return root;
    return NULL;
}

TreeNode<int>* findLcaBst(TreeNode<int>*root, int x, int y) {
    bool isxPresent = findElementBst(root, x);
    bool isyPresent = findElementBst(root, y);
    if (isxPresent && isyPresent) return findLcaBst1(root, x, y);
}

template <typename T>
void levelPrint(TreeNode<T>* root) {
    TreeNode<T>* const MARKER = NULL;   // marker is constant

    queue<TreeNode<T>*> q;
    q.push(root);
    q.push(MARKER);

    while (q.empty() == false) {
        TreeNode<T>* cur = q.front(); q.pop();

        if (cur == MARKER) {
            // signifies end of the current level.. all children of the current level are
            // already pushed into the queue
            if (q.empty() == false) q.push(MARKER);
            cout << endl;
            continue;
        }

        cout << cur->data << "(" << (cur->next ? cur->next->data : '0') << ")-->" ;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

template<typename T>
void connectLevels(TreeNode<T>* root) {
    TreeNode<T>* const MARKER = NULL;   // marker is constant

    queue<TreeNode<T>*> q;
    q.push(root);
    q.push(MARKER);

    while (q.empty() == false) {
        TreeNode<T>* cur = q.front(); q.pop();

        if (cur == MARKER) {
            // signifies end of the current level.. all children of the current level are
            // already pushed into the queue
            if (q.empty() == false) q.push(MARKER);
            continue;
        }
        cur->next = q.front();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

bool getPath(TreeNode<int>* root, vector<TreeNode<int>*>& v, int key) {
    if (root == NULL) return false;

    v.push_back(root);
    if (root->data == key) return true;
    if (getPath(root->left, v, key)) return true;
    if (getPath(root->right, v, key)) return true;
    v.pop_back();
    return false;
}

TreeNode<int>* findLcaBT(TreeNode<int>* root, int x, int y) {
    vector<TreeNode<int>*> x_path, y_path;
    bool xPresence =  getPath(root, x_path, x);
    bool yPresence =  getPath(root, y_path, y);

    if (!xPresence or !yPresence) return NULL;

    int i = 0, j = 0;
    while (i < x_path.size() && j < y_path.size() && x_path[i] == y_path[j]) {
        ++i;
        ++j;
    }

    return x_path[i - 1];
}


template<typename T>
TreeNode<T>* createTree(T stopper) {
    T x; cin >> x;
    if (x == stopper) return NULL;

    TreeNode<T>* root = new TreeNode<T>(x);
    // cout << "Enter left child of " << x << " ";
    root->left = createTree(stopper);
    // cout << "Enter right child of " << x << " ";
    root->right = createTree(stopper);
    return root;
}





int main() {
    // TreeNode<int>* root = createBst<int>();
    // printBst(root); cout << endl;

    // int x; cin >> x;
    // TreeNode<int>* ans = findElementBst(root, x);
    // cout << endl;
    // cout << ans << " " << (ans ? ans->data : -1);

    // int x, y; cin >> x >> y;
    // TreeNode<int>* ans = findLcaBst(root, x, y);
    // cout << ans << " " << (ans ? ans->data : -1);

    // TreeNode<char>* root = createBst<char>('x');
    // levelPrint(root);

    // TreeNode<char>* root = createTree('x');
    // connectLevels(root);
    // levelPrint(root);

    TreeNode<int>* root = createTree(-1);
    // vector<TreeNode<int>*> v; 
    // int key; cin >> key;
    // bool ans = getPath(root, v, key);
    // if (ans) {
    //     for (TreeNode<int>* x : v) {
    //         cout << x->data << "-->";
    //     }
    // }
    // else {
    //     cout << "Cant find element. So where can I find the path." << endl;
    // }
    int x, y; cin >> x >> y;
    auto ans = findLcaBT(root, x, y);
    cout << ans << " " << (ans ? ans->data : -1) << endl;
}