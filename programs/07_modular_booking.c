#include <stdio.h>

void bookTicket(int *seats)
{
    if(*seats > 0)
    {
        (*seats)--;
        printf("Ticket booked successfully.\n");
    }
    else
    {
        printf("No seats available.\n");
    }
}

void cancelTicket(int *seats)
{
    (*seats)++;
    printf("Ticket cancelled successfully.\n");
}

void displaySeats(int seats)
{
    printf("Available seats: %d\n", seats);
}

int main()
{
    int seats = 5;
    int choice;

    do
    {
        printf("\n===== RAILWAY RESERVATION =====\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Available Seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bookTicket(&seats);
                break;

            case 2:
                cancelTicket(&seats);
                break;

            case 3:
                displaySeats(seats);
                break;

            case 4:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}
