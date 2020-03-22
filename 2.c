/******************************************************************************

 Name        : 2.c
 Author      : Marcos Garcia
 Version     : March 21 2020
 Copyright   : Your copyright notice
 Description : 
    This program distinguishes a Linked List between circular and inear. 
    It returns true if the linked list is linear, and fal if it's circular.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *n)
{

    struct Node *head = n;

    while (n != NULL)
    {
        printf("%d\n", n->data);

        if (n->next == head)
        {
            return 0;
        }

        n = n->next;
    }
}

bool isCircular(struct Node *head)
{
    if (head == NULL)
        return true;

    struct Node *node = head->next;

    while (node != NULL && node != head)
        node = node->next;

    return (node == head);
}

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    // third->next = NULL;
    third->next = head;

    printList(head);
    if (isCircular(head))
    {
        printf("the linked list is circular.");
    }
    else
    {
        printf("the linked list is NOT circular.");
    };

    return EXIT_SUCCESS;
}
