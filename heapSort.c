#include<stdio.h>
int size,i,array[10];
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int array[],int size,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    while((left<size)&&(array[largest]<array[left]))
    largest=left;
    while((right<size)&&(array[largest]<array[right]))
    largest=right;
    if(largest!=i)
    {
        swap(&array[i],&array[largest]);
        heapify(array,size,largest);
    }
}
void heapSort(int array[],int size)
{
    for(i=size/2-1;i>=0;i--)
    heapify(array,size,i);
    for(i=size-1;i>=0;i--)
    {
        swap(&array[i],&array[0]);
        heapify(array,i,0);
    }
}
void main()
{
    printf("How many elements are you going to enter ?: ");
    scanf("%d",&size);
    printf("\nEnter the elements : \n");
    for(i=0;i<size;i++)
    scanf("%d",&array[i]);
    printf("The elements you entered are : \n");
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
    heapSort(array,size);
    printf("\nThe sorted elements are : \n");
    for(i=0;i<size;i++)
    printf("%d\t",array[i]);
}
