#include <stdio.h>

void displayArray(int *p, int n)
{
    int i;

    printf("\nArray elements: ");

    for(i = 0; i < n; i++)
        printf("%d ", *(p + i));

    printf("\n");
}

int calculateSum(int *p, int n)
{
    int i, sum = 0;

    for(i = 0; i < n; i++)
        sum += *(p + i);

    return sum;
}

int findLargest(int *p, int n)
{
    int i, largest = *p;

    for(i = 1; i < n; i++)
    {
        if(*(p + i) > largest)
            largest = *(p + i);
    }

    return largest;
}

int main()
{
    int arr[20];
    int n, i, choice;

    printf("===== ARRAY & POINTER SYSTEM =====\n");

    printf("Enter number of elements (maximum 20): ");
    scanf("%d", &n);

    if(n <= 0 || n > 20)
    {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Display Array\n");
        printf("2. Calculate Sum\n");
        printf("3. Find Largest Element\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayArray(arr, n);
                break;

            case 2:
                printf("Sum = %d\n", calculateSum(arr, n));
                break;

            case 3:
                printf("Largest Element = %d\n", findLargest(arr, n));
                break;

            case 4:
                printf("Exiting array system.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}
