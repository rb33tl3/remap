
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Block
{
    int block_id;
    int size;
    int allocated;  // 0 = Free, 1 = Allocated
    struct Block *prev;
    struct Block *next;
};

struct Block *head = NULL;

// Create a new memory block
struct Block *createBlock(int id, int size)
{
    struct Block *newBlock =
        (struct Block *)malloc(sizeof(struct Block));

    if (newBlock == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newBlock->block_id = id;
    newBlock->size = size;
    newBlock->allocated = 0;
    newBlock->prev = NULL;
    newBlock->next = NULL;

    return newBlock;
}

// Add a block to the list
void addBlock(int id, int size)
{
    struct Block *newBlock = createBlock(id, size);

    if (newBlock == NULL)
        return;

    if (head == NULL)
    {
        head = newBlock;
    }
    else
    {
        struct Block *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newBlock;
        newBlock->prev = temp;
    }

    printf("Memory block added successfully.\n");
}

// Allocate a memory block
void allocateBlock(int id)
{
    struct Block *temp = head;

    while (temp != NULL)
    {
        if (temp->block_id == id)
        {
            if (temp->allocated == 0)
            {
                temp->allocated = 1;
                printf("Block %d allocated successfully.\n", id);
            }
            else
            {
                printf("Block %d is already allocated.\n", id);
            }

            return;
        }

        temp = temp->next;
    }

    printf("Block %d not found.\n", id);
}

// Garbage collection (deallocate a block)
void garbageCollect(int id)
{
    struct Block *temp = head;

    while (temp != NULL)
    {
        if (temp->block_id == id)
        {
            if (temp->allocated == 1)
            {
                temp->allocated = 0;
                printf("Block %d deallocated successfully "
                       "(garbage collected).\n", id);
            }
            else
            {
                printf("Block %d is already free.\n", id);
            }

            return;
        }

        temp = temp->next;
    }

    printf("Block %d not found.\n", id);
}

// Display memory status
void displayMemory()
{
    struct Block *temp = head;

    printf("\nMemory Status:\n");
    printf("ID\tSize\tStatus\n");

    while (temp != NULL)
    {
        printf("%d\t%d\t%s\n",
               temp->block_id,
               temp->size,
               temp->allocated ? "Allocated" : "Free");

        temp = temp->next;
    }
}

// Main function
int main()
{
    int choice, id, size;

    do
    {
        printf("\nMenu:\n");
        printf("1. Add Memory Block\n");
        printf("2. Allocate Block\n");
        printf("3. Garbage Collect (Free Block)\n");
        printf("4. Display Memory\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter block ID and size: ");
                scanf("%d %d", &id, &size);
                addBlock(id, size);
                break;

            case 2:
                printf("Enter block ID to allocate: ");
                scanf("%d", &id);
                allocateBlock(id);
                break;

            case 3:
                printf("Enter block ID to free: ");
                scanf("%d", &id);
                garbageCollect(id);
                break;

            case 4:
                displayMemory();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
