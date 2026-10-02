#include <stdio.h>

int main()
{
    int n, original, digit, sum = 0;

    printf("===== SUM OF DIGITS =====\n");

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    if(n < 0)
        n = -n;

    while(n > 0)
    {
        digit = n % 10;
        sum = sum + digit;
        n = n / 10;
    }

    printf("Sum of digits of %d = %d\n", original, sum);

    return 0;
}
