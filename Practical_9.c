#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for automobile details
struct Automobile
{
    char type[30];
    char company[30];
    int year;
};

// Structure for BST node
struct Node
{
    struct Automobile data;
    struct Node *left;
    struct Node *right;
};

// Create a new BST node
struct Node* createNode(char type[], char company[], int year)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(newNode->data.type, type);
    strcpy(newNode->data.company, company);
    newNode->data.year = year;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert automobile into BST
// BST is ordered according to year of manufacture
struct Node* insert(struct Node *root, char type[], char company[], int year)
{
    if (root == NULL)
    {
        return createNode(type, company, year);
    }

    if (year < root->data.year)
    {
        root->left = insert(root->left, type, company, year);
    }
    else if (year > root->data.year)
    {
        root->right = insert(root->right, type, company, year);
    }
    else
    {
        printf("Automobile with year %d already exists.\n", year);
    }

    return root;
}

// Find minimum node in right subtree
struct Node* findMin(struct Node *root)
{
    struct Node *current = root;

    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Delete a node based on year
struct Node* deleteNode(struct Node *root, int year)
{
    struct Node *temp;

    if (root == NULL)
    {
        printf("Automobile with year %d not found.\n", year);
        return root;
    }

    if (year < root->data.year)
    {
        root->left = deleteNode(root->left, year);
    }
    else if (year > root->data.year)
    {
        root->right = deleteNode(root->right, year);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        // Case 3: Only left child
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Case 4: Two children
        else
        {
            temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,
                                     temp->data.year);
        }
    }

    return root;
}

// Display automobile details
void displayNode(struct Node *root)
{
    printf("%-15s %-15s %d\n",
           root->data.type,
           root->data.company,
           root->data.year);
}

// Inorder Traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        displayNode(root);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        displayNode(root);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        displayNode(root);
    }
}

// Main function
int main()
{
    struct Node *root = NULL;

    int choice;
    int year;
    char type[30];
    char company[30];

    do
    {
        printf("\n========================================\n");
        printf(" BINARY SEARCH TREE - AUTOMOBILE DATA\n");
        printf("========================================\n");
        printf("1. Insert Automobile\n");
        printf("2. Delete Automobile\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter automobile type: ");
                scanf("%s", type);

                printf("Enter company: ");
                scanf("%s", company);

                printf("Enter year of make: ");
                scanf("%d", &year);

                root = insert(root, type, company, year);

                printf("\nAutomobile inserted successfully.\n");
                break;

            case 2:
                printf("\nEnter year of automobile to delete: ");
                scanf("%d", &year);

                root = deleteNode(root, year);

                break;

            case 3:
                printf("\n--- INORDER TRAVERSAL ---\n");
                printf("%-15s %-15s %s\n",
                       "Type", "Company", "Year");
                printf("--------------------------------------------\n");

                inorder(root);
                break;

            case 4:
                printf("\n--- PREORDER TRAVERSAL ---\n");
                printf("%-15s %-15s %s\n",
                       "Type", "Company", "Year");
                printf("--------------------------------------------\n");

                preorder(root);
                break;

            case 5:
                printf("\n--- POSTORDER TRAVERSAL ---\n");
                printf("%-15s %-15s %s\n",
                       "Type", "Company", "Year");
                printf("--------------------------------------------\n");

                postorder(root);
                break;

            case 6:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
