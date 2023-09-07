#include<stdio.h>
void main()
{
    int size,i,search,mid,left,right,arr[10],count=0;
    printf("Enter the size of array : \n");
    scanf("%d",&size);
    printf("Enter the array elements in ascending order : \n");
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);
    printf("\nEnter the search element : ");
    scanf("%d",&search);
    left=0;
    right=size-1;
    while(left<right)
    {
        mid=(left+right)/2;
        if(arr[mid]==search)
        {
            count++;
            printf("Found...at index %d",mid+1);
            break;
        }
        else if(arr[mid]>search)
        right=mid-1;
        else
        left=mid+1;
    }
    if((left>right)||(count==0))
    {
        printf("The element not found...");
    }
}
