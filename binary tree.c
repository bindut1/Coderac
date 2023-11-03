#include <stdio.h>

struct treenode{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct treenode treenode;

treenode *makenode(int x){
    treenode *newnode = (treenode*)malloc(sizeof(treenode));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode; 
}

treenode *add_left(treenode *head, int x){
    head->left=make_node(x);
    return head->left;
}

treenode *add_right(treenode *head, int x){
    head->right=make_node(x);
    return head->right;
}

void pre_oder(treenode *head){
    if(head==NULL) return;
    printf("%d ", head->data);
    pre_oder(head->left);
    pre_oder(head->right);
}

void in_oder(treenode *head){
    if(head==NULL) return;
    in_oder(head->left);
    printf("%d ", head->data);
    in_oder(head->right);
}

void post_oder(treenode *head){
    if(head==NULL) return;
    post_oder(head->left);
    post_oder(head->right);
    printf("%d ", head->data);
}

int search(treenode *head, int x){
    if(head == NULL) return 0;
    if(head->data == x) return 1;
    int left = search(head->left, x);
    int right = search(head->right, x);
    return left || right;
}

void insert(treenode **head, int x){
    if(*head == NULL){
        *head = makenode(x);
        return;
    }
    if(x < (*head)->data){
        insert(&((*head)->left), x);
    }
    else{
        insert(&((*head)->right), x);
    }
}


void node_themang (tree &p, tree &q)
{
    if (q -> left != NULL) node_themang(p, q -> left);
    else
    {
        p -> data = q -> data;
        p = q;
        q = q -> right;
    }
}

void xoa (tree &t, int x)
{
    if (t == NULL) return;
    else
    {
        if (t -> data < x) xoa(t -> right, x);
        else if (t -> data > x) xoa(t -> left, x);
        else
        {
            tree *p = t;
            if (t -> left == NULL) t = t -> right;
            else if (t -> right == NULL) t = t -> left;
            else
            {
                tree *q = t -> right;
                node_themang (p, q);
            }
        }
        delete x;
    }
}

void remotetree(treenode **head){
    if(*head){
        remotetree(&((*head)->left));
        remotetree(&((*head)->right));
        free(head);
    }
}