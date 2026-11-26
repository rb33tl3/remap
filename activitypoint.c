
#include <stdio.h>

int main()
{
    int a[100], n, k, i, j, t, sum = 0;

    printf("Enter number of events: ");
    scanf("%d", &n);

    printf("Enter maximum events: ");
    scanf("%d", &k);

    printf("Enter activity points: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Sort activity points in descending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    // Select at most k positive activity points
    if (k > n)
        k = n;

    for (i = 0; i < k; i++)
    {
        if (a[i] > 0)
            sum += a[i];
        else
            break;
    }

    printf("Maximum activity points = %d\n", sum);

    return 0;
}
