#include <stdio.h>

int main()
{
    int seats[5][4];
    int coaches, i, j;

    printf("Enter number of coaches (1-5): ");
    scanf("%d", &coaches);

    if(coaches < 1 || coaches > 5)
    {
        printf("Invalid number of coaches.\n");
        return 0;
    }

    printf("\nEnter seat status (0 = Available, 1 = Booked)\n");

    for(i = 0; i < coaches; i++)
    {
        printf("\nCoach %d\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("Seat %d: ", j + 1);
            scanf("%d", &seats[i][j]);
        }
    }

    printf("\n===== SEAT MATRIX =====\n");

    for(i = 0; i < coaches; i++)
    {
        printf("Coach %d: ", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("%d ", seats[i][j]);
        }

        printf("\n");
    }

    return 0;
}
