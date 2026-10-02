#include <stdio.h>

int main()
{
    int distance, passengerType;
    float fare, totalFare;

    printf("===== RAILWAY FARE CALCULATOR =====\n");

    printf("Enter distance travelled (in km): ");
    scanf("%d", &distance);

    if(distance <= 0)
    {
        printf("Invalid distance.\n");
        return 0;
    }

    if(distance <= 100)
        fare = distance * 2.00;
    else if(distance <= 300)
        fare = distance * 1.75;
    else
        fare = distance * 1.50;

    printf("\nPassenger Type\n");
    printf("1. Adult\n");
    printf("2. Student\n");
    printf("3. Senior Citizen\n");
    printf("Enter choice: ");
    scanf("%d", &passengerType);

    if(passengerType == 2)
        totalFare = fare * 0.75;
    else if(passengerType == 3)
        totalFare = fare * 0.60;
    else if(passengerType == 1)
        totalFare = fare;
    else
    {
        printf("Invalid passenger type.\n");
        return 0;
    }

    printf("\n===== FARE DETAILS =====\n");
    printf("Distance    : %d km\n", distance);
    printf("Base Fare   : Rs.%.2f\n", fare);
    printf("Final Fare  : Rs.%.2f\n", totalFare);

    return 0;
}
