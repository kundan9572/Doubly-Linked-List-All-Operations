
#include "header.h"

Node getnode(void)
{
    Node x;
    x=(Node)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Space is not available\n");
        exit(0);
    }
    return x;
}

Node insert_at_front(Node head,int data)
{
    Node curr,temp;
    temp=getnode();
    temp->info=data;
    curr=head->rlink;
    head->rlink=temp;
    temp->llink=head;
    temp->rlink=curr;
    curr->llink=temp;
    return head;
}

Node insert_at_end(Node head,int data)
{
    Node curr,prev,temp;
    temp=getnode();
    temp->info=data;
    curr=head->llink;
    head->llink=temp;
    temp->rlink=head;
    temp->llink=curr;
    curr->rlink=temp;
    return head;
}

Node delete_at_front(Node head)
{
    Node next,prev;
    if(head->rlink == head)
    {
        printf("List is empty\n");
        return head;
    }
    next=head->rlink;
    prev=next->rlink;
    head->rlink=prev;
    prev->llink=head;
    printf("The item deleted is %d\n",next->info);
    free(next);
    return head;

}

Node delete_at_end(Node head)
{
    Node next,prev;
    if(head->llink == head)
    {
        printf("List is empty\n");
        return head;
    }
    next=head->llink;
    prev=next->llink;
    head->llink=prev;
    prev->rlink=head;
    printf("The item deleted is %d\n",next->info);
    free(next);
    return head;

}

void display(Node head)
{
    Node curr;
    if(head->rlink == NULL)
    {
        printf("List is empty\n");
    }
    curr=head->rlink;
    while(curr != head)
    {
        printf("%d--->",curr->info);
        curr=curr->rlink;
    }
    printf("\n");
}

Node insert_right(Node head,int data,int info)
{
    Node temp,curr,next;
    if(head->rlink == head)
    {
        printf("list is empty\n");
        return head;
    }
    curr=head->rlink;
    while(curr !=head)
    {
        if(info==curr->info)
            break;
        curr=curr->rlink;
    }
    if(curr==head)
    {
        printf("key is not found\n");
        return head;
    }
    temp=getnode();
    temp->info=data;
    next=curr->rlink;
    curr->rlink=temp;
    temp->llink=curr;
    temp->rlink=next;
    next->llink=temp;
    return head;
}

Node insert_left(Node head,int data,int info)
{
    Node curr,prev,temp;
    if(head->rlink==head)
    {
        printf("Link is empty\n");
        return head;
    }
    curr=head->rlink;
    while(curr != head)
    {
        if(info==curr->info)
            break;
        curr=curr->rlink;
    }
    temp=getnode();
    temp->info=data;
    prev=curr->llink;
    prev->rlink=temp;
    temp->llink=prev;
    curr->llink=temp;
    temp->rlink=curr;
    return head;

}

Node delete_info_given(Node head,int item)
{
    Node prev,curr,next;
    if(head->rlink==head)
    {
        printf("List is empty\n");
        return head;
    }
    curr=head->rlink;
    while(curr != head)
    {
        if(curr->info == item)
            break;
        curr=curr->rlink;
    }
    if(curr==head)
    {
        printf("Item is not present\n");
        return head;
    }
    prev=curr->llink;
    next=curr->rlink;
    prev->rlink=next;
    next->llink=prev;
    printf("The item deleted is %d\n",curr->info);
    free(curr);
    return head;

}

Node delete_all_given_info(Node head,int data)
{
    Node prev,curr,next;
    int count;
    if(head->rlink==head)
    {
        printf("List is empty\n");
        return head;
    }
    count=0;
    curr=head->rlink;
    while(curr !=head)
    {
        if(data !=curr->info)
        {
            curr=curr->rlink;
        }
        else
        {
            count++;
            prev=curr->llink;
            next=curr->rlink;
            prev->rlink=next;
            next->llink=prev;
            free(curr);
            curr=next;
        }
    }
    if(count==0)
        printf("Key not found\n");
    else
        printf("key is found at %d position and deleted\n",count);
    return head;
}
