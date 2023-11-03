#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): value(val), left(NULL), right(NULL) {}
};

void tree(TreeNode *root){
    root->left=new TreeNode(1);
    root->right=new TreeNode(9);

    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(7);

    root->right->left=new TreeNode(11);
    root->right->right=new TreeNode(15);

    root->left->left->left=new TreeNode(0);

    root->right->left->right=new TreeNode(0);
    root->right->left->right->left=new TreeNode(3);
}

bool search(TreeNode* root, int x){
    if(root == NULL) return false;
    if(root->value == x) return true;
    bool left = search(root->left, x);
    bool right = search(root->right, x);
    return left || right;
}

void insert(TreeNode **root, int x){
    if(*root == NULL){
        *root = new TreeNode(x);
        return;
    }
    if(x < (*root)->value){
        insert(&((*root)->left), x);
    }
    else{
        insert(&((*root)->right), x);
    }
}

void insert1(TreeNode *&root, int x){
    if(root == NULL){
        root = new TreeNode(x);
        return;
    }
    if(x < root->value){
        insert1(root->left, x);
    }
    else{
        insert1(root->right, x);
    }
}

TreeNode* deleteNode(TreeNode* root, int x) {
    if (root == NULL) {
        return root;
    }
    if (x < root->value) {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->value) {
        root->right = deleteNode(root->right, x);
    }
    else {
        // Phần tử cần xóa đã được tìm thấy
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        else {
            // Tìm phần tử lớn nhất trong cây con trái
            TreeNode* temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            // Thay thế phần tử hiện tại bằng phần tử lớn nhất này
            root->value = temp->value;
            // Xóa phần tử lớn nhất này từ cây con trái
            root->left = deleteNode(root->left, temp->value);
        }
    }
    return root;
}

void duyet_truoc(TreeNode *root){
    if(root==NULL) return;
    cout << root->value << " ";
    duyet_truoc(root->left);
    duyet_truoc(root->right);
}

int longgest(TreeNode *root){
    if(root==NULL) return 0;
    return max(longgest(root->left), longgest(root->right))+1;
}

bool target(TreeNode *root, int sum){
    bool lc, rc;
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL){
        return root->value==sum;
    }
    sum-=root->value;
    lc=target(root->left,sum);
    rc=target(root->right,sum);
    return (lc || rc);
}

class countgood{
    public:
        int good(TreeNode *root, int maxvalue){
            if(root==NULL) return 0;
            int l,r,ans;
            l=good(root->left, max(maxvalue, root->value));
            r=good(root->right, max(maxvalue, root->value));
            ans=l+r;
            if(root->value>=maxvalue) ans++;
            return ans;
        }
        int cnt(TreeNode *root){
            return good(root, INT_MIN);
        }
};

int main(){
    TreeNode *root = new TreeNode(5);
    tree(root);
    //cout << "Chieu sau toi da cua cay la: " << longgest(root) << endl;
    //cout << boolalpha << target(root,29);
    //countgood cgn;
    //cout << cgn.cnt(root);

// int x = 2;
// if(search(root, x)){
//     cout << "Found " << x << " on the tree" << endl;
// }
// else{
//     cout << x << " not found on the tree" << endl;
// }

int x = 18;
duyet_truoc(root);
insert(&root, x);
cout << "\nsau khi them\n";
duyet_truoc(root);
    return 0;
}
