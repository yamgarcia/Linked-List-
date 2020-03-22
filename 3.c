/******************************************************************************

 Name        : 3.c
 Author      : Marcos Garcia
 Version     : March 21 2020
 Copyright   : Your copyright notice
 Description : 
    This program insert a new element to the right place in a sorted 
    linked list.
    E.g. If 11 is inserted into 1=>5=>10=>15 it becomes 1=>5=>10=>11=>15

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node
{
  int data;
  struct Node *next;
};

// creates a new node
struct Node *
newNode(int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->data = new_data;
  new_node->next = NULL;

  return new_node;
}

// function inserts a new_node in a sorted way. Like push()
void sortedInsert(struct Node **head_ref, struct Node *new_node)
{
  struct Node *current;
  if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
  {
    new_node->next = *head_ref;
    *head_ref = new_node;
  }
  else
  {
    // it locates then interts
    current = *head_ref;
    while (current->next != NULL && current->next->data < new_node->data)
    {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

// prints linked list
void printList(struct Node *head)
{
  if (NULL != head)
  {
    printf("Linked List:\n");

    struct Node *temp = head;
    while (temp != NULL)
    {
      printf("%d  ", temp->data);
      temp = temp->next;
    }
  }
  else
  {
    printf("The Linked List is NULL/empty\n\n");
    return 0;
  }
}

int main()
{
  //test node
  struct Node *test = NULL;
  struct Node *head = NULL;

  struct Node *new_node = newNode(8);
  sortedInsert(&head, new_node);

  new_node = newNode(5);
  sortedInsert(&head, new_node);

  new_node = newNode(6);
  sortedInsert(&head, new_node);

  new_node = newNode(2);
  sortedInsert(&head, new_node);

  new_node = newNode(10);
  sortedInsert(&head, new_node);

  new_node = newNode(4);
  sortedInsert(&head, new_node);

  new_node = newNode(7);
  sortedInsert(&head, new_node);

  new_node = newNode(1);
  sortedInsert(&head, new_node);

  new_node = newNode(3);
  sortedInsert(&head, new_node);

  new_node = newNode(9);
  sortedInsert(&head, new_node);

  printf("NULL Check:\n");
  printList(test);

  printList(head);

  return EXIT_SUCCESS;
}
