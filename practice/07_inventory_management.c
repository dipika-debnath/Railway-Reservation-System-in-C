#include <stdio.h>

struct Product
{
    int id;
    char name[30];
    int quantity;
    float price;
};

void displayProduct(struct Product p)
{
    printf("\nID       : %d\n", p.id);
    printf("Name     : %s\n", p.name);
    printf("Quantity : %d\n", p.quantity);
    printf("Price    : Rs.%.2f\n", p.price);
}

void addStock(struct Product *p)
{
    int amount;

    printf("Enter quantity to add: ");
    scanf("%d", &amount);

    if(amount > 0)
    {
        p->quantity += amount;
        printf("Stock updated successfully.\n");
    }
    else
        printf("Invalid quantity.\n");
}

void sellProduct(struct Product *p)
{
    int amount;

    printf("Enter quantity to sell: ");
    scanf("%d", &amount);

    if(amount <= 0)
        printf("Invalid quantity.\n");
    else if(amount > p->quantity)
        printf("Not enough stock available.\n");
    else
    {
        p->quantity -= amount;
        printf("Sale completed successfully.\n");
    }
}

int main()
{
    struct Product products[10];
    int n, i, choice, searchId, found;

    printf("===== INVENTORY MANAGEMENT SYSTEM =====\n");

    printf("Enter number of products (maximum 10): ");
    scanf("%d", &n);

    if(n <= 0 || n > 10)
    {
        printf("Invalid number of products.\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\n--- Product %d ---\n", i + 1);

        printf("Enter product ID: ");
        scanf("%d", &products[i].id);

        printf("Enter product name: ");
        scanf(" %[^\n]", products[i].name);

        printf("Enter quantity: ");
        scanf("%d", &products[i].quantity);

        printf("Enter price: Rs.");
        scanf("%f", &products[i].price);
    }

    printf("\nEnter product ID to manage: ");
    scanf("%d", &searchId);

    found = 0;

    for(i = 0; i < n; i++)
    {
        if(products[i].id == searchId)
        {
            found = 1;

            do
            {
                printf("\n===== PRODUCT MENU =====\n");
                printf("1. Display Product\n");
                printf("2. Add Stock\n");
                printf("3. Sell Product\n");
                printf("4. Exit\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                switch(choice)
                {
                    case 1:
                        displayProduct(products[i]);
                        break;

                    case 2:
                        addStock(&products[i]);
                        break;

                    case 3:
                        sellProduct(&products[i]);
                        break;

                    case 4:
                        printf("Exiting product management.\n");
                        break;

                    default:
                        printf("Invalid choice.\n");
                }

            } while(choice != 4);

            break;
        }
    }

    if(found == 0)
        printf("Product not found.\n");

    return 0;
}
