#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAX 100

int top=-1;
int stack[MAX];


void push(int c)
{
    stack[++top]=c;
}


int pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}


int evaluate(char postfix[])
{
    int i;
    int a,b,result;
    char c;

    for(i=0; postfix[i]!='\0'; i++)
    {
        c=postfix[i];

        if(isdigit(c))
        {
            push(c-'0');
        }

        else
        {
            b=pop();
            a=pop();

            switch(c)
            {
                case '+':
                    result=a+b;
                    break;

                case '-':
                    result=a-b;
                    break;

                case '*':
                    result=a*b;
                    break;

                case '/':
                    result=a/b;
                    break;

                case '^':
                    result=pow(a,b);
                    break;
            }

            push(result);
        }
    }

    return pop();
}


int main()
{
    char postfix[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%99s",postfix);

    result=evaluate(postfix);

    printf("Result = %d\n",result);

    return 0;
}