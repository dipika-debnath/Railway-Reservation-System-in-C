#include <stdio.h>

int main()
{
    int availableSeats, requiredSeats;

    printf("Enter available seats: ");
    scanf("%d", &availableSeats);

    printf("Enter number of seats required: ");
    scanf("%d", &requiredSeats);

    if(requiredSeats <= availableSeats)
        printf("Seats are available. Booking can be confirmed.\n");
    else
        printf("Sorry! Not enough seats available.\n");

    return 0;
}
