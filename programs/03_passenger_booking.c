#include <stdio.h>

int main()
{
    int n, i;
    char name[10][30];
    int age[10];

    printf("===== PASSENGER BOOKING SYSTEM =====\n");

    printf("Enter number of passengers: ");
    scanf("%d", &n);

    if(n <= 0 || n > 10)
    {
        printf("Invalid number of passengers.\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nPassenger %d\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", name[i]);

        printf("Enter age: ");
        scanf("%d", &age[i]);

        if(age[i] <= 0)
        {
            printf("Invalid age.\n");
            return 0;
        }
    }

    printf("\n===== BOOKING SUMMARY =====\n");

    for(i = 0; i < n; i++)
    {
        printf("Passenger %d | Name: %s | Age: %d | Status: Confirmed\n",
               i + 1, name[i], age[i]);
    }

    printf("\n%d passenger(s) booked successfully.\n", n);

    return 0;
}
