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
        for(j=i+1;j<size;j++)
        {
            if(array[j]<array[i])
            {
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
}
