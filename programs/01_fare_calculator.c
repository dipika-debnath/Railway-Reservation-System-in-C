#include <stdio.h>

int main()
{
    int distance, fare;

    printf("Enter distance travelled (in km): ");
    scanf("%d", &distance);

    fare = distance * 2;

    printf("Total Fare = Rs.%d\n", fare);

    return 0;
}
