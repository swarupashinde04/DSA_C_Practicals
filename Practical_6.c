#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue\n", value);
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d deleted from queue\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
