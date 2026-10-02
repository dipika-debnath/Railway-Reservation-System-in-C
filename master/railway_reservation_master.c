#include <stdio.h>
#include <string.h>

#define MAX_TRAINS 4
#define MAX_COACHES 5
#define SEATS_PER_COACH 4
#define MAX_TICKETS 50
#define MAX_WAITLIST 20
#define MAX_NAME 30
#define MAX_STATION 30

/*
   RAILWAY RESERVATION MASTER SYSTEM

   This program combines the main concepts from the 10 railway programs:
   1. Fare calculation
   2. Seat availability
   3. Multiple passenger booking
   4. Train details
   5. 2D coach-seat matrix
   6. Train search by number/name
   7. Modular booking and cancellation
   8. Recursive PNR search + pointer usage
   9. Seat and fare update
   10. Structures + nested structures + ticket details
*/

struct Journey
{
    char from[MAX_STATION];
    char to[MAX_STATION];
};

struct Passenger
{
    char name[MAX_NAME];
    int age;
    int type;      /* 1 = Adult, 2 = Student, 3 = Senior Citizen */
};

struct Ticket
{
    int pnr;
    int trainNumber;
    int coachNumber;
    int seatNumber;
    float fare;
    struct Passenger passenger;
    struct Journey journey;
};

struct Train
{
    int trainNumber;
    char trainName[40];
    char source[MAX_STATION];
    char destination[MAX_STATION];
    float distance;
    int coaches;
    int seats[MAX_COACHES][SEATS_PER_COACH];
};

struct WaitlistEntry
{
    int waitlistID;
    int trainNumber;
    char name[MAX_NAME];
    int age;
    int type;
    struct Journey journey;
};

void initializeTrains(struct Train trains[], int *trainCount);
void displayMenu(void);
void displayTrainDetails(struct Train *train);
void displayAllTrains(struct Train trains[], int trainCount);
int searchTrainByNumber(struct Train trains[], int trainCount, int trainNumber);
int searchTrainByName(struct Train trains[], int trainCount, const char name[]);
void searchTrain(struct Train trains[], int trainCount);

float calculateBaseFare(float distance);
float calculatePassengerFare(float baseFare, int type);
void displayFareDetails(float baseFare, int type, float finalFare);

int countAvailableSeats(struct Train *train);
void displaySeatMatrix(struct Train *train);
int findNextAvailableSeat(struct Train *train, int *coach, int *seat);
int isSeatAvailable(struct Train *train, int coach, int seat);

int recursivePNRSearch(struct Ticket tickets[],
                       int count,
                       int index,
                       int targetPNR);

void displayTicket(struct Ticket *ticket);
void displayAllTickets(struct Ticket tickets[], int ticketCount);

void bookTickets(struct Train trains[], int trainCount,
                 struct Ticket tickets[], int *ticketCount,
                 struct WaitlistEntry waitlist[], int *waitCount,
                 int *nextPNR,
                 int *nextWaitlistID);

int bookOnePassenger(struct Train *train,
                     struct Ticket tickets[],
                     int *ticketCount,
                     int *nextPNR,
                     struct Passenger passenger,
                     int manualSeat,
                     int requestedCoach,
                     int requestedSeat);

void cancelTicket(struct Train trains[], int trainCount,
                  struct Ticket tickets[], int *ticketCount,
                  struct WaitlistEntry waitlist[], int *waitCount,
                  int *nextPNR);

void searchPNR(struct Ticket tickets[], int ticketCount);

void updateTicket(struct Train trains[], int trainCount,
                  struct Ticket tickets[], int ticketCount);

void displaySeatAvailability(struct Train trains[], int trainCount);

void addToWaitlist(struct Train *train,
                   struct WaitlistEntry waitlist[],
                   int *waitCount,
                   int *nextWaitlistID);

void displayWaitlist(struct WaitlistEntry waitlist[],
                     int waitCount,
                     struct Train trains[],
                     int trainCount);

void promoteWaitlistedPassenger(struct Train trains[],
                                int trainCount,
                                struct Ticket tickets[],
                                int *ticketCount,
                                struct WaitlistEntry waitlist[],
                                int *waitCount,
                                int trainNumber,
                                int freedCoach,
                                int freedSeat,
                                int *nextPNR);

void removeWaitlistEntry(struct WaitlistEntry waitlist[],
                         int *waitCount,
                         int index);

