#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char url[100];
    struct node *prev;
    struct node *next;
};

struct node *current = NULL;

void visit(char url[]) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    strcpy(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;

    if (current != NULL) {
        struct node *temp = current->next;

        while (temp != NULL) {
            struct node *del = temp;
            temp = temp->next;
            free(del);
        }

        current->next = newNode;
    }

    current = newNode;
    printf("Visited: %s\n", current->url);
}

void backward() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Current page: %s\n", current->url);
    } else {
        printf("No previous page!\n");
    }
}

void forward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Current page: %s\n", current->url);
    } else {
        printf("No next page!\n");
    }
}

void display() {
    if (current != NULL)
        printf("Current page: %s\n", current->url);
    else
        printf("No page visited yet!\n");
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n1. Visit Page");
        printf("\n2. Backward");
        printf("\n3. Forward");
        printf("\n4. Display Current Page");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%99s", url);
                visit(url);
                break;

            case 2:
                backward();
                break;

            case 3:
                forward();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
