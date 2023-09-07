#include<stdio.h>
#include<ctype.h>
int top=-1;
char stack[100];
void push(char c)
{
    stack[++top]=c;
}
char pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
int priority(char c)
{
    if(c=='(')
    return 0;
    if(c=='+'||c=='-')\
    return 1;
    if(c=='*'||c=='/')
    return 2;
    return 0;
}
void main()
{
    char expre[100],c,*p;
    printf("Enter the expression : \n");
    scanf("%s",expre);
    printf("The postfix expression is :\n");
    p=expre;
    while(*p!='\0')
    {
        if(isalnum(*p))
        printf("%c",*p);
        else if(*p=='(')
        push(*p);
        else if(*p==')')
        {
            while((c=pop())!='(')
            printf("%c",c);
        }
        else
        {
            while((priority(stack[top]))>=(priority(*p)))
            printf("%c",pop());
            push(*p);
        }
        p++;
    }
    while(top!=-1)
    printf("%c",pop());
}