void systemSummary(struct Train trains[],
                   int trainCount,
                   struct Ticket tickets[],
                   int ticketCount,
                   struct WaitlistEntry waitlist[],
                   int waitCount);

int main(void)
{
    struct Train trains[MAX_TRAINS];
    struct Ticket tickets[MAX_TICKETS];
    struct WaitlistEntry waitlist[MAX_WAITLIST];

    int trainCount = 0;
    int ticketCount = 0;
    int waitCount = 0;

    int nextPNR = 1001;
    int nextWaitlistID = 1;

    int choice;

    initializeTrains(trains, &trainCount);

    printf("\n==========================================================\n");
    printf("           RAILWAY RESERVATION MASTER SYSTEM\n");
    printf("==========================================================\n");

    printf("System initialized with %d trains.\n", trainCount);

    do
    {
        displayMenu();

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayAllTrains(trains, trainCount);
                break;

            case 2:
                searchTrain(trains, trainCount);
                break;

            case 3:
                bookTickets(trains,
                             trainCount,
                             tickets,
                             &ticketCount,
                             waitlist,
                             &waitCount,
                             &nextPNR,
                             &nextWaitlistID);
                break;

            case 4:
                displaySeatAvailability(trains, trainCount);
                break;

            case 5:
                cancelTicket(trains,
                             trainCount,
                             tickets,
                             &ticketCount,
                             waitlist,
                             &waitCount,
                             &nextPNR);
                break;

            case 6:
                searchPNR(tickets, ticketCount);
                break;

            case 7:
                displayAllTickets(tickets, ticketCount);
                break;

            case 8:
                updateTicket(trains,
                             trainCount,
                             tickets,
                             ticketCount);
                break;

            case 9:
            {
                int trainNumber;
                int trainIndex;
                float distance;
                float baseFare;

                printf("\nEnter train number: ");
                scanf("%d", &trainNumber);

                trainIndex =
                    searchTrainByNumber(trains,
                                        trainCount,
                                        trainNumber);

                if(trainIndex == -1)
                {
                    printf("Train not found.\n");
                    break;
                }

                printf("Current distance: %.0f km\n",
                       trains[trainIndex].distance);

                printf("Enter distance for fare calculation: ");
                scanf("%f", &distance);

                if(distance <= 0)
                {
                    printf("Invalid distance.\n");
                    break;
                }

                baseFare = calculateBaseFare(distance);

                printf("\nFare rate selected according to distance.\n");
                printf("Calculated Base Fare: Rs.%.2f\n",
                       baseFare);

                break;
            }

            case 10:
                displayWaitlist(waitlist,
                                waitCount,
                                trains,
                                trainCount);
                break;

            case 11:
            {
                int trainNumber;
                int trainIndex;

                printf("\nEnter train number: ");
                scanf("%d", &trainNumber);

                trainIndex =
                    searchTrainByNumber(trains,
                                        trainCount,
                                        trainNumber);

                if(trainIndex == -1)
                    printf("Train not found.\n");
                else
                    displaySeatMatrix(&trains[trainIndex]);

                break;
            }

            case 12:
                systemSummary(trains,
                              trainCount,
                              tickets,
                              ticketCount,
                              waitlist,
                              waitCount);
                break;

            case 13:
                printf("\nThank you for using the Railway Reservation Master System.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 13);

    return 0;
}

void displayMenu(void)
{
    printf("\n==========================================================\n");
    printf("                       MAIN MENU\n");
    printf("==========================================================\n");

    printf("1.  Display Train Details\n");
    printf("2.  Search Train\n");
    printf("3.  Book Passenger(s)\n");
    printf("4.  Check Seat Availability\n");
    printf("5.  Cancel Booking\n");
    printf("6.  Search Passenger by PNR\n");
    printf("7.  Display All E-Tickets\n");
    printf("8.  Update Ticket Seat / Fare\n");
    printf("9.  Calculate Fare by Distance\n");
    printf("10. Display Waitlist\n");
    printf("11. Display Coach Seat Matrix\n");
    printf("12. Display System Summary\n");
    printf("13. Exit\n");
}

void initializeTrains(struct Train trains[], int *trainCount)
{
    int i;
    int j;
    int k;

    *trainCount = 4;

    trains[0].trainNumber = 101;

    strcpy(trains[0].trainName,
           "Bangalore Express");

    strcpy(trains[0].source,
           "Bangalore");

    strcpy(trains[0].destination,
           "Mysore");

    trains[0].distance = 140.0f;
    trains[0].coaches = 3;


    trains[1].trainNumber = 202;

    strcpy(trains[1].trainName,
           "Chennai Superfast");

    strcpy(trains[1].source,
           "Bangalore");

    strcpy(trains[1].destination,
           "Chennai");

    trains[1].distance = 350.0f;
    trains[1].coaches = 4;


    trains[2].trainNumber = 303;

    strcpy(trains[2].trainName,
           "Mumbai Express");

    strcpy(trains[2].source,
           "Bangalore");

    strcpy(trains[2].destination,
           "Mumbai");

    trains[2].distance = 980.0f;
    trains[2].coaches = 5;


    trains[3].trainNumber = 404;

    strcpy(trains[3].trainName,
           "Hyderabad Intercity");

    strcpy(trains[3].source,
           "Bangalore");

    strcpy(trains[3].destination,
           "Hyderabad");

    trains[3].distance = 570.0f;
    trains[3].coaches = 3;


    /* Initialize complete 2D seat matrix */

    for(i = 0; i < *trainCount; i++)
    {
        for(j = 0; j < MAX_COACHES; j++)
        {
            for(k = 0; k < SEATS_PER_COACH; k++)
            {
                trains[i].seats[j][k] = 0;
            }
        }
    }


    /*
       Initial booked seats.
       0 = available
       1 = booked
    */

    trains[0].seats[0][1] = 1;
    trains[0].seats[1][0] = 1;

    trains[1].seats[0][0] = 1;
    trains[1].seats[0][1] = 1;
    trains[1].seats[2][2] = 1;

    trains[2].seats[0][0] = 1;
    trains[2].seats[1][1] = 1;
    trains[2].seats[3][3] = 1;

    trains[3].seats[0][2] = 1;
    trains[3].seats[2][1] = 1;
}

void displayTrainDetails(struct Train *train)
{
    printf("\n----------------------------------------------------------\n");

    printf("Train Number    : %d\n",
           train->trainNumber);

    printf("Train Name      : %s\n",
           train->trainName);

    printf("From            : %s\n",
           train->source);

    printf("To              : %s\n",
           train->destination);

    printf("Distance        : %.0f km\n",
           train->distance);

    printf("Coaches         : %d\n",
           train->coaches);

    printf("Total Seats     : %d\n",
           train->coaches * SEATS_PER_COACH);

    printf("Available Seats : %d\n",
           countAvailableSeats(train));

    printf("Base Fare       : Rs.%.2f\n",
           calculateBaseFare(train->distance));

    printf("----------------------------------------------------------\n");
}

void displayAllTrains(struct Train trains[], int trainCount)
{
    int i;

    printf("\n==================== TRAIN DETAILS ====================\n");

    for(i = 0; i < trainCount; i++)
    {
        displayTrainDetails(&trains[i]);
    }
}

int searchTrainByNumber(struct Train trains[],
                        int trainCount,
                        int trainNumber)
{
    int i;

    for(i = 0; i < trainCount; i++)
    {
        if(trains[i].trainNumber == trainNumber)
        {
            return i;
        }
    }

    return -1;
}

int searchTrainByName(struct Train trains[],
                       int trainCount,
                       const char name[])
{
    int i;

    for(i = 0; i < trainCount; i++)
    {
        if(strcmp(trains[i].trainName, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

void searchTrain(struct Train trains[], int trainCount)
{
    int choice;
    int trainIndex = -1;

    printf("\n================ TRAIN SEARCH ================\n");

    printf("1. Search by Train Number\n");
    printf("2. Search by Train Name\n");

    printf("Enter choice: ");
    scanf("%d", &choice);


    if(choice == 1)
    {
        int trainNumber;

        printf("Enter train number: ");
        scanf("%d", &trainNumber);

        trainIndex =
            searchTrainByNumber(trains,
                                trainCount,
                                trainNumber);
    }
    else if(choice == 2)
    {
        char name[40];

        printf("Enter exact train name: ");
        scanf(" %[^\n]", name);

        trainIndex =
            searchTrainByName(trains,
                              trainCount,
                              name);
    }
    else
    {
        printf("Invalid search choice.\n");
        return;
    }


    if(trainIndex == -1)
    {
        printf("Train not found.\n");
    }
    else
    {
        displayTrainDetails(&trains[trainIndex]);
    }
}

float calculateBaseFare(float distance)
{
    float fare;

    /*
       Same basic fare idea as the original fare calculator:

       Up to 100 km     -> Rs.2.00 per km
       101-300 km       -> Rs.1.75 per km
       Above 300 km     -> Rs.1.50 per km
    */

    if(distance <= 100)
    {
        fare = distance * 2.00f;
    }
    else if(distance <= 300)
    {
        fare = distance * 1.75f;
    }
    else
    {
        fare = distance * 1.50f;
    }

    return fare;
}

float calculatePassengerFare(float baseFare, int type)
{
    /*
       Passenger type:
       1 = Adult
       2 = Student
       3 = Senior Citizen
    */

    if(type == 2)
    {
        return baseFare * 0.75f;
    }
    else if(type == 3)
    {
        return baseFare * 0.60f;
    }
    else
    {
        return baseFare;
    }
}

void displayFareDetails(float baseFare,
                        int type,
                        float finalFare)
{
    printf("\n================ FARE DETAILS ================\n");

    printf("Base Fare  : Rs.%.2f\n",
           baseFare);

    if(type == 2)
    {
        printf("Passenger  : Student (25%% discount)\n");
    }
    else if(type == 3)
    {
        printf("Passenger  : Senior Citizen (40%% discount)\n");
    }
    else
    {
        printf("Passenger  : Adult\n");
    }

    printf("Final Fare : Rs.%.2f\n",
           finalFare);
}

int countAvailableSeats(struct Train *train)
{
    int i;
    int j;
    int available = 0;

    for(i = 0; i < train->coaches; i++)
    {
        for(j = 0; j < SEATS_PER_COACH; j++)
        {
            if(train->seats[i][j] == 0)
            {
                available++;
            }
        }
    }

    return available;
}

void displaySeatMatrix(struct Train *train)
{
    int i;
    int j;

    printf("\n================ SEAT MATRIX ================\n");

    printf("Train %d - %s\n",
           train->trainNumber,
           train->trainName);

    printf("0 = Available | 1 = Booked\n\n");

    for(i = 0; i < train->coaches; i++)
    {
        printf("Coach %d : ",
               i + 1);

        for(j = 0; j < SEATS_PER_COACH; j++)
        {
            printf("%d ",
                   train->seats[i][j]);
        }

        printf("\n");
    }

    printf("Available Seats: %d\n",
           countAvailableSeats(train));
}

int findNextAvailableSeat(struct Train *train,
                          int *coach,
                          int *seat)
{
    int i;
    int j;

    for(i = 0; i < train->coaches; i++)
    {
        for(j = 0; j < SEATS_PER_COACH; j++)
        {
            if(train->seats[i][j] == 0)
            {
                *coach = i;
                *seat = j;

                return 1;
            }
        }
    }

    return 0;
}

int isSeatAvailable(struct Train *train,
                    int coach,
                    int seat)
{
    if(coach < 0 || coach >= train->coaches)
    {
        return 0;
    }

    if(seat < 0 || seat >= SEATS_PER_COACH)
    {
        return 0;
    }

    return train->seats[coach][seat] == 0;
}

int recursivePNRSearch(struct Ticket tickets[],
                       int count,
                       int index,
                       int targetPNR)
{
    if(index == count)
    {
        return -1;
    }

    if(tickets[index].pnr == targetPNR)
    {
        return index;
    }

    return recursivePNRSearch(tickets,
                               count,
                               index + 1,
                               targetPNR);
}

void displayTicket(struct Ticket *ticket)
{
    printf("\n==========================================================\n");
    printf("                     RAILWAY E-TICKET\n");
    printf("==========================================================\n");

    printf("PNR             : %d\n",
           ticket->pnr);

    printf("Train Number    : %d\n",
           ticket->trainNumber);

    printf("Passenger Name  : %s\n",
           ticket->passenger.name);

    printf("Passenger Age   : %d\n",
           ticket->passenger.age);

    printf("From            : %s\n",
           ticket->journey.from);

    printf("To              : %s\n",
           ticket->journey.to);

    printf("Coach Number    : %d\n",
           ticket->coachNumber + 1);

    printf("Seat Number     : %d\n",
           ticket->seatNumber + 1);

    printf("Fare            : Rs.%.2f\n",
           ticket->fare);

    printf("==========================================================\n");
}

void displayAllTickets(struct Ticket tickets[],
                       int ticketCount)
{
    int i;

    if(ticketCount == 0)
    {
        printf("\nNo active bookings.\n");
        return;
    }

    printf("\n================ ACTIVE E-TICKETS ================\n");

    for(i = 0; i < ticketCount; i++)
    {
        displayTicket(&tickets[i]);
    }
}

void bookTickets(struct Train trains[],
                 int trainCount,
                 struct Ticket tickets[],
                 int *ticketCount,
                 struct WaitlistEntry waitlist[],
                 int *waitCount,
                 int *nextPNR,
                 int *nextWaitlistID)
{
    int trainNumber;
    int trainIndex;

    int passengerCount;
    int i;

    int manualSeat;

    int coach = -1;
    int seat = -1;

    struct Passenger passenger;


    if(*ticketCount >= MAX_TICKETS)
    {
        printf("\nTicket storage is full.\n");
        return;
    }


    printf("\n================ NEW BOOKING ================\n");

    printf("Enter train number: ");
    scanf("%d", &trainNumber);

    trainIndex =
        searchTrainByNumber(trains,
                            trainCount,
                            trainNumber);

    if(trainIndex == -1)
    {
        printf("Train not found.\n");
        return;
    }


    printf("Available seats on %s: %d\n",
           trains[trainIndex].trainName,
           countAvailableSeats(&trains[trainIndex]));


    printf("Enter number of passengers (1-5): ");
    scanf("%d", &passengerCount);


    if(passengerCount < 1 ||
       passengerCount > 5)
    {
        printf("Invalid number of passengers.\n");
        return;
    }


    if(passengerCount >
       countAvailableSeats(&trains[trainIndex]))
    {
        printf("\nNot enough seats for all passengers.\n");

        passengerCount =
            countAvailableSeats(&trains[trainIndex]);

        if(passengerCount == 0)
        {
            printf("Train is full.\n");

            addToWaitlist(&trains[trainIndex],
                          waitlist,
                          waitCount,
                          nextWaitlistID);

            return;
        }

        printf("Only %d passenger(s) can be booked now.\n",
               passengerCount);
    }


    printf("\nSeat assignment mode:\n");

    printf("1. Choose each seat manually\n");
    printf("2. Assign first available seats automatically\n");

    printf("Enter choice: ");
    scanf("%d", &manualSeat);


    if(manualSeat != 1 &&
       manualSeat != 2)
    {
        printf("Invalid seat assignment choice.\n");
        return;
    }


    for(i = 0; i < passengerCount; i++)
    {
        printf("\n========== Passenger %d ==========\n",
               i + 1);


        printf("Enter passenger name: ");
        scanf(" %[^\n]", passenger.name);


        printf("Enter age: ");
        scanf("%d", &passenger.age);


        if(passenger.age <= 0)
        {
            printf("Invalid age. Passenger skipped.\n");
            continue;
        }


        printf("\nPassenger Type:\n");
        printf("1. Adult\n");
        printf("2. Student\n");
        printf("3. Senior Citizen\n");

        printf("Enter type: ");
        scanf("%d", &passenger.type);


        if(passenger.type < 1 ||
           passenger.type > 3)
        {
            printf("Invalid passenger type. Passenger skipped.\n");
            continue;
        }


        coach = -1;
        seat = -1;


        if(manualSeat == 1)
        {
            displaySeatMatrix(&trains[trainIndex]);

            printf("Enter coach number: ");
            scanf("%d", &coach);

            printf("Enter seat number: ");
            scanf("%d", &seat);

            coach--;
            seat--;


            if(!isSeatAvailable(&trains[trainIndex],
                                coach,
                                seat))
            {
                printf("Selected seat is invalid or already booked.\n");
                printf("Passenger skipped.\n");
                continue;
            }
        }
        else
        {
            if(!findNextAvailableSeat(&trains[trainIndex],
                                      &coach,
                                      &seat))
            {
                printf("No more seats available.\n");
                break;
            }
        }


        if(bookOnePassenger(&trains[trainIndex],
                            tickets,
                            ticketCount,
                            nextPNR,
                            passenger,
                            manualSeat,
                            coach,
                            seat))
        {
            printf("Passenger %d booked successfully.\n",
                   i + 1);
        }
    }
}

int bookOnePassenger(struct Train *train,
                     struct Ticket tickets[],
                     int *ticketCount,
                     int *nextPNR,
                     struct Passenger passenger,
                     int manualSeat,
                     int requestedCoach,
                     int requestedSeat)
{
    struct Ticket *ticket;

    float baseFare;
    float finalFare;

    int coach;
    int seat;


    if(*ticketCount >= MAX_TICKETS)
    {
        return 0;
    }


    if(manualSeat == 1)
    {
        coach = requestedCoach;
        seat = requestedSeat;
    }
    else
    {
        if(!findNextAvailableSeat(train,
                                  &coach,
                                  &seat))
        {
            return 0;
        }
    }


    if(!isSeatAvailable(train,
                        coach,
                        seat))
    {
        return 0;
    }


    ticket = &tickets[*ticketCount];


    ticket->pnr = *nextPNR;

    ticket->trainNumber =
        train->trainNumber;

    ticket->coachNumber =
        coach;

    ticket->seatNumber =
        seat;

    ticket->passenger =
        passenger;


    strcpy(ticket->journey.from,
           train->source);

    strcpy(ticket->journey.to,
           train->destination);


    baseFare =
        calculateBaseFare(train->distance);

    finalFare =
        calculatePassengerFare(baseFare,
                               passenger.type);

    ticket->fare =
        finalFare;


    train->seats[coach][seat] =
        1;


    (*ticketCount)++;
    (*nextPNR)++;


    displayFareDetails(baseFare,
                       passenger.type,
                       finalFare);

    displayTicket(ticket);


    return 1;
}

void cancelTicket(struct Train trains[],
                  int trainCount,
                  struct Ticket tickets[],
                  int *ticketCount,
                  struct WaitlistEntry waitlist[],
                  int *waitCount,
                  int *nextPNR)
{
    int targetPNR;

    int ticketIndex;
    int trainIndex;

    int trainNumber;

    int freedCoach;
    int freedSeat;

    int i;


    if(*ticketCount == 0)
    {
        printf("\nNo active tickets to cancel.\n");
        return;
    }


    printf("\nEnter PNR to cancel: ");
    scanf("%d", &targetPNR);


    ticketIndex =
        recursivePNRSearch(tickets,
                           *ticketCount,
                           0,
                           targetPNR);


    if(ticketIndex == -1)
    {
        printf("PNR not found.\n");
        return;
    }


    trainNumber =
        tickets[ticketIndex].trainNumber;

    freedCoach =
        tickets[ticketIndex].coachNumber;

    freedSeat =
        tickets[ticketIndex].seatNumber;


    trainIndex =
        searchTrainByNumber(trains,
                            trainCount,
                            trainNumber);


    if(trainIndex == -1)
    {
        printf("Associated train not found.\n");
        return;
    }


    trains[trainIndex].seats
        [freedCoach][freedSeat] = 0;


    printf("\nBooking cancelled successfully.\n");

    printf("PNR %d has been removed.\n",
           targetPNR);

    printf("Seat released: Coach %d, Seat %d\n",
           freedCoach + 1,
           freedSeat + 1);


    for(i = ticketIndex;
        i < *ticketCount - 1;
        i++)
    {
        tickets[i] =
            tickets[i + 1];
    }


    (*ticketCount)--;


    /*
       If someone is waiting for the same train,
       give the freed seat to that passenger.
    */

    promoteWaitlistedPassenger(
        trains,
        trainCount,
        tickets,
        ticketCount,
        waitlist,
        waitCount,
        trainNumber,
        freedCoach,
        freedSeat,
        nextPNR
    );
}

void searchPNR(struct Ticket tickets[],
               int ticketCount)
{
    int targetPNR;
    int ticketIndex;


    if(ticketCount == 0)
    {
        printf("\nNo active tickets.\n");
        return;
    }


    printf("\nEnter PNR to search: ");
    scanf("%d", &targetPNR);


    ticketIndex =
        recursivePNRSearch(tickets,
                           ticketCount,
                           0,
                           targetPNR);


    if(ticketIndex == -1)
    {
        printf("PNR %d not found.\n",
               targetPNR);
    }
    else
    {
        displayTicket(&tickets[ticketIndex]);
    }
}

void updateTicket(struct Train trains[],
                  int trainCount,
                  struct Ticket tickets[],
                  int ticketCount)
{
    int targetPNR;
    int ticketIndex;
    int trainIndex;

    int choice;

    float newFare;

    int newCoach;
    int newSeat;

    int oldCoach;
    int oldSeat;


    if(ticketCount == 0)
    {
        printf("\nNo active tickets to update.\n");
        return;
    }


    printf("\nEnter PNR to update: ");
    scanf("%d", &targetPNR);


    ticketIndex =
        recursivePNRSearch(tickets,
                           ticketCount,
                           0,
                           targetPNR);


    if(ticketIndex == -1)
    {
        printf("PNR not found.\n");
        return;
    }


    trainIndex =
        searchTrainByNumber(
            trains,
            trainCount,
            tickets[ticketIndex].trainNumber
        );


    if(trainIndex == -1)
    {
        printf("Train not found.\n");
        return;
    }


    printf("\n1. Update Seat\n");
    printf("2. Update Fare\n");
    printf("3. Update Both\n");

    printf("Enter choice: ");
    scanf("%d", &choice);


    if(choice == 1 ||
       choice == 3)
    {
        displaySeatMatrix(
            &trains[trainIndex]
        );


        printf("Enter new coach number: ");
        scanf("%d", &newCoach);


        printf("Enter new seat number: ");
        scanf("%d", &newSeat);


        newCoach--;
        newSeat--;


        oldCoach =
            tickets[ticketIndex].coachNumber;

        oldSeat =
            tickets[ticketIndex].seatNumber;


        /*
           Same seat is allowed.
        */

        if(newCoach == oldCoach &&
           newSeat == oldSeat)
        {
            printf("Passenger is already in that seat.\n");
        }
        else if(!isSeatAvailable(
                    &trains[trainIndex],
                    newCoach,
                    newSeat))
        {
            printf("New seat is invalid or already booked.\n");
            return;
        }
        else
        {
            trains[trainIndex]
                .seats[oldCoach][oldSeat] = 0;

            trains[trainIndex]
                .seats[newCoach][newSeat] = 1;


            tickets[ticketIndex]
                .coachNumber = newCoach;

            tickets[ticketIndex]
                .seatNumber = newSeat;


            printf("Seat updated successfully.\n");
        }
    }


    if(choice == 2 ||
       choice == 3)
    {
        printf("Current fare: Rs.%.2f\n",
               tickets[ticketIndex].fare);

        printf("Enter new fare: Rs.");
        scanf("%f", &newFare);


        if(newFare <= 0)
        {
            printf("Invalid fare.\n");
            return;
        }


        tickets[ticketIndex].fare =
            newFare;


        printf("Fare updated successfully.\n");
    }


    if(choice < 1 ||
       choice > 3)
    {
        printf("Invalid update choice.\n");
        return;
    }


    printf("\nUpdated Ticket:\n");

    displayTicket(
        &tickets[ticketIndex]
    );
}

void addToWaitlist(struct Train *train,
                   struct WaitlistEntry waitlist[],
                   int *waitCount,
                   int *nextWaitlistID)
{
    struct WaitlistEntry *entry;


    if(*waitCount >= MAX_WAITLIST)
    {
        printf("Waitlist is full.\n");
        return;
    }


    entry =
        &waitlist[*waitCount];


    entry->waitlistID =
        *nextWaitlistID;

    entry->trainNumber =
        train->trainNumber;


    printf("Enter passenger name for waitlist: ");
    scanf(" %[^\n]", entry->name);


    printf("Enter age: ");
    scanf("%d", &entry->age);


    printf("\nPassenger Type:\n");

    printf("1. Adult\n");
    printf("2. Student\n");
    printf("3. Senior Citizen\n");

    printf("Enter type: ");
    scanf("%d", &entry->type);


    if(entry->age <= 0 ||
       entry->type < 1 ||
       entry->type > 3)
    {
        printf("Invalid passenger information.\n");
        return;
    }


    strcpy(entry->journey.from,
           train->source);

    strcpy(entry->journey.to,
           train->destination);


    (*waitCount)++;
    (*nextWaitlistID)++;


    printf("Added to waitlist successfully.\n");

    printf("Waitlist ID: %d\n",
           entry->waitlistID);
}

void displayWaitlist(struct WaitlistEntry waitlist[],
                     int waitCount,
                     struct Train trains[],
                     int trainCount)
{
    int i;
    int trainIndex;


    if(waitCount == 0)
    {
        printf("\nWaitlist is empty.\n");
        return;
    }


    printf("\n================ WAITLIST ================\n");


    for(i = 0; i < waitCount; i++)
    {
        trainIndex =
            searchTrainByNumber(
                trains,
                trainCount,
                waitlist[i].trainNumber
            );


        printf("\nWaitlist ID : %d\n",
               waitlist[i].waitlistID);

        printf("Name        : %s\n",
               waitlist[i].name);

        printf("Age         : %d\n",
               waitlist[i].age);

        printf("Train       : %d\n",
               waitlist[i].trainNumber);

        printf("From        : %s\n",
               waitlist[i].journey.from);

        printf("To          : %s\n",
               waitlist[i].journey.to);


        if(trainIndex != -1)
        {
            printf("Available Seats: %d\n",
                   countAvailableSeats(
                       &trains[trainIndex]
                   ));
        }
    }
}

void promoteWaitlistedPassenger(
    struct Train trains[],
    int trainCount,
    struct Ticket tickets[],
    int *ticketCount,
    struct WaitlistEntry waitlist[],
    int *waitCount,
    int trainNumber,
    int freedCoach,
    int freedSeat,
    int *nextPNR)
{
    int i;
    int trainIndex;

    float baseFare;

    struct Ticket *ticket;


    if(*waitCount == 0 ||
       *ticketCount >= MAX_TICKETS)
    {
        return;
    }


    trainIndex =
        searchTrainByNumber(
            trains,
            trainCount,
            trainNumber
        );


    if(trainIndex == -1)
    {
        return;
    }


    for(i = 0;
        i < *waitCount;
        i++)
    {
        if(waitlist[i].trainNumber ==
           trainNumber)
        {
            ticket =
                &tickets[*ticketCount];


            ticket->pnr =
                *nextPNR;

            (*nextPNR)++;


            ticket->trainNumber =
                trainNumber;

            ticket->coachNumber =
                freedCoach;

            ticket->seatNumber =
                freedSeat;


            ticket->passenger.age =
                waitlist[i].age;

            ticket->passenger.type =
                waitlist[i].type;


            strcpy(ticket->passenger.name,
                   waitlist[i].name);

            strcpy(ticket->journey.from,
                   waitlist[i].journey.from);

            strcpy(ticket->journey.to,
                   waitlist[i].journey.to);


            baseFare =
                calculateBaseFare(
                    trains[trainIndex].distance
                );


            ticket->fare =
                calculatePassengerFare(
                    baseFare,
                    ticket->passenger.type
                );


            trains[trainIndex]
                .seats[freedCoach][freedSeat] = 1;


            (*ticketCount)++;


            printf("\n============== WAITLIST PROMOTION ==============\n");

            printf("A waitlisted passenger has been promoted.\n");

            displayTicket(ticket);


            removeWaitlistEntry(
                waitlist,
                waitCount,
                i
            );

            return;
        }
    }
}

void removeWaitlistEntry(
    struct WaitlistEntry waitlist[],
    int *waitCount,
    int index)
{
    int i;


    for(i = index;
        i < *waitCount - 1;
        i++)
    {
        waitlist[i] =
            waitlist[i + 1];
    }


    (*waitCount)--;
}

void displaySeatAvailability(
    struct Train trains[],
    int trainCount)
{
    int i;
    int available;


    printf("\n================ SEAT AVAILABILITY ================\n");


    for(i = 0;
        i < trainCount;
        i++)
    {
        available =
            countAvailableSeats(
                &trains[i]
            );


        printf(
            "Train %d - %-22s : %2d available / %2d total\n",
            trains[i].trainNumber,
            trains[i].trainName,
            available,
            trains[i].coaches * SEATS_PER_COACH
        );
    }
}

void systemSummary(
    struct Train trains[],
    int trainCount,
    struct Ticket tickets[],
    int ticketCount,
    struct WaitlistEntry waitlist[],
    int waitCount)
{
    int i;
    int totalAvailable = 0;


    /*
       These parameters are used as part of
       the complete system interface.
    */

    (void)tickets;
    (void)waitlist;


    for(i = 0;
        i < trainCount;
        i++)
    {
        totalAvailable +=
            countAvailableSeats(
                &trains[i]
            );
    }


    printf("\n================ SYSTEM SUMMARY ================\n");

    printf("Number of Trains          : %d\n",
           trainCount);

    printf("Active Tickets            : %d\n",
           ticketCount);

    printf("Waitlisted Passengers     : %d\n",
           waitCount);

    printf("Total Available Seats     : %d\n",
           totalAvailable);

    printf("Maximum Ticket Capacity   : %d\n",
           MAX_TICKETS);

    printf("Maximum Waitlist Capacity : %d\n",
           MAX_WAITLIST);
}
