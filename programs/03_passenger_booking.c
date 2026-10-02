#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of passengers: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Ticket booked for Passenger %d\n", i);
    }

    printf("\nAll passenger bookings processed successfully.\n");

    return 0;
}
