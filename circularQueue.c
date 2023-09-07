#include<stdio.h>
int choice,size,front=-1,rear=-1,value,que[20],del,i;
void insert()
{
    if((front==0&&rear==size-1)||(front==rear+1))
    printf("Que is full...");
    else if(rear==size-1)
    {
        rear=0;
        printf("Enter value : ");
        scanf("%d",&value);
        que[rear]=value;
    }
    else
    {
        rear=(rear+1)%size;
        printf("Enter value : ");
        scanf("%d",&value);
        que[rear]=value;
    }
    if(front==-1)
    front=0;
}
void delete()
{
    if(front==-1)
    printf("Queue is empty...");
    else if(front==rear)
    {
        del=que[front];
        front=-1;
        rear=-1;
        printf("deleteed : %d",del);
    }
    else if(front==size-1)
    {
        del=que[front];
        front=0;
        printf("Deleted : %d",del);
    }
    else
    {
        del=que[front];
        front=(front+1)%size;
        printf("deletedd : %d",del);
    }
}
void display()
{
    if(front==-1)
    printf("Queue is empty..");
    else if(front>rear)
    {
        printf("\nThe elements are : ");
        for(i=front;i<size;i++)
            printf("%d",que[i]);
        for(i=0;i<=rear;i++)
        printf("%d",que[i]);
    }
    else
    {
        printf("\nThe elements are : ");
        for(i=front;i<=rear;i++)
        printf("%d",que[i]);
    }    
}
void main()
{
    printf("\nEnter size of que : ");
    scanf("%d",&size);
    printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do
    {
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("..Exit..");
            break;
            default:
            printf("Enter correct choice");
            break;
        }
    } while (choice!=4);
    
}
