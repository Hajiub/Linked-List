// version 1.0.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

int main()
{
    node *n, *list;
    list = NULL;
    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; 
    }
    n->value = 1;
    n->next = NULL;
    list = n;

    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; 
    }
    n->value = 2;
    n->next = NULL;
    list->next = n;

    for (node *current = list; current != NULL; current = current->next)
    {
        printf("%i\n", current->value);
    }

    node *tmp;
    while (list != NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
    return 0;
}
