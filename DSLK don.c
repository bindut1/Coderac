#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;   //data
    struct node *next;     //link
};

typedef struct node node;

void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head=head->next; //dich head sang ben phai de tro vao node tiep theo
    }
}

int size(node *head){
    int cnt=0;
    while(head!=NULL){
        ++cnt;
        head=head->next;
    }
    return cnt;
}

node *add_node(int x){
    node *new_node=(node*)malloc(sizeof(node)); //Cap phat dong mot node
    new_node->data=x;
    new_node->next=NULL;
    return new_node;
}

void push_front(node **head, int x){
    node *new_node=add_node(x);
    new_node->next=(*head); //gan head ban dau cho node moi them vao
    (*head)=new_node;   //head giu gia tri cua node moi them vao
}

void push_back(node **head, int x){
    node *new_node=add_node(x);
    node *tmp=(*head);
    if(tmp==NULL){  //kiem tra xem DSLK nay co phai DS rong khong
        (*head)=new_node;
        return;
    }
    while(tmp->next!=NULL){     //duyet den node cuoi cung
        tmp=tmp->next;
    }
    tmp->next=new_node;     //cho next cua tmp tro vao node moi them vao
}   

void insert(node **head, int k, int x){
    int n=size(*head);
    if(k<1 || k>n+1) return;
    if(k==1) push_front(head, x);
    else if(k==n+1) push_back(head, x);
    else{
        node *tmp=(*head);
        for(int i=0; i<k-1; i++){
            tmp=tmp->next; //tmp dang luu node k-1
        }
        node *new_node=add_node(x);
        new_node->next=tmp->next; 
        tmp->next=new_node; 
    }
}

void delete_front(node **head){
    if(*head==NULL) return;
    node (*tmp) = (*head); //de ti nua giai phong head ban dau
    (*head)=(*head)->next;    //gan head bang head tiep theo
    free(tmp);
}

void delete_back(node **head){
    if(*head==NULL) return;
    node *tmp=*head;
    if(tmp->next==NULL){    //DSLK chi co 1 phan tu
        *head=NULL;
        free(tmp);
        return;
    }
    while(tmp->next->next!=NULL){   //DSLK co 2 phan tu tro len, duyet toi phan tu thu 2 tu cuoi ve
        tmp=tmp->next;
    }
    node *last=tmp->next; //luu node cuoi cung de ti nua giai phong
    tmp->next=NULL; //cho tro vao NULL, bay gio tmp da la node cuoi cung
    free(last);
}

void erase(node **head, int k){
    if(k<1 || k>size(*head)) return;    
    if(k==1) delete_front(head);
    else{
        node *tmp=*head;
        for(int i=1; i<k-1; i++) tmp=tmp->next; //sau khi ket thuc, tmp giu gia tri cua node thu k-1
        node *end=tmp->next;    //node thu k
        tmp->next=end->next;    //cho node tmp nhay qua node end
        free(end);
    }
}

void selectionsort(node **head){
    for(node *i=*head; i!=NULL; i=i->next){
        node *min=i;
        for(node *j=i->next; j!=NULL; j=j->next){
            if(min->data>j->data){
                min=j;
            }
        }
        int tmp=min->data;
        min->data=i->data;
        i->data=tmp;
    }
}

int main(){
    node *head=NULL;
    while(1){
        printf("-------------------DANH SACH LIEN KET----------------\n");
        printf("1. Them node vao dau DSLK\n");
        printf("2. Them node vao cuoi DSLK\n");
        printf("3. Them node vao vi tri thu k trong DSLK\n");
        printf("4. Xoa node o dau DSLK\n");
        printf("5. Xoa node o cuoi DSLK\n");
        printf("6. Xoa node o vi tri thu k trong DSLK\n");
        printf("7. Sap xep DSLK theo thu tu giam dan\n");
        printf("8. Duyet DSLK\n");
        printf("0. Thoat chuong trinh\n");
        printf("-------------------------------------------------------");
        printf("\nNhap lua chon : ");
        int lc; scanf("%d",&lc);
        if(lc==1){
            printf("\nNhap gia tri can them : ");
            int x; scanf("%d",&x);
            push_front(&head,x);
        }
        else if(lc==2){
            printf("\nNhap gia tri can them : ");
            int x; scanf("%d",&x);
            push_back(&head,x);
        }
        else if(lc==3){
            printf("\nNhap vi tri chen : ");
            int k; scanf("%d",&k);
            printf("\nNhap gia tri can chen : ");
            int x; scanf("%d",&x);
            insert(&head,k,x);
        }
        else if(lc==4){
            delete_front(&head);
        }
        else if(lc==5){
            delete_back(&head);
        }
        else if(lc==6){
            printf("\nNhap vi tri can xoa : ");
            int k; scanf("%d",&k);
            erase(&head,k);
        }
        else if(lc==7){
            insertionsort(&head);
        }
        else if(lc==8){
            duyet(head);
        }
        else if(lc==0) return;
        else printf("\nDu lieu dau vao khong hop le !");
    }
}