#include<stdio.h>
int main()
{
    int arr[10],n,i,element,remove;

    //Create :
    printf("Enter number of elements (less than 10): ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    //Append :
    printf("Enter element to append : ");
    scanf("%d",&element);
    arr[n] = element;
    n++;

    printf("Array after appending: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    //Remove :
    printf("\nEnter element to remove : ");
    scanf("%d",&remove);

    for(i=0;i<n;i++)
    {
        if(arr[i]==remove)
        {
            for(int j=i;j<n-1;j++)
            {
                arr[j]=arr[j+1];
            }
            n--;
            break;
        }
    }
    printf("Array after removing %d: ", remove);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;

}