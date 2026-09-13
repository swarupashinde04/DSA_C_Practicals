#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to insert at front
void insertFront(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at front.\n");
}

// Function to insert at end
void insertEnd(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}

// Function to insert in ascending order
void insertAscending(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning if list is empty
    // or value is smaller than first node
    if (head == NULL || value < head->data)
    {
        newNode->next = head;
        head = newNode;
        printf("Node inserted in ascending order.\n");
        return;
    }

    temp = head;

    // Find the correct position
    while (temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted in ascending order.\n");
}

// Function to display the linked list
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Ascending Order\n");
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
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAscending(value);
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
