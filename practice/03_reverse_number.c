#include <stdio.h>

int main()
{
    int n, original, reverse = 0, digit;

    printf("===== REVERSE NUMBER =====\n");

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    if(n < 0)
        n = -n;

    while(n > 0)
    {
        digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }

    if(original < 0)
        reverse = -reverse;

    printf("Original Number : %d\n", original);
    printf("Reversed Number : %d\n", reverse);

    return 0;
}
