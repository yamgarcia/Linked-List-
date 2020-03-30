#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
 * creating a data structure
 
    typedef struct tsample
    {
     int foo;
     char bar[4];
    } tzsample;
*/

/*
 * creating a linked list
 */
typedef struct Node
{
  int data;
  char bar[50];
  struct tsample *next;

} tZnode;
/**
 * Functions
 */
struct Node *SortedMerge (struct Node *a, struct Node *b);
void MoveNode (struct Node **destRef, struct Node **sourceRef);
void printList (struct Node *node);
void push (struct Node **head_ref, int new_data);
void traverse (struct Node *head);
int insert (struct Node *head, int dataToInsert);
int deleteNode (struct Node *head, int dataToDelete);

/*****************************main********************************/
int
main (void)
{
  tZnode *node;
  node = (tZnode *) malloc (sizeof (tZnode));
  tZnode node2;

  if (NULL == node)
    {
      EXIT_FAILURE;
    }

  node2.data = 5;
  strcpy (node2.bar, "ho");
  node->data = 3;
  strncpy (node->bar, "hi", sizeof ("hi"));

  printf ("node: data = %d, bar = %s\n\n", node->data, node->bar);
  printf ("node2: data = %d, bar = %s\n", node2.data, node2.bar);

  //using push
  tZnode *a = NULL;
  //or
  struct Node *b = NULL;
  struct Node *c = NULL;
  push (&a, 2);
  push (&b, 1);
  push (&c, 3);
  printf ("\n");

  //Print
  printf (" a = ");
  traverse (a);
  printf (" b = ");
  traverse (b);
  printf (" c = ");
  traverse (c);
  printf ("\t\n");

  //Concatenate
  struct Node *res = NULL;
  res = SortedMerge (a, b);
  res = SortedMerge (res, c);
  printf ("Print after sorted merging\n");
  traverse (res);
  printf ("\n");

//   a->next = b;
//   b->next = c;
//   printf ("\ntraverse\n");
//   traverse (a);

  //Insert
//   struct Node *newNode = NULL;
  insert (res, 5);
  insert (res, 6);
  insert (res, 7);
  insert (res, 8);

  printf ("\n Print After Inserting Nodes \n");
  traverse (res);

  printf ("\n After DELETING Nodes \n");

  deleteNode (res, 7);
  traverse (res);

  return EXIT_SUCCESS;
}

/*******************************main******************************/

/*
 * Insert data into the linked list
 */
void
push (struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node));

  new_node->data = new_data;

  new_node->next = (*head_ref);

  (*head_ref) = new_node;
}

/*
 * Print linked list 
 */
void
printList (struct Node *node)
{
  while (node != NULL)
    {
      printf ("%d", node->data);
      node = node->next;
    }
}

/**
 * Traverse
 */
void
traverse (struct Node *head)
{
  struct Node *p = head;
  while (p != NULL)
    {
      if (p->data == NULL)
	{
	  p = p->next;
	}
      else
	{
	  printf ("%d\t", p->data);
	  p = p->next;
	}
    }
}

/*
 * Sorted Merge nodes
 */

struct Node *
SortedMerge (struct Node *a, struct Node *b)
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
	  MoveNode (lastPtrRef, &a);
	}
      else
	{
	  MoveNode (lastPtrRef, &b);
	}

      lastPtrRef = &((*lastPtrRef)->next);
    }
  return (result);
}

/*
 * Move nodes 
 */
void
MoveNode (struct Node **destRef, struct Node **sourceRef)
{

  struct Node *newNode = *sourceRef;
  assert (newNode != NULL);

  *sourceRef = newNode->next;

  newNode->next = *destRef;

  *destRef = newNode;
}

/**
 * insert node
 */
int
insert (struct Node *head, int dataToInsert)
{
  struct Node *new;

  new = (struct Node *) malloc (sizeof (struct Node));
  if (NULL == new)
    {
      return -1;
    }

  struct Node *p = head;
  while (1)
    {
      if (p->next == NULL)
	{
	  p->next = new;
	  new->data = dataToInsert;
	  //   strcpy (new->bar, "New Node");
	  break;
	}
      p = p->next;
    }
}

/**
 * delete node
 */
int
deleteNode (struct Node *head, int dataToDelete)
{

  if (NULL == head)
    {
      return -1;
    }

  struct Node *p = head;
  while (1)
    {
      if (p->data == dataToDelete)
	{
	  p->data = NULL;
	  free (p);
	  //   p = NULL;
	  break;
	  if (NULL == p->next)
	    {
	      printf ("data not found");
	      break;
	    }
	}
      p = p->next;
    }
}

