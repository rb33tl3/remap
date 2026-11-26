#include <stdio.h>
struct sparse
{
    int row;
    int col;
    int value;
};
int main()
{
    struct sparse A[20], B[20], sum[40];
    int i, j, k;
    int rows, cols, terms1, terms2;

    printf("Enter rows, columns and non-zero elements of first matrix: ");
    scanf("%d%d%d", &rows, &cols, &terms1);

    A[0].row = rows;
    A[0].col = cols;
    A[0].value = terms1;

    printf("Enter row, column and value of first matrix:\n");
    for (i = 1; i <= terms1; i++)
    {
        scanf("%d%d%d", &A[i].row, &A[i].col, &A[i].value);
    }

    printf("Enter rows, columns and non-zero elements of second matrix: ");
    scanf("%d%d%d", &rows, &cols, &terms2);

    B[0].row = rows;
    B[0].col = cols;
    B[0].value = terms2;

    printf("Enter row, column and value of second matrix:\n");
    for (i = 1; i <= terms2; i++)
    {
        scanf("%d%d%d", &B[i].row, &B[i].col, &B[i].value);
    }

    if (A[0].row != B[0].row || A[0].col != B[0].col)
    {
        printf("Addition not possible.\n");
        return 0;
    }

    i = 1;
    j = 1;
    k = 1;
    while (i <= terms1 && j <= terms2)
    {
        if (A[i].row == B[j].row && A[i].col == B[j].col)
        {
            sum[k].row = A[i].row;
            sum[k].col = A[i].col;
            sum[k].value = A[i].value + B[j].value;
            i++;
            j++;
            k++;
        }
        else if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
        {
            sum[k] = A[i];
            i++;
            k++;
        }
        else
        {
            sum[k] = B[j];
            j++;
            k++;
        }
    }

    while (i <= terms1)
    {
        sum[k] = A[i];
        i++;
        k++;
    }

    while (j <= terms2)
    {
        sum[k] = B[j];
        j++;
        k++;
    }

    sum[0].row = rows;
    sum[0].col = cols;
    sum[0].value = k - 1;

    printf("\nSum of sparse matrices:\n");

    for (i = 0; i < k; i++)
    {
        printf("%d\t%d\t%d\n",
               sum[i].row,
               sum[i].col,
               sum[i].value);
    }

    return 0;
}

