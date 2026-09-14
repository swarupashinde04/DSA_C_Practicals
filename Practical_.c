#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert node at front
void insertFront(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;

    printf("Node inserted at front.\n");
}

// Delete first node
void deleteFirst()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);

    printf("First node deleted.\n");
}

// Delete node before specified position
void deleteBeforePosition(int position)
{
    struct Node *current;
    struct Node *deleteNode;

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    // No node exists before first position
    if (position <= 1)
    {
        printf("No node exists before position %d.\n", position);
        return;
    }

    current = head;

    // Move current to specified position
    int i;

    for (i = 1; i < position && current != NULL; i++)
    {
        current = current->next;
    }

    // Position does not exist
    if (current == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    // Node before current
    deleteNode = current->prev;

    // If deleting the first node
    if (deleteNode->prev == NULL)
    {
        head = current;
        current->prev = NULL;
    }
    else
    {
        deleteNode->prev->next = current;
        current->prev = deleteNode->prev;
    }

    free(deleteNode);

    printf("Node before position %d deleted.\n", position);
}

// Display list
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice, value, position;

    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Front\n");
        printf("2. Delete First Node\n");
        printf("3. Delete Node Before Specified Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteBeforePosition(position);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
