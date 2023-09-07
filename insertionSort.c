#include<stdio.h>
int i;
void InsertionSort(int array[],int size)
{
    int j,key;
    for(i=1;i<size;i++)
    {
        key=array[i];
        j=i-1;
        while(array[j]>=key&&j>=0)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}
void main()
{
    int array[10],size;
    printf("How many elements are you going to enter ?:");
    scanf("%d",&size);
    printf("Enter the elements :\n");
    for(i=0;i<size;i++)
    scanf("%d",&array[i]);
    printf("\nThe elements you entered are : \n");
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
    InsertionSort(array,size);
    printf("\nthe sorted elements are : ");
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
}
