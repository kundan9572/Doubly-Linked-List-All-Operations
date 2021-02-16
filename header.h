#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *Node;

Node getnode();
Node insert_at_front(Node head,int data);
Node insert_at_end(Node head,int data);
Node delete_at_front(Node head);
Node delete_at_end(Node head);
void display(Node head);
Node insert_right(Node head,int data,int info);
Node insert_left(Node head,int data,int info);
Node delete_info_given(Node head,int item);
Node delete_all_given_info(Node head,int data);

#endif // HEADER_H_INCLUDED
