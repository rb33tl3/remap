#include <stdio.h>
#include <string.h>

int main()
{
    char text[200], find[50], replace[50], result[500];
    char *pos;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    printf("Enter word to find: ");
    scanf("%49s", find);

    printf("Enter word to replace: ");
    scanf("%49s", replace);

    result[0] = '\0';

    while((pos = strstr(text, find)) != NULL)
    {
        strncat(result, text, pos - text);
        strcat(result, replace);
        strcpy(text, pos + strlen(find));
    }

    strcat(result, text);

    printf("Updated text: %s\n", result);

    return 0;
}