#include <stdio.h>

struct Student
{
    int rollNo;
    char name[30];
    float marks;
};

void displayStudents(struct Student s[], int n)
{
    int i;

    printf("\n===== STUDENT DETAILS =====\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRoll No : %d\n", s[i].rollNo);
        printf("Name    : %s\n", s[i].name);
        printf("Marks   : %.2f\n", s[i].marks);
    }
}

void sortStudents(struct Student s[], int n)
{
    int i, j;
    struct Student temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].marks < s[j + 1].marks)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main()
{
    struct Student students[20];
    int n, i, choice, searchRoll, found;

    printf("===== STUDENT MARKS SYSTEM =====\n");

    printf("Enter number of students (maximum 20): ");
    scanf("%d", &n);

    if(n <= 0 || n > 20)
    {
        printf("Invalid number of students.\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Display Students\n");
        printf("2. Search by Roll Number\n");
        printf("3. Sort by Marks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayStudents(students, n);
                break;

            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &searchRoll);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(students[i].rollNo == searchRoll)
                    {
                        printf("\nStudent Found!\n");
                        printf("Name  : %s\n", students[i].name);
                        printf("Marks : %.2f\n", students[i].marks);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Student not found.\n");

                break;

            case 3:
                sortStudents(students, n);
                printf("Students sorted by marks (highest to lowest).\n");
                break;

            case 4:
                printf("Exiting student marks system.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}
