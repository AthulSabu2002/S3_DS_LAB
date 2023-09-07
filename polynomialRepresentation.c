#include<stdio.h>
struct poly{
int coeff;
int expo;
};
int s1,i;
struct poly p[10];
void CreatePoly(int s1)
{
    printf("Enter highest exponent first...\n");
    for(i=0;i<s1;i++)
    {
        printf("\nEnter the coefficient : ");
        scanf("%d",&p[i].coeff);
        printf("Enter the exponent : ");
        scanf("%d",&p[i].expo);
    }
    printf("\nThe polynomial is : \n");
    for(i=0;i<s1;i++)
    {
        printf("%d(X^%d)",p[i].coeff,p[i].expo);
        if(i!=(s1-1))
        printf(" + ");
    }
}
void main()
{
    printf("Enter the size of polynomial1 : ");
    scanf("%d",&s1);
    CreatePoly(s1);
}
