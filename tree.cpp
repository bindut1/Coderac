#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *make_node(int x){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=x;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

node *add_left(node *head, int x){
    head->left=make_node(x);
    return head->left;
}

node *add_right(node *head, int x){
    head->right=make_node(x);
    return head->right;
}

void pre_order(node *head){ 
    if(head==NULL) return;
    cout << head->data << " ";
    pre_order(head->left);
    pre_order(head->right);
}

void in_order(node *head){
    if(head==NULL) return;
    in_order(head->left);
    cout << head->data << " ";
    in_order(head->right);
}

void post_order(node *head){
    if(head==NULL) return;
    post_order(head->left);
    post_order(head->right);
    cout << head->data << " ";
}

node *search(node *head, int x){
    if(head){
        if(head->data==x) return head;
        else if(head->data>x) return search(head->left,x);
        else return search(head->right,x);
    }
    return NULL;
}

main(){
    node *head=make_node(2);
    add_left(head,3);
    add_left(head->left,5);
    add_right(head,6);
    add_left(head->right, 8);
    add_right(head->right, 9);
    // cout << "Pre:\n";
    // pre_order(head);
     //cout << "\nIn:\n";
    // in_order(head);
    // cout << "\nPost:\n";
     post_order(head);
   // int x; cin >> x;
   // cout << search(head,x);
}

