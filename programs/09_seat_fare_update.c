#include <stdio.h>

void updateFare(float fare)
{
    float newFare;

    printf("\nEnter new fare: Rs.");
    scanf("%f", &newFare);

    if(newFare > 0)
    {
        fare = newFare;
        printf("Updated Fare: Rs.%.2f\n", fare);
    }
    else
    {
        printf("Invalid fare.\n");
    }
}

void updateSeat(int *seat)
{
    int choice;

    printf("\n1. Book Seat\n");
    printf("2. Make Seat Available\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        *seat = 1;
        printf("Seat status updated: BOOKED\n");
    }
    else if(choice == 2)
    {
        *seat = 0;
        printf("Seat status updated: AVAILABLE\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

void displayStatus(float fare, int seat)
{
    printf("\n===== CURRENT STATUS =====\n");
    printf("Fare: Rs.%.2f\n", fare);

    if(seat == 1)
        printf("Seat Status: BOOKED\n");
    else
        printf("Seat Status: AVAILABLE\n");
}

int main()
{
    float fare = 300.00;
    int seat = 0;
    int choice;

    printf("===== RAILWAY UPDATE SYSTEM =====\n");

    displayStatus(fare, seat);

    printf("\n1. Update Fare\n");
    printf("2. Update Seat Status\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        updateFare(fare);
    else if(choice == 2)
        updateSeat(&seat);
    else if(choice != 3)
        printf("Invalid choice.\n");

    displayStatus(fare, seat);

    return 0;
}
