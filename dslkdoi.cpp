#include <iostream>
using namespace std;

template<typename T>
class Node
{
    public:
        T data;
        Node* next;
        Node* prev;
        Node();
}

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

node *add_node(int x)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
}

int size(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void push_front(node **head, int x)
{
    node *new_node = add_node(x);
    new_node->next = (*head);
    if (*head != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
}

void push_back(node **head, int x)
{
    node *new_node = add_node(x);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
}

void insert(node **head, int k, int x)
{
    int n = size(*head);
    if (k < 1 || k > n + 1)
        return;
    if (k == 1)
        push_front(head, x);
    else if (k == n + 1)
        push_back(head, x);
    else
    {
        node *tmp = (*head);
        for (int i = 1; i < k - 1; i++)
            tmp = tmp->next;
        node *new_node = add_node(x);
        new_node->next = tmp->next;
        tmp->next->prev = new_node;
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

void delete_front(node **head)
{
    if (*head == NULL)
        return;
    node *tmp = *head;
    *head = *head->next;
    if (*head != NULL)
        *head->prev = NULL;
    free(tmp);
}

void delete_back(node **head)
{
    if (*head == NULL)
        return;
    node *tmp = *head;
    if (tmp->next == NULL)
    {
        *head = NULL;
        free(tmp);
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    node *last = tmp->next;
    tmp->next = NULL;
    free(last);
}

void erase(node **head, int k)
{
    int n = size(*head);
    if (k < 1 || k > n)
        return;
    if (k == 1)
        pop_front(head);
    else
    {
        node *tmp = *head;
        for (int i = 1; i <= k - 1; i++)
            tmp = tmp->next;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
    }
}

void duyetnguoc(node *head)
{
    if (head == NULL)
        return;
    while (head->next != NULL)
        head = head->next;
    while (head != NULL)
    {
        cout << head->next;
        head = head->prev;
    }
}

void sort(node *head)
{
    for (node *i = *head;; i != NULL; i = i > next)
    {
        node *min = i;
        for (int *j = i->next; j != NULL; j = j->next)
        {
            if (min->data > j->data)
                min = j;
        }
        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}
