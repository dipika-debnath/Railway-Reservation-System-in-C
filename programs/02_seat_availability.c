#include <stdio.h>

int main()
{
    int totalSeats, bookedSeats, requiredSeats;
    int availableSeats;

    printf("===== SEAT AVAILABILITY CHECKER =====\n");

    printf("Enter total number of seats: ");
    scanf("%d", &totalSeats);

    printf("Enter number of booked seats: ");
    scanf("%d", &bookedSeats);

    if(totalSeats <= 0 || bookedSeats < 0 || bookedSeats > totalSeats)
    {
        printf("Invalid seat information.\n");
        return 0;
    }

    availableSeats = totalSeats - bookedSeats;

    printf("\nTotal Seats     : %d\n", totalSeats);
    printf("Booked Seats    : %d\n", bookedSeats);
    printf("Available Seats : %d\n", availableSeats);

    printf("\nEnter number of seats required: ");
    scanf("%d", &requiredSeats);

    if(requiredSeats <= 0)
    {
        printf("Invalid number of seats.\n");
    }
    else if(requiredSeats <= availableSeats)
    {
        availableSeats -= requiredSeats;

        printf("\nSeats are available!\n");
        printf("Booking confirmed for %d seat(s).\n", requiredSeats);
        printf("Remaining Seats: %d\n", availableSeats);
    }
    else
    {
        printf("\nSorry! Only %d seat(s) are available.\n",
               availableSeats);
    }

    return 0;
}
