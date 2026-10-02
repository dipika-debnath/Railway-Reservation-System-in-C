#include <stdio.h>

struct Journey
{
    char from[30];
    char to[30];
};

struct Passenger
{
    char name[30];
    int age;
};

struct Ticket
{
    int pnr;
    struct Passenger passenger;
    struct Journey journey;
    float fare;
};

int main()
{
    struct Ticket ticket;

    printf("===== RAILWAY TICKET SYSTEM =====\n");

    printf("Enter PNR number: ");
    scanf("%d", &ticket.pnr);

    printf("Enter passenger name: ");
    scanf(" %[^\n]", ticket.passenger.name);

    printf("Enter passenger age: ");
    scanf("%d", &ticket.passenger.age);

    printf("Enter starting station: ");
    scanf(" %[^\n]", ticket.journey.from);

    printf("Enter destination: ");
    scanf(" %[^\n]", ticket.journey.to);

    printf("Enter ticket fare: Rs.");
    scanf("%f", &ticket.fare);

    printf("\n========== TICKET DETAILS ==========\n");
    printf("PNR         : %d\n", ticket.pnr);
    printf("Passenger   : %s\n", ticket.passenger.name);
    printf("Age         : %d\n", ticket.passenger.age);
    printf("From        : %s\n", ticket.journey.from);
    printf("To          : %s\n", ticket.journey.to);
    printf("Fare        : Rs.%.2f\n", ticket.fare);

    return 0;
}
