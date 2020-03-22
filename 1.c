/******************************************************************************

 Name        : 1.c
 Author      : Marcos Garcia
 Version     : March 21 2020
 Copyright   : Your copyright notice
 Description : 
    This program accepts the header of two linked lists, concatenate 
    the linked lists together and returns the augmented linked list.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
  int data;
  struct Node *next;
};

void MoveNode(struct Node **destRef, struct Node **sourceRef);

struct Node *
SortedMerge(struct Node *a, struct Node *b)
{
  struct Node *result = NULL;

  struct Node **lastPtrRef = &result;

  while (1)
  {
    if (a == NULL)
    {
      *lastPtrRef = b;
      break;
    }
    else if (b == NULL)
    {
      *lastPtrRef = a;
      break;
    }
    if (a->data <= b->data)
    {
      MoveNode(lastPtrRef, &a);
    }
    else
    {
      MoveNode(lastPtrRef, &b);
    }

    lastPtrRef = &((*lastPtrRef)->next);
  }
  return (result);
}

void MoveNode(struct Node **destRef, struct Node **sourceRef)
{

  struct Node *newNode = *sourceRef;
  assert(newNode != NULL);

  *sourceRef = newNode->next;

  newNode->next = *destRef;

  *destRef = newNode;
}

void push(struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->data = new_data;

  new_node->next = (*head_ref);

  (*head_ref) = new_node;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
}

int main()
{
  struct Node *res = NULL;
  struct Node *a = NULL;
  struct Node *b = NULL;

  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);

  push(&b, 10);
  push(&b, 9);
  push(&b, 8);
  push(&b, 7);
  push(&b, 6);

  res = SortedMerge(a, b);

  printf("Merged Linked List is: \n");
  printList(res);

  return EXIT_SUCCESS;
}
