#include<stdio.h>
int choice,q[10],front=-1,rear=-1,size,item,i;
void insert()
{
    if(rear==size-1)
    printf("\nThe que is full..");
    else if(front==-1)
    {
        printf("Enter the value : ");
        scanf("%d",&item);
        q[++rear]=item;
        front=0;
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&item);
        q[++rear]=item;
    }
}
void delete()
{
    if(front==-1)
    printf("\nThe que is empty...");
    else{
        if(front==size-1)
        {
            int del=q[front];
            printf("Deleted  : %d",del);
            front=-1;
        }
        else{
            int del=q[front++];
            printf("Deleted  : %d",del);
        }
    }
}
void Display()
{
    if(front==-1)
    printf("The queue is empty...");
    else{
        printf("The queue elements are : \n");
        for(i=front;i<=rear;i++)
        printf("%d\t",q[i]);
    }
}
void main()
{
    printf("Enter size of queue : ");
    scanf("%d",&size);
    printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do
    {
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            Display();
            break;
            case 2:
            delete();
            Display();
            break;
            case 3:
            Display();
            break;
            case 4:
            break;
            default:
            printf("Enter correct choice : ");
            break;
        }
    } while(choice!=4); 
}
