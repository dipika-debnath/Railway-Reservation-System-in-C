#include <stdio.h>

int main()
{
    int n, i;
    int trainNo[10];
    int seats[10];
    float fare[10];

    printf("===== TRAIN DETAILS SYSTEM =====\n");

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

        printf("Enter available seats: ");
        scanf("%d", &seats[i]);

        printf("Enter ticket fare: Rs.");
        scanf("%f", &fare[i]);
    }

    printf("\n========== TRAIN DETAILS ==========\n");

    for(i = 0; i < n; i++)
    {
        printf("\nTrain Number    : %d\n", trainNo[i]);
        printf("Available Seats : %d\n", seats[i]);
        printf("Ticket Fare     : Rs.%.2f\n", fare[i]);
    }

    return 0;
}
