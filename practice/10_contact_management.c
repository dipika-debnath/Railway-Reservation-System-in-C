#include <stdio.h>
#include <string.h>

struct Contact
{
    char name[30];
    char phone[15];
    char email[40];
};

void displayContact(struct Contact c)
{
    printf("\nName  : %s\n", c.name);
    printf("Phone : %s\n", c.phone);
    printf("Email : %s\n", c.email);
}

int main()
{
    struct Contact contacts[20];
    int n, i, choice, found;
    char searchName[30];

    printf("===== CONTACT MANAGEMENT SYSTEM =====\n");

    printf("Enter number of contacts (maximum 20): ");
    scanf("%d", &n);

    if(n <= 0 || n > 20)
    {
        printf("Invalid number of contacts.\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\n--- Contact %d ---\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", contacts[i].name);

        printf("Enter phone number: ");
        scanf("%s", contacts[i].phone);

        printf("Enter email: ");
        scanf("%s", contacts[i].email);
    }

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Display All Contacts\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                for(i = 0; i < n; i++)
                {
                    printf("\n--- Contact %d ---", i + 1);
                    displayContact(contacts[i]);
                }
                break;

            case 2:
                printf("Enter name to search: ");
                scanf(" %[^\n]", searchName);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(strcmp(contacts[i].name, searchName) == 0)
                    {
                        displayContact(contacts[i]);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Contact not found.\n");

                break;

            case 3:
                printf("Exiting contact management system.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 3);

    return 0;
}
