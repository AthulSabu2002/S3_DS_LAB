#include<stdio.h>
int n,q[20],stack[10],adj[10][10],i,j,choice,vis[10],front=-1,rear=-1,s,top=-1;
void enq(int item)
{
    if(rear==19)
    printf("que is full");
    else{
        if(front==-1||rear==-1)
        {
            q[++rear]=item;
            front++;
        }
        else{
            q[++rear]=item;
        }
    }
}
int deq()
{
    if(front==-1||front>rear)
    return 0;
    else{
        return q[front++];
    }
}
void push(int item)
{
    if(top==9)
    printf("Stack is full ..");
    else{
        stack[++top]=item;
    }
}
int pop()
{
    if(top==-1)
    return 0;
    else{
        return stack[top--];
    }
}
void dfs(int s,int n)
{
    int k;
    push(s);
    vis[s]=1;
    k=pop();
    if(k!=0)
    printf("%d ",k);
    while(k!=0)
    {
        for(i=1;i<=n;i++)
        if((adj[k][i]==1)&&(vis[i]==0))
        {
            push(i);
            vis[i]=1;
        }
        k=pop();
        if(k!=0)
        printf(" %d ",k);
    }
    for(i=1;i<=n;i++)
    if(vis[i]==0)
    dfs(i,n);
}
void bfs(int s,int n)
{
    enq(s);
    vis[s]=1;
    int p=deq();
    if(p!=0)
    printf("%d ",p);
    while(p!=0)
    {
        for(i=1;i<=n;i++)
        if((adj[p][i]==1)&&(vis[i]==0))
        {
            enq(i);
            vis[i]=1;
        }
        p=deq();
        if(p!=0)
        printf("%d ",p);
    }
    for(i=1;i<=n;i++)
    if(vis[i]==0)
    bfs(i,n);
}
void main()
{
    printf("Enter the number of vertices : \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\npress 1 if %d is adjacent to %d otherwise press 0 : ",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nThe adjacency matrix you entered is : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    printf("\nMENU\n1.BFS\n2.DFS\n3.EXIT");
    do
    {
     for(i=1;i<=n;i++)
     vis[i]=0;
      printf("\nEnter the choice : ");
      scanf("%d",&choice);
      switch (choice)
      {
      case 1:
      printf("\nEnter source vertex : ");
      scanf("%d",&s);
        bfs(s,n);
        break;
      case 2:
        printf("\nEnter source vertex : ");
        scanf("%d",&s);
        dfs(s,n);
        break;
    case 3:
        break;
      default:
        break;
      }
    }while(choice!=3);
}
