#include <stdio.h>

struct Employee
{
    int id;
    char name[30];
    float basicSalary;
    float allowance;
    float deduction;
    float netSalary;
};

void calculateSalary(struct Employee *e)
{
    e->allowance = e->basicSalary * 0.20;
    e->deduction = e->basicSalary * 0.10;
    e->netSalary = e->basicSalary + e->allowance - e->deduction;
}

void displayEmployee(struct Employee e)
{
    printf("\n===== EMPLOYEE DETAILS =====\n");
    printf("Employee ID  : %d\n", e.id);
    printf("Name         : %s\n", e.name);
    printf("Basic Salary : Rs.%.2f\n", e.basicSalary);
    printf("Allowance    : Rs.%.2f\n", e.allowance);
    printf("Deduction    : Rs.%.2f\n", e.deduction);
    printf("Net Salary   : Rs.%.2f\n", e.netSalary);
}

int main()
{
    struct Employee employees[10];
    int n, i, searchId, found = 0;

    printf("===== EMPLOYEE PAYROLL SYSTEM =====\n");

    printf("Enter number of employees (maximum 10): ");
    scanf("%d", &n);

    if(n <= 0 || n > 10)
    {
        printf("Invalid number of employees.\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\n--- Employee %d ---\n", i + 1);

        printf("Enter employee ID: ");
        scanf("%d", &employees[i].id);

        printf("Enter employee name: ");
        scanf(" %[^\n]", employees[i].name);

        printf("Enter basic salary: Rs.");
        scanf("%f", &employees[i].basicSalary);

        if(employees[i].basicSalary < 0)
        {
            printf("Invalid salary.\n");
            return 0;
        }

        calculateSalary(&employees[i]);
    }

    printf("\nEnter employee ID to search: ");
    scanf("%d", &searchId);

    for(i = 0; i < n; i++)
    {
        if(employees[i].id == searchId)
        {
            displayEmployee(employees[i]);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nEmployee not found.\n");

    return 0;
}
