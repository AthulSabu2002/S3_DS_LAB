#include<stdio.h>
int a[10][10],i,j,r,c,b[10][3];
void CreateSparse(int a[10][10],int b[10][3],int r,int c)
{
    int k=1;
    b[0][0]=r;
    b[0][1]=c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][2]=k-1;
}
void PrintSparse(int b[10][3])
{
    int size=b[0][2];
    for(i=0;i<=size;i++)
    printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
}
void main()
{
    printf("Enter the order of matrix : \n");
    printf("Row : ");
    scanf("%d",&r);
    printf("\nColumn : ");
    scanf("%d",&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("mat1[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe matrix you entered is : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("\nThe tuple form is : \n");
    CreateSparse(a,b,r,c);
    PrintSparse(b);
}
