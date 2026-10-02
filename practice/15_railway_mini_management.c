#include <stdio.h>
#include <string.h>

struct Passenger
{
    int pnr;
    char name[30];
    int age;
    int seatNo;
    float fare;
};

void displayPassenger(struct Passenger p)
{
    printf("\nPNR      : %d\n", p.pnr);
    printf("Name     : %s\n", p.name);
    printf("Age      : %d\n", p.age);
    printf("Seat No. : %d\n", p.seatNo);
    printf("Fare     : Rs.%.2f\n", p.fare);
}

void bookPassenger(struct Passenger p[], int *count, int *nextPNR)
{
    if(*count >= 10)
    {
        printf("No more bookings can be made.\n");
        return;
    }

    p[*count].pnr = *nextPNR;

    printf("Enter passenger name: ");
    scanf(" %[^\n]", p[*count].name);

    printf("Enter age: ");
    scanf("%d", &p[*count].age);

    if(p[*count].age <= 0)
    {
        printf("Invalid age.\n");
        return;
    }

    p[*count].seatNo = *count + 1;

    printf("Enter fare: Rs.");
    scanf("%f", &p[*count].fare);

    if(p[*count].fare <= 0)
    {
        printf("Invalid fare.\n");
        return;
    }

    (*count)++;
    (*nextPNR)++;

    printf("\nBooking successful!\n");
    printf("PNR Number : %d\n", p[*count - 1].pnr);
    printf("Seat Number: %d\n", p[*count - 1].seatNo);
}

void searchPassenger(struct Passenger p[], int count)
{
    int target, i, found = 0;

    printf("Enter PNR to search: ");
    scanf("%d", &target);

    for(i = 0; i < count; i++)
    {
        if(p[i].pnr == target)
        {
            printf("\n===== PASSENGER FOUND =====\n");
            displayPassenger(p[i]);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("PNR not found.\n");
}

void cancelPassenger(struct Passenger p[], int *count)
{
    int target, i, found = 0;

    printf("Enter PNR to cancel: ");
    scanf("%d", &target);

    for(i = 0; i < *count; i++)
    {
        if(p[i].pnr == target)
        {
            found = 1;

            for(int j = i; j < *count - 1; j++)
                p[j] = p[j + 1];

            (*count)--;

            printf("Booking cancelled successfully.\n");
            break;
        }
    }

    if(found == 0)
        printf("PNR not found.\n");
}

void displayAll(struct Passenger p[], int count)
{
    int i;

    if(count == 0)
    {
        printf("No active bookings.\n");
        return;
    }

    printf("\n===== ALL BOOKINGS =====\n");

    for(i = 0; i < count; i++)
    {
        printf("\n--- Passenger %d ---", i + 1);
        displayPassenger(p[i]);
    }
}

int main()
{
    struct Passenger passengers[10];
    int count = 0;
    int nextPNR = 1001;
    int choice;

    do
    {
        printf("\n===== RAILWAY MINI MANAGEMENT =====\n");
        printf("1. Book Passenger\n");
        printf("2. Search Passenger\n");
        printf("3. Cancel Booking\n");
        printf("4. Display All Bookings\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bookPassenger(passengers, &count, &nextPNR);
                break;

            case 2:
                searchPassenger(passengers, count);
                break;

            case 3:
                cancelPassenger(passengers, &count);
                break;

            case 4:
                displayAll(passengers, count);
                break;

            case 5:
                printf("\nThank you for using the Railway System.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);

    return 0;
}
