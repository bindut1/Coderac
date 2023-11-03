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

vector<int> rightNode(TreeNode *root){
    vector<int> ans;
    queue<TreeNode*> myQueue;
    myQueue.push(root);
    while(!myQueue.empty()){
        int nodes=myQueue.size();
        for(int i=0; i<nodes; i++){
            TreeNode *node=myQueue.front();
            myQueue.pop();
            if(i==nodes-1) ans.push_back(node->value);
            if(node->left!=NULL) myQueue.push(node->left);
            if(node->right!=NULL) myQueue.push(node->right);
        }
    }
    return ans;
}

vector<int> maxx(TreeNode *root){
    vector<int> ans;
    queue<TreeNode*> myQueue;
    myQueue.push(root);
    while(!myQueue.empty()){
        int nodes=myQueue.size();
        int largest=INT_MIN;
        for(int i=0; i<nodes; i++){
            TreeNode *node=myQueue.front();
            myQueue.pop();
            largest=max(node->value, largest);
            if(node->left!=NULL) myQueue.push(node->left);
            if(node->right!=NULL) myQueue.push(node->right);
        }
        ans.push_back(largest);
    }
    return ans;
}

int main(){
    TreeNode *root=new TreeNode(5);
    tree(root);
    vector<int> answer=maxx(root);
    for(int i=0; i<answer.size(); i++) cout << answer[i] << "\t";
}