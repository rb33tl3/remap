#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10][10] , r, c, x, y, i, j, d, min;
    printf("Enter number of rows and columns : ");
    scanf("%d%d",&r,&c);
    printf("Enter matrix :(0 = empty | 1 = landmine)");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Distance matrix ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]==1)
            {
                printf("0");
            }
            else
            {
                min=999;
                for(x=0;x<r;x++)
                {
                    for(y=0;y<c;y++)
                    {
                        if(a[x][y]==1)
                        {
                            d = abs(i-x)+abs(j-y);
                            if(d<min)
                                min=d;
                        }
                    }
                }
                printf("%d\t",min);
            }
        }
        printf("\n");
    }
    return 0;
}