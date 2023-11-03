#include <stdio.h>

int n = 0, st[10001];

//Xay dung Stack bang mang 1 chieu
void push(int x){
    st[n] = x;
    ++n;
}

void pop(){
    if(n>=1) --n;
}

int top(){
    return st[n-1];
}

int size(){
    return n;
}

//Xay dung Stack bang DSLK

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *makenode(int x){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void push(node **top, int x){
    node *newnode=makenode(x);
    if(*top==NULL){
        *top=newnode;
        return;
    }
    newnode->next=(*top)->next;
    *top=newnode;
}

void pop(node **top){
    if(*top!=NULL){
        node *tmp=*top;
        *top=tmp->next;
        free(tmp);
    }
}

void top(node **top){
    if(*top!=NULL) return *top->data;
}