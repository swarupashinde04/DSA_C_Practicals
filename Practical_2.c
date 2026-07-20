#include <stdio.h>

int main()
{
    int arr[10], n, i, j, key;
    int choice;
    int low, high, mid;
    int found = 0;
    int temp, swapped;

    printf("Enter number of elements(less than 10): ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter element to search: ");
    scanf("%d", &key);

    switch(choice)
    {
        case 1:

            found = 0;

            for(i = 0; i < n; i++)
            {
                if(arr[i] == key)
                {
                    printf("Element found at position %d\n", i + 1);
                    found = 1;
                }
            }

            if(found == 0)
            {
                printf("Element not found");
            }

            break;

        case 2:

            // Bubble Sort
            for(i = 0; i < n - 1; i++)
            {
                swapped = 0;

                for(j = 0; j < n - 1 - i; j++)
                {
                    if(arr[j] > arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                        swapped = 1;
                    }
                }

                if(swapped == 0)
                {
                    break;
                }
            }

            found = 0;
            low = 0;
            high = n - 1;

            while(low <= high)
            {
                mid = (low + high) / 2;

                if(arr[mid] == key)
                {
                    printf("Element found at position %d", mid + 1);
                    found = 1;
                    break;
                }
                else if(key < arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            if(found == 0)
            {
                printf("Element not found");
            }

            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}