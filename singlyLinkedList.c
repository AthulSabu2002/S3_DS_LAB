#include<stdio.h>
#include<stdlib.h>
int choice,value;
struct node{
    int data;
    struct node *next;
};
struct node *start,*temp;
int pos,i;
void InsertAtBegin()
{
    printf("Enter value to insert : \n");
    scanf("%d",&value);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        newnode->next=NULL;
        newnode->data=value;
        start=newnode;
    }
    else
    {
        newnode->next=start;
        newnode->data=value;
        start=newnode;
    }
}
void Display()
{
    if(start==NULL)
    printf("The list is empty..");
    else{
    printf("The elements are : \n");
    struct node *temp;
    for(temp=start;temp!=NULL;temp=temp->next)
    printf("%d\t",temp->data);
    }
}
void DeleteAtBegin()
{
    struct node *temp;
    if(start==NULL)
    printf("The list is empty..");
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        printf("Deleted : %d",temp->data);
        free(temp);
    }
    else{
        temp=start;
        start=start->next;
        printf("Deleted : %d",temp->data);
        free(temp);
    }
}
void insertAtEnd()
{
    printf("Enter value to insert : \n");
    scanf("%d",&value);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        newnode->next=NULL;
        newnode->data=value;
        start=newnode;
    }
    else{
        struct node *p;
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=newnode;
        newnode->data=value;
        newnode->next=NULL;
    }
}
void deleteAtEnd()
{
    struct node *p;
    if(start==NULL)
    printf("There is nothing to delete ...");
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        printf("Deleted : %d",temp->data);
        free(temp);
    }
    else{
        p=start->next;
        temp=start;
        while(p->next!=NULL)
        {
            temp=temp->next;
            p=p->next;
        }
        temp->next=NULL;
        printf("Deleted : %d",p->data);
        free(p);
    }
}
void insertAtParticular()
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert : ");
    scanf("%d",&value);
    printf("Enter position : ");
    scanf("%d",&pos);
    if(start==NULL)
    {
        newNode->next=NULL;
        newNode->data=value;
        start=newNode;
    }
    else 
    {
        struct node *p;
        p=start;
        for(i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        newNode->data=value;
        newNode->next=p->next;
        p->next=newNode;
    }
}
void DeleteAtParticular()
{
    struct node *p;
    printf("Enter position : ");
    scanf("%d",&pos);
    if(start==NULL)
    printf("The list is empty..");
    else if(pos==1&&start->next==NULL)
    {
        temp=start;
        start=NULL;
        printf("Deleted :%d");
        free(temp);
    }
    else if(pos==1)
    {
        temp=start;
        start=start->next;
        printf("Deleted :%d",temp->data);
        free(temp);
    }
    else{
        struct node *p;
        p=start;
        for(i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        printf("Deleted :%d",temp->data);
        free(temp);
    }
}
void main()
{
    printf("MENU\n1.insert at begning\n2.Delete At Begining\n3.insert at end\n4.delete at end\n5.insert At particular\n6.Delete at particular\n10.EXIT\n");
    do
    {
        printf("\nEnter choice : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            InsertAtBegin();
            Display();
            break;
            case 2:
            DeleteAtBegin();
            Display();
            break;
            case 3:
            insertAtEnd();
            Display();
            break;
            case 4:
            deleteAtEnd();
            Display();
            break;
            case 5:
            insertAtParticular();
            Display();
            break;
            case 6:
            DeleteAtParticular();
            Display();
            break;
            case 10:
            break;
            default:
            break;
        }
    } while (choice!=10); 
}
