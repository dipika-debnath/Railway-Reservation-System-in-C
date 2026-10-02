#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    char author[30];
    int available;
};

void displayBook(struct Book b)
{
    printf("\nBook ID      : %d\n", b.id);
    printf("Title        : %s\n", b.title);
    printf("Author       : %s\n", b.author);

    if(b.available == 1)
        printf("Status       : Available\n");
    else
        printf("Status       : Issued\n");
}

void issueBook(struct Book *b)
{
    if(b->available == 1)
    {
        b->available = 0;
        printf("Book issued successfully.\n");
    }
    else
        printf("Book is already issued.\n");
}

void returnBook(struct Book *b)
{
    if(b->available == 0)
    {
        b->available = 1;
        printf("Book returned successfully.\n");
    }
    else
        printf("Book is already available.\n");
}

int main()
{
    struct Book books[10];
    int n, i, searchId, choice, found = 0;

    printf("===== LIBRARY MANAGEMENT SYSTEM =====\n");

    printf("Enter number of books (maximum 10): ");
    scanf("%d", &n);

    if(n <= 0 || n > 10)
    {
        printf("Invalid number of books.\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\n--- Book %d ---\n", i + 1);

        printf("Enter book ID: ");
        scanf("%d", &books[i].id);

        printf("Enter book title: ");
        scanf(" %[^\n]", books[i].title);

        printf("Enter author name: ");
        scanf(" %[^\n]", books[i].author);

        books[i].available = 1;
    }

    printf("\nEnter book ID to manage: ");
    scanf("%d", &searchId);

    for(i = 0; i < n; i++)
    {
        if(books[i].id == searchId)
        {
            found = 1;

            do
            {
                printf("\n===== BOOK MENU =====\n");
                printf("1. Display Book\n");
                printf("2. Issue Book\n");
                printf("3. Return Book\n");
                printf("4. Exit\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                switch(choice)
                {
                    case 1:
                        displayBook(books[i]);
                        break;

                    case 2:
                        issueBook(&books[i]);
                        break;

                    case 3:
                        returnBook(&books[i]);
                        break;

                    case 4:
                        printf("Exiting book management.\n");
                        break;

                    default:
                        printf("Invalid choice.\n");
                }

            } while(choice != 4);

            break;
        }
    }

    if(found == 0)
        printf("Book not found.\n");

    return 0;
}
