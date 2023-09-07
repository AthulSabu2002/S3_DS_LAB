#include<stdio.h>
void main()
{
    int i,j,key,hkey,index,size;
    printf("Enter the size of table : ");
    scanf("%d",&size);
    int table[size];
    for(j=0;j<size;j++)
    {
        table[j]=0;
    }
     printf("Enter values : ");
    for(j=0;j<size;j++)
    {
        scanf("%d",&key);
        hkey=key%size;
        for(i=0;i<size;i++)
        {
            index=(hkey+i)%size;
            if(table[index]==0)
            {
                table[index]=key;
                break;
            }
        }
    }
    printf("The table is : \n");
    printf("|  index  |  values  |\n");
    for(i=0;i<size;i++)
    printf("|    %d   |    %d   |\n",i,table[i]);
}
