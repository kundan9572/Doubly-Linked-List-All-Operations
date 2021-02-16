
#include "header.h"
int main()
{
    Node head;
    head=getnode();
    head->llink=head;
    head->rlink=head;
    int data,choice,info;
    while(1)
    {
        printf("\n1-InsertFront\t2-InsertEnd\t3-DeleteFront\t4-DeleteEnd\t5-Display"
               "\t6-InsertRight(After)\t7-InsertLeft(Before)\t8-DeleteGivenInfo\t9-DeleteAllGivenInfo\t10-End\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter data to insert\n");
                    scanf("%d",&data);
                    head=insert_at_front(head,data);
                    break;
            case 2:
                    printf("Enter data to insert\n");
                    scanf("%d",&data);
                    head=insert_at_end(head,data);
                    break;
            case 3:
                    head=delete_at_front(head);
                    break;
            case 4:
                    head=delete_at_end(head);
                    break;
            case 5:
                    display(head);
                    break;
            case 6:
                    printf("Enter data to insert After key\n");
                    scanf("%d",&data);
                    printf("Enter the info field\n");
                    scanf("%d",&info);
                    head=insert_right(head,data,info);
                    break;
            case 7:
                    printf("Enter data to insert Before key\n");
                    scanf("%d",&data);
                    printf("Enter the info field\n");
                    scanf("%d",&info);
                    head=insert_left(head,data,info);
                    break;
            case 8:
                    printf("Enter the info to delete\n");
                    scanf("%d",&info);
                    head=delete_info_given(head,info);
                    break;
            case 9:
                    printf("Enter the info to delete\n");
                    scanf("%d",&info);
                    head=delete_all_given_info(head,info);
                    break;

            case 10:
                    exit(0);
            default:
                    printf("Invalid choice\n");

        }
    }
}
