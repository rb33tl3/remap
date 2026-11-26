#include <stdio.h>
#include <string.h>

int main()
{
    char name[4][50], temp[50];
    int priority[4] = {3, 1, 2, 4};
    int i, j, p[4] = {0};

    printf("Enter customer names:\n");

    printf("Defence personnel: ");
    scanf("%49s", name[0]);

    printf("Differently abled: ");
    scanf("%49s", name[1]);

    printf("Senior citizen: ");
    scanf("%49s", name[2]);

    printf("Ordinary person: ");
    scanf("%49s", name[3]);

    /* Arrange customers by priority */
    for(i = 0; i < 4; i++)
    {
        for(j = i + 1; j < 4; j++)
        {
            if(priority[i] > priority[j])
            {
                int t = priority[i];
                priority[i] = priority[j];
                priority[j] = t;

                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    printf("\nCustomer service sequence:\n");

    for(i = 0; i < 4; i++)
        printf("%d. %s\n", i + 1, name[i]);

    return 0;
}