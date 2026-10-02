#include <stdio.h>
#include <string.h>

void displayLength(char str[])
{
    int i = 0;

    while(str[i] != '\0')
        i++;

    printf("Length: %d\n", i);
}

void reverseString(char str[])
{
    int i = 0, j;
    char temp;

    while(str[i] != '\0')
        i++;

    for(j = i - 1, i = 0; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    char str[100];
    int choice;

    printf("===== STRING OPERATIONS SYSTEM =====\n");

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Display Length\n");
        printf("2. Reverse String\n");
        printf("3. Compare with Another String\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayLength(str);
                break;

            case 2:
                reverseString(str);
                printf("Reversed String: %s\n", str);
                break;

            case 3:
            {
                char another[100];

                printf("Enter another string: ");
                scanf(" %[^\n]", another);

                if(strcmp(str, another) == 0)
                    printf("Both strings are equal.\n");
                else
                    printf("Strings are different.\n");

                break;
            }

            case 4:
                printf("Exiting string operations.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}
