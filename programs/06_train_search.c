#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, choice;
    int trainNo[10];
    char trainName[10][30];
    int found = 0;

    printf("===== TRAIN SEARCH SYSTEM =====\n");

    printf("Enter number of trains (maximum 10): ");
    scanf("%d", &n);

    if(n <= 0 || n > 10)
    {
        printf("Invalid number of trains.\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\n--- Train %d ---\n", i + 1);

        printf("Enter train number: ");
        scanf("%d", &trainNo[i]);

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
        int searchNumber;

        printf("Enter train number: ");
        scanf("%d", &searchNumber);

        for(i = 0; i < n; i++)
        {
            if(trainNo[i] == searchNumber)
            {
                printf("\n===== TRAIN FOUND =====\n");
                printf("Train Number : %d\n", trainNo[i]);
                printf("Train Name   : %s\n", trainName[i]);
                found = 1;
                break;
            }
        }
    }
    else if(choice == 2)
    {
        char searchName[30];

        printf("Enter train name: ");
        scanf(" %[^\n]", searchName);

        for(i = 0; i < n; i++)
        {
            if(strcmp(trainName[i], searchName) == 0)
            {
                printf("\n===== TRAIN FOUND =====\n");
                printf("Train Number : %d\n", trainNo[i]);
                printf("Train Name   : %s\n", trainName[i]);
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
