#include <stdio.h>

int a[100000], maxN = 100000;
int n = 0;

int size(){
    return n;
}

int empty(){
    return n == 0;
}

void push(int x){
    if(n == maxN) return;
    a[n] = x; ++n;
}

void pop(){
    if(n == 0) return;
    for(int i = 0; i < n - 1; i++){
        a[i] = a[i+1];
    }
    --n;
}

int front(){
    return a[0];
}

//Dung DSLK

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *make_node(int x){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void push(node **queue){
    if(*queue == NULL){
        *queue = new_node;
        return;
    }
    node *tmp = *queue;
    while(tmp->next != NULL) tmp = tmp->next;
    tmp->next = new_node;
}

void pop(node **queue){
    if(*queue == NULL) return;
    node *tmp = *queue;
    *queue = *queue->next;
    free(tmp);
}

int size(node *queue){
    int ans = 0;
    while(queue!=NULL){
        ++ans;
        queue = queue->next;
    }
    return ans;
}

int front(node *queue){
    return queue->data;h
}
