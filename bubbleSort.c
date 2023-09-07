#include<stdio.h>
int size,i,j,array[10];
void main()
{
    printf("How many elements are you going to enter ?: ");
    scanf("%d",&size);
    printf("\nEnter the elements : \n");
    for(i=0;i<size;i++)
    scanf("%d",&array[i]);
    printf("\nThe elements you entered are : \n");
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
    printf("\nThe sorted elements are : \n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
}
