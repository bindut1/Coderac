// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;
//chieu sau toi da cua cay

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): value(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, 1));
        int ans = 0;
        
        while (!stack.empty()) {
            auto [node, depth] = stack.top();
            stack.pop();
            ans = max(ans, depth);
            
            if (node->left != NULL) {
                stack.push(pair(node->left, depth + 1));
            }
            
            if (node -> right != NULL) {
                stack.push(pair(node->right, depth + 1));
            }
        }
        
        return ans;
    }
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

int main() {
    TreeNode *root = new TreeNode(3);
    tree(root);
    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Chieu sau toi da cua cay la: " << depth << endl;
    return 0;
}
