#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    char data;
    struct node *left, *right;
};

struct stack {
    struct node *data;
    struct stack *next;
};

struct stack *top = NULL;

struct node *create_node(char value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void push(struct node *tree_node) {
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = tree_node;
    temp->next = top;
    top = temp;
}

struct node *pop() {
    if (top == NULL)
        return NULL;
    struct stack *temp = top;
    struct node *res = top->data;
    top = top->next;
    free(temp);
    return res;
}

struct node *create_exp_tree(char postfix[]) {
    int i = 0;
    char symbol;
    while ((symbol = postfix[i]) != '\0') {
        if (isalnum((unsigned char)symbol)) {
            struct node *operand_node = create_node(symbol);
            push(operand_node);
        } else {
            struct node *operator_node = create_node(symbol);
            operator_node->right = pop();
            operator_node->left = pop();
            push(operator_node);
        }
        i++;
    }
    return pop();
}

void inorder(struct node *root) {
    if (root != NULL) {
        if (root->left && root->right)
            printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (root->left && root->right)
            printf(")");
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    struct node *root = NULL;
    int choice;
    char postfix[100];

    do {
        printf("\n______Menu______\n");
        printf("1. Create expression tree\n2. Inorder traversal\n3. Preorder traversal\n4. Postorder traversal\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Postfix expression: ");
                scanf("%99s", postfix);
                root = create_exp_tree(postfix);
                printf("Expression tree created\n");
                break;
            case 2:
                if (root == NULL)
                    printf("Create the tree first\n");
                else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Create the tree first\n");
                else {
                    printf("Preorder traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL)
                    printf("Create the tree first\n");
                else {
                    printf("Postorder traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting....\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}