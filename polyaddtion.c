
#include<stdio.h>

struct Polynomial
{
    int coeff;
    int exp;
};

int main()
{
    struct Polynomial p1[100],p2[100],sum[200];

    int n1,n2,n3=0;
    int i,j;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d",&n1);

    printf("Enter coefficient and exponent:\n");

    for(i=0;i<n1;i++)
    {
        scanf("%d%d",&p1[i].coeff,&p1[i].exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d",&n2);

    printf("Enter coefficient and exponent:\n");

    for(i=0;i<n2;i++)
    {
        scanf("%d%d",&p2[i].coeff,&p2[i].exp);
    }

    
    i=0;
    j=0;

    while(i<n1 && j<n2)
    {
        if(p1[i].exp==p2[j].exp)
        {
            sum[n3].coeff=p1[i].coeff+p2[j].coeff;
            sum[n3].exp=p1[i].exp;

            i++;
            j++;
            n3++;
        }

        else if(p1[i].exp>p2[j].exp)
        {
            sum[n3]=p1[i];
            i++;
            n3++;
        }

        else
        {
            sum[n3]=p2[j];
            j++;
            n3++;
        }
    }

    
    while(i<n1)
    {
        sum[n3]=p1[i];
        i++;
        n3++;
    }

    
    while(j<n2)
    {
        sum[n3]=p2[j];
        j++;
        n3++;
    }


    
    printf("\nSum of polynomials: ");

    for(i=0;i<n3;i++)
    {
        printf("%dx^%d",sum[i].coeff,sum[i].exp);

        if(i<n3-1)
        {
            printf(" + ");
        }
    }

    printf("\n");

    return 0;
}
