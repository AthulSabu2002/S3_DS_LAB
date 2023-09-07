#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int choice;
struct node *qfront,*qrear;
void insert()
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node*));
     printf("Enter data : ");
     scanf("%d",&newNode->data);
     if(qfront==NULL)
     {
        qrear=qfront=newNode;
        qfront->next=qrear->next=NULL;
     }
     else
     {
        qrear->next=newNode;
        qrear=qrear->next;
        qrear->next=NULL;
     }
}
void delete()
{
    struct node *temp;
    if(qfront==NULL)
    printf("\nThe que is empty..");
    else if(qfront==qrear)
    {
        temp=qfront;
        qrear=NULL;
        qfront=NULL;
        printf("Deleted :  %d",temp->data);
        free(temp);
    }
    else
    {
        temp=qfront;
        qfront=qfront->next;
        printf("Deleted :  %d",temp->data);
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp=qfront;
    if(qfront==NULL)
    printf("\n There is nothing to display....");
    else{
        printf("\nThe elements are : ");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    }
}
void main()
{
    printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do
    {
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            display();
            break;
            case 2:
            delete();
            display();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("...Terminated...");
            break;
            default:
            printf("Enter correct choice : ");
            break;
        }
    } while (choice!=4);  
}
