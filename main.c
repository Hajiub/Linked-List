#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int val;
    struct node* next;
} node;

node* createNode(int val)
{
    node* n = (node*)malloc(sizeof(node));
    assert(n != NULL);
    n->val = val;
    n->next = NULL;
    return n;
}

void insertNode(node** head, int val)
{
    node* n = createNode(val);
    if (*head == NULL)
    {
        *head = n;
    }
    else
    {
        node* temp = *head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void reverse(node** head)
{
    node* current, *prev, *next;
    current = *head;
    prev = NULL;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void display(node* head)
{
    node* current = head;
    while (current)
    {
        printf("%i -> ", current->val);
        current = current->next;
    }
    printf("None \n");
}

int len(node *head)
{
    node *list = head;
    int len = 0;
    while (list)
    {
        list = list->next;
        len++;
    }
    return len;
}

void freeList(node* head)
{
    node* current = head;
    node* tmp;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
}

int main()
{
    node* my_list = NULL;

    insertNode(&my_list, 1);
    insertNode(&my_list, 2);
    insertNode(&my_list, 3);
    printf("%i\n", len(my_list));
    reverse(&my_list);

    printf("Linked List: ");
    display(my_list);

    freeList(my_list);

    return 0;
}
