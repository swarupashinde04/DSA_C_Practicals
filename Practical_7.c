#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// 1. Insert node at front
void insertFront(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    cout << "Node inserted at front.\n";
}

// 2. Delete first node
void deleteFirst()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;

    cout << "First node deleted.\n";
}

// 3. Delete node before specified position
void deleteBeforePosition(int pos)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    // No node exists before position 1
    if (pos <= 1)
    {
        cout << "No node exists before this position.\n";
        return;
    }

    Node* current = head;

    // Move to specified position
    for (int i = 1; i < pos; i++)
    {
        if (current == NULL)
        {
            cout << "Invalid position.\n";
            return;
        }

        current = current->next;
    }

    if (current == NULL)
    {
        cout << "Invalid position.\n";
        return;
    }

    // Node before current
    Node* temp = current->prev;

    if (temp == NULL)
    {
        cout << "No node exists before this position.\n";
        return;
    }

    // Connect previous node with current
    if (temp->prev != NULL)
        temp->prev->next = current;
    else
        head = current;

    current->prev = temp->prev;

    delete temp;

    cout << "Node before position " << pos << " deleted.\n";
}

// Display list
void display()
{
    Node* temp = head;

    if (temp == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    cout << "Doubly Linked List: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, value, pos;

    do
    {
        cout << "\n--- DOUBLY LINKED LIST ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Delete First Node\n";
        cout << "3. Delete Node Before Position\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertFront(value);
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                cout << "Enter position: ";
                cin >> pos;
                deleteBeforePosition(pos);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
