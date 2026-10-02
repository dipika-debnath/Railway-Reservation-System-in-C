#include <stdio.h>

void displaySeats(int seats)
{
    printf("\nAvailable Seats: %d\n", seats);
}

void bookTicket(int *seats, int *booked)
{
    if(*seats > 0)
    {
        (*seats)--;
        (*booked)++;

        printf("\nTicket booked successfully!");
        printf("\nPNR Number: %d\n", 1000 + *booked);
    }
    else
    {
        printf("\nSorry! No seats available.\n");
    }
}

void cancelTicket(int *seats, int *booked)
{
    if(*booked > 0)
    {
        (*seats)++;
        (*booked)--;

        printf("\nTicket cancelled successfully.\n");
    }
    else
    {
        printf("\nNo booked tickets to cancel.\n");
    }
}

int main()
{
    int seats = 5;
    int booked = 0;
    int choice;

    do
    {
        printf("\n===== RAILWAY RESERVATION SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Available Seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bookTicket(&seats, &booked);
                break;

            case 2:
                cancelTicket(&seats, &booked);
                break;

            case 3:
                displaySeats(seats);
                break;

            case 4:
                printf("\nThank you for using the Railway Reservation System.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while(choice != 4);

    return 0;
}
