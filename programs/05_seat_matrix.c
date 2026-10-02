#include <stdio.h>

int main()
{
    int seats[5][4];
    int coaches, i, j;
    int available = 0, booked = 0;

    printf("===== COACH SEAT MANAGEMENT =====\n");

    printf("Enter number of coaches (1-5): ");
    scanf("%d", &coaches);

    if(coaches < 1 || coaches > 5)
    {
        printf("Invalid number of coaches.\n");
        return 0;
    }

    printf("\nEnter seat status:\n");
    printf("0 = Available\n");
    printf("1 = Booked\n");

    for(i = 0; i < coaches; i++)
    {
        printf("\n--- Coach %d ---\n", i + 1);

        for(j = 0; j < 4; j++)
        {
            do
            {
                printf("Seat %d: ", j + 1);
                scanf("%d", &seats[i][j]);

                if(seats[i][j] != 0 && seats[i][j] != 1)
                    printf("Enter only 0 or 1.\n");

            } while(seats[i][j] != 0 && seats[i][j] != 1);
        }
    }

    printf("\n========== SEAT MATRIX ==========\n");

    for(i = 0; i < coaches; i++)
    {
        printf("Coach %d: ", i + 1);

        for(j = 0; j < 4; j++)
        {
            printf("%d ", seats[i][j]);

            if(seats[i][j] == 0)
                available++;
            else
                booked++;
        }

        printf("\n");
    }

    printf("\nAvailable Seats : %d\n", available);
    printf("Booked Seats    : %d\n", booked);

    return 0;
}
