#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("Element pushed successfully.\n");
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", stack[top]);
    top--;
}

// Peek operation
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

// Update operation
void update()
{
    int pos, value;

    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Enter position from top: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > top + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    stack[top - pos + 1] = value;

    printf("Element updated successfully.\n");
}

// Display operation
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Update\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                update();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
