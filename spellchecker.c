#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char table[SIZE][30];

int hash(char word[])
{
    int sum = 0, i;

    for(i = 0; word[i] != '\0'; i++)
        sum += tolower(word[i]);

    return sum % SIZE;
}

void insert(char word[])
{
    int i = hash(word);

    while(table[i][0] != '\0')
        i = (i + 1) % SIZE;

    strcpy(table[i], word);
}

int search(char word[])
{
    int i = hash(word);
    int start = i;

    while(table[i][0] != '\0')
    {
        if(strcmp(table[i], word) == 0)
            return 1;

        i = (i + 1) % SIZE;

        if(i == start)
            break;
    }

    return 0;
}

int main()
{
    char word[30];
    int i;

    char dictionary[][30] = {
        "apple", "banana", "computer",
        "school", "hello", "world"
    };

    for(i = 0; i < 6; i++)
        insert(dictionary[i]);

    printf("Enter a word: ");
    scanf("%29s", word);

    for(i = 0; word[i] != '\0'; i++)
        word[i] = tolower(word[i]);

    if(search(word))
    {
        printf("Correct spelling!\n");
    }
    else
    {
        printf("Misspelled word!\n");
        printf("Suggestions:\n");

        for(i = 0; i < 6; i++)
        {
            if(word[0] == dictionary[i][0])
                printf("%s\n", dictionary[i]);
        }
    }

    return 0;
}