#include <stdio.h>

struct Sparse
{
    int row;
    int col;
    int value;
};

int main()
{
    struct Sparse a[100], b[100];
    int m, n, i, j, k = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &a[0].value);

    a[0].row = m;
    a[0].col = n;

    printf("Enter row, column and value of each non-zero element:\n");

    for(i = 1; i <= a[0].value; i++)
    {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    for(i = 0; i < a[0].col; i++)
    {
        for(j = 1; j <= a[0].value; j++)
        {
            if(a[j].col == i)
            {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].value = a[j].value;
                k++;
            }
        }
    }

    printf("\nOriginal Sparse Matrix:\n");

    for(i = 0; i <= a[0].value; i++)
    {
        printf("%d\t%d\t%d\n",
               a[i].row, a[i].col, a[i].value);
    }

    printf("\nTranspose Sparse Matrix (Triplet Form):\n");

    for(i = 0; i <= b[0].value; i++)
    {
        printf("%d\t%d\t%d\n",
               b[i].row, b[i].col, b[i].value);
    }

    return 0;
}