#include <stdio.h>

// Function Prototypes
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void mergeSort(int arr[], int n);
void display(int arr[], int n);

int main()
{
    int arr[10], n, i, choice;

    printf("Enter number of elements(less than 10): ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Insertion Sort");
    printf("\n2. Selection Sort");
    printf("\n3. Bubble Sort");
    printf("\n4. Merge Sort");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            insertionSort(arr, n);
            printf("\nArray after Insertion Sort:\n");
            display(arr, n);
            break;

        case 2:
            selectionSort(arr, n);
            printf("\nArray after Selection Sort:\n");
            display(arr, n);
            break;

        case 3:
            bubbleSort(arr, n);
            printf("\nArray after Bubble Sort:\n");
            display(arr, n);
            break;

        case 4:
            mergeSort(arr, n);
            printf("\nArray after Merge Sort:\n");
            display(arr,n);
            break;

        default:
            printf("\nInvalid Choice!");
    }

    return 0;
}

// Insertion Sort Function
void insertionSort(int arr[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Selection Sort Function
void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Bubble Sort Function
void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge Sort Function
void mergeSort(int arr[], int n)
{
    int i, j, k, mid;
    int temp[10];
    if(n>1)
    {
        mid = n/2;
        mergeSort(arr, mid);
        mergeSort(arr+mid, n-mid);
        i=0;
        j=mid;
        k=0;
        while(i<mid&&j<n)
        {
            if(arr[i]<arr[j])
            {
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i<mid)
        {
              temp[k] = arr[i];
              i++;
              k++;
        }
        for(i=0;i<n;i++)
        {
            arr[i] = temp[i];
        }
    }        
}

// Display Function
void display(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
