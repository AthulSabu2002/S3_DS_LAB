#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int expo;
    int coeff;
    struct poly*next;
};
int s1,s2,s3;
struct poly*createNode(struct poly*polynomial,int length);
void readElements(struct poly*polynomial);
void printPoly(struct poly*polynomial);
void addPoly(struct poly *polynomial1,struct poly *polynomial2,struct poly *polynomial3);
void main()
{
    struct poly *poly1,*poly2,*poly3;
    poly1=(struct poly*)malloc(sizeof(struct poly));
    poly2=(struct poly*)malloc(sizeof(struct poly));
    poly3=(struct poly*)malloc(sizeof(struct poly));
    printf("Enter the size of first polynomial : ");
    scanf("%d",&s1);
    poly1=createNode(poly1,s1);
    readElements(poly1);
    printf("\nThe first polynomial is : ");
    printPoly(poly1);
    printf("\nEnter the size of second polynomial : ");
    scanf("%d",&s2);
    poly2=createNode(poly2,s2);
    readElements(poly2);
    printf("\nThe second polynomial is : ");
    printPoly(poly2);
    s3=s1;
    if(s2>=s1)
        s3=s2;
    poly3=createNode(poly3,s3);
    addPoly(poly1,poly2,poly3);
    printf("\nThe resultant polynomial is : ");
    printPoly(poly3);
}
struct poly*createNode(struct poly*polynomial,int length)
{
    struct poly*temp;
    int i;
    for(i=0;i<=length;i++)
    {
        if(i==0)
        {
            if(length==1)
            {
                polynomial->next=NULL;
            }
            temp=polynomial;
        }
        else
        {
            struct poly *newNode;
            newNode=(struct poly*)malloc(sizeof(struct poly));
            temp->next=newNode;
            newNode->next=NULL;
            temp=newNode;
        }
    }
    return polynomial;
}
void readElements(struct poly *polynomial)
{
    while(polynomial->next!=NULL)
    {
        printf("Enter the coefficient : ");
        scanf("%d",&polynomial->coeff);
        printf("Enter the exponent : ");
        scanf("%d",&polynomial->expo);
        polynomial=polynomial->next;
    }

}
void printPoly(struct poly *polynomial)
{
    while(polynomial->next!=NULL)
    {
        printf("%d(X^%d)",polynomial->coeff,polynomial->expo);
        polynomial=polynomial->next;
        if(polynomial->next!=NULL)
            printf("  +  ");
    }
}
void addPoly(struct poly *polynomial1,struct poly *polynomial2,struct poly *polynomial3)
{
    while(polynomial1->next!=NULL&&polynomial2->next!=NULL)
    {
        if (polynomial1->expo>polynomial2->expo)
         {
          polynomial3->expo=polynomial1->expo;
          polynomial3->coeff=polynomial1->coeff;
          polynomial1=polynomial1->next;
          polynomial3=polynomial3->next;
         }
        else if(polynomial1->expo==polynomial2->expo)
        {
            polynomial3->expo=polynomial1->expo;
            polynomial3->coeff=polynomial1->coeff+polynomial2->coeff;
            polynomial3=polynomial3->next;
            polynomial2=polynomial2->next;
            polynomial1=polynomial1->next;
        }
        else
        {
          polynomial3->expo=polynomial2->expo;
          polynomial3->coeff=polynomial2->coeff;
          polynomial2=polynomial2->next;
          polynomial3=polynomial3->next;
        }
    }
       while(polynomial1->next!=NULL)
        {
            polynomial3->expo=polynomial1->expo;
            polynomial3->coeff=polynomial1->coeff;
            polynomial1=polynomial1->next;
            polynomial3=polynomial3->next;
        }
        while(polynomial2->next!=NULL)
        {
            polynomial3->expo=polynomial2->expo;
            polynomial3->coeff=polynomial2->coeff;
            polynomial3=polynomial3->next;
            polynomial2=polynomial2->next;
        }
        polynomial3->next=NULL;
}
