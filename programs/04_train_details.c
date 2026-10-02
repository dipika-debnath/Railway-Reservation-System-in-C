#include <stdio.h>

int main()
{
    int n, i;
    int trainNo[10];
    int seats[10];

    printf("Enter number of trains: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nTrain %d\n", i + 1);

        printf("Enter train number: ");
        scanf("%d", &trainNo[i]);

        printf("Enter available seats: ");
        scanf("%d", &seats[i]);
    }

    printf("\n===== TRAIN DETAILS =====\n");

    for(i = 0; i < n; i++)
    {
        printf("Train No: %d | Available Seats: %d\n",
               trainNo[i], seats[i]);
    }

    return 0;
}
