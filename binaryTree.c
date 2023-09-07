#include<stdio.h>
void main()
{
    char array[20];
    int nodes=1,size,h,i,j,level;
    printf("Enter the height of your tree : ");
    scanf("%d",&h);
    level=h+1;
    size=(h*h)-1;
    printf("\nEnter root node data : ");
    scanf("%s",&array[0]);
    for(i=0;i<size;i++)
    {
        if(array[i]!='_'){
        printf("\nEnter left child of  %c : ",array[i]);
        scanf("%s",&array[2*i+1]);
        printf("\nEnter right child of  %c : ",array[i]);
        scanf("%s",&array[2*i+2]);
        }
        else{
            array[2*i+1]='_';
            array[2*i+2]='_';
        }
    }
    for(i=1;i<=level;i++)
    nodes=nodes*2;
    for(i=0;i<(nodes-1);i++)
    printf("%c\t",array[i]);
}
