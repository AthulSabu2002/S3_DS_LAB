#include<stdio.h>
int k,i,j,s1,s2;
void merge(int array[],int start,int mid,int end)
{
    s1=mid-start+1;
    s2=end-mid;
    int arr1[s1],arr2[s2];
    for(i=0;i<s1;i++)
        arr1[i]=array[start+i];
    for(j=0;j<s2;j++)
        arr2[j]=array[mid+1+j];
    i=0;
    j=0;
    k=start;
    while((i<s1)&&(j<s2))
    {
        if(arr1[i]<=arr2[j])
            array[k++]=arr1[i++];
        else
            array[k++]=arr2[j++];
    }
    while(i<s1)
        array[k++]=arr1[i++];
    while(j<s2)
        array[k++]=arr2[j++];
}
void mergesort(int array[],int start,int end)
{
    if(start!=end)
    {
        int mid=(start+end)/2;
        mergesort(array,start,mid);
        mergesort(array,mid+1,end);
        merge(array,start,mid,end);
    }
}
void main()
{
    int size,array[10],i;
    printf("How many elements are you going to enter ? : ");
    scanf("%d",&size);
    printf("Enter the elements :\n");
    for(i=0;i<size;i++)
        scanf("%d",&array[i]);
    printf("The elements you entered are :\n");
    for(i=0;i<size;i++)
        printf("%d\t",array[i]);
    mergesort(array,0,size-1);
    printf("\nThe sorted elements are: \n");
    for(i=0;i<size;i++)
            printf("%d\t",array[i]);
}
