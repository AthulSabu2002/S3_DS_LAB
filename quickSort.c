#include<stdio.h>
int temp,array[10],i,j;
void QuickSort(int array[],int first,int last)
{
    if(first<last)
    {
        i=first;
        j=last;
        int pivot=first;
        while(i<j)
        {
            while((i<j)&&(array[i]<=array[pivot]))
            i++;
            while(array[j]>array[pivot])
            j--;
            if(i<j)
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
        temp=array[j];
        array[j]=array[pivot];
        array[pivot]=temp;
        QuickSort(array,first,j-1);
        QuickSort(array,j+1,last);
    }
}
void main()
{
    int size;
    printf("How many elements are you going to enter ?:");
    scanf("%d",&size);
    printf("Enter the elements :\n");
    for(i=0;i<size;i++)
    scanf("%d",&array[i]);
    printf("The elements you entered are : \n");
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
    QuickSort(array,0,size-1);
    printf("\nThe sorted elements are : \n");
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
}
