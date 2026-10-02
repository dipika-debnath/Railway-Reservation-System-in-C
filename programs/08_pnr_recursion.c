#include <stdio.h>

int searchPNR(int pnr[], int n, int index, int target)
{
    if(index == n)
        return -1;

    if(pnr[index] == target)
        return index;

    return searchPNR(pnr, n, index + 1, target);
}

int main()
{
    int pnr[10];
    int n, i, target, result;

    printf("===== PNR SEARCH SYSTEM =====\n");

    printf("Enter number of bookings (maximum 10): ");
    scanf("%d", &n);

    if(n <= 0 || n > 10)
    {
        printf("Invalid number of bookings.\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter PNR for booking %d: ", i + 1);
        scanf("%d", &pnr[i]);
    }

    printf("\nEnter PNR to search: ");
    scanf("%d", &target);

    result = searchPNR(pnr, n, 0, target);

    if(result != -1)
        printf("\nPNR %d found at booking %d.\n",
               target, result + 1);
    else
        printf("\nPNR %d not found.\n", target);

    return 0;
}
