#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, exp;
    struct node *next;
};

struct node *createNode(int c, int e) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    return newNode;
}

void insert(struct node **head, int c, int e) {
    struct node *newNode, *temp, *prev;

    if (c == 0)
        return;

    temp = *head;
    prev = NULL;

    while (temp != NULL && temp->exp > e) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->exp == e) {
        temp->coeff += c;
        if (temp->coeff == 0) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
        }
        return;
    }

    newNode = createNode(c, e);
    newNode->next = temp;

    if (prev == NULL)
        *head = newNode;
    else
        prev->next = newNode;
}

struct node *multiply(struct node *p1, struct node *p2) {
    struct node *result = NULL;
    struct node *a, *b;

    for (a = p1; a != NULL; a = a->next) {
        for (b = p2; b != NULL; b = b->next) {
            insert(&result,
                   a->coeff * b->coeff,
                   a->exp + b->exp);
        }
    }

    return result;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;

        if (head != NULL)
            printf(" + ");
    }

    printf("\n");
}

int main() {
    struct node *p1 = NULL, *p2 = NULL, *result = NULL;
    int n, i, c, e;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        insert(&p1, c, e);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        insert(&p2, c, e);
    }

    printf("First polynomial: ");
    display(p1);

    printf("Second polynomial: ");
    display(p2);

    result = multiply(p1, p2);

    printf("Product of polynomials: ");
    display(result);

    return 0;
}