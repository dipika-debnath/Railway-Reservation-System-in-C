#include <stdio.h>

struct Account
{
    int accountNo;
    char name[30];
    float balance;
};

void deposit(struct Account *a)
{
    float amount;

    printf("Enter deposit amount: Rs.");
    scanf("%f", &amount);

    if(amount > 0)
    {
        a->balance += amount;
        printf("Amount deposited successfully.\n");
    }
    else
        printf("Invalid amount.\n");
}

void withdraw(struct Account *a)
{
    float amount;

    printf("Enter withdrawal amount: Rs.");
    scanf("%f", &amount);

    if(amount <= 0)
        printf("Invalid amount.\n");
    else if(amount > a->balance)
        printf("Insufficient balance.\n");
    else
    {
        a->balance -= amount;
        printf("Amount withdrawn successfully.\n");
    }
}

void displayAccount(struct Account a)
{
    printf("\n===== ACCOUNT DETAILS =====\n");
    printf("Account Number : %d\n", a.accountNo);
    printf("Account Holder : %s\n", a.name);
    printf("Balance       : Rs.%.2f\n", a.balance);
}

int main()
{
    struct Account account;
    int choice;

    printf("===== BANK ACCOUNT SYSTEM =====\n");

    printf("Enter account number: ");
    scanf("%d", &account.accountNo);

    printf("Enter account holder name: ");
    scanf(" %[^\n]", account.name);

    printf("Enter initial balance: Rs.");
    scanf("%f", &account.balance);

    if(account.balance < 0)
    {
        printf("Invalid balance.\n");
        return 0;
    }

    do
    {
        printf("\n1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display Account\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                deposit(&account);
                break;

            case 2:
                withdraw(&account);
                break;

            case 3:
                displayAccount(account);
                break;

            case 4:
                printf("Thank you for using the system.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}
