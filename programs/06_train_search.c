#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, choice, trainNo, found = 0;
    char searchName[30];
    char trainName[10][30];
    int numbers[10];

    printf("Enter number of trains: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nTrain %d\n", i + 1);

        printf("Enter train number: ");
        scanf("%d", &numbers[i]);

        printf("Enter train name: ");
        scanf(" %[^\n]", trainName[i]);
    }

    printf("\nSearch Train By:\n");
    printf("1. Train Number\n");
    printf("2. Train Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter train number to search: ");
        scanf("%d", &trainNo);

        for(i = 0; i < n; i++)
        {
            if(numbers[i] == trainNo)
            {
                printf("\nTrain Found!\n");
                printf("Train Number: %d\n", numbers[i]);
                printf("Train Name: %s\n", trainName[i]);
                found = 1;
                break;
            }
        }
    }
    else if(choice == 2)
    {
        printf("Enter train name to search: ");
        scanf(" %[^\n]", searchName);

        for(i = 0; i < n; i++)
        {
            if(strcmp(trainName[i], searchName) == 0)
            {
                printf("\nTrain Found!\n");
                printf("Train Number: %d\n", numbers[i]);
                printf("Train Name: %s\n", trainName[i]);
                found = 1;
                break;
            }
        }
    }
    else
    {
        printf("Invalid choice.\n");
        return 0;
    }

    if(found == 0)
        printf("\nTrain not found.\n");

    return 0;
}
