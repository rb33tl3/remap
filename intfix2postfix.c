
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAX 100

int top=-1;
char stack[MAX];


void push(char c)
{
    stack[++top]=c;
}


char pop()
{
    if(top==-1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}


int precedence(char c)
{
    if(c=='/' || c=='*')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void infix2postfix(char infix[])
{
    char postfix[MAX];
    int i,j=0;
    char c;

    for(i=0; infix[i]!='\0'; i++)
    {
        c=infix[i];

        if(isalnum(c))
        {
            postfix[j++]=c;
        }

        else if(c=='(')
        {
            push(c);
        }

        else if(c==')')
        {
            while(top!=-1 && stack[top]!='(')
            {
                postfix[j++]=pop();
            }

            pop();
        }

        else
        {
            while(top!=-1 && stack[top]!='(' &&
                  precedence(stack[top])>=precedence(c))
            {
                postfix[j++]=pop();
            }

            push(c);
        }
    }

    while(top!=-1)
    {
        postfix[j++]=pop();
    }

    postfix[j]='\0';

    printf("Postfix expression is: %s\n",postfix);
}


int main()
{
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%99s",infix);

    infix2postfix(infix);

    return 0;
}
