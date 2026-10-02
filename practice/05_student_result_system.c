#include <stdio.h>

struct Student
{
    int rollNo;
    char name[30];
    float marks[3];
    float total;
    float average;
    char grade;
};

void calculateResult(struct Student *s)
{
    s->total = s->marks[0] + s->marks[1] + s->marks[2];
    s->average = s->total / 3;

    if(s->average >= 90)
        s->grade = 'A';
    else if(s->average >= 75)
        s->grade = 'B';
    else if(s->average >= 60)
        s->grade = 'C';
    else if(s->average >= 40)
        s->grade = 'D';
    else
        s->grade = 'F';
}

void displayStudent(struct Student s)
{
    printf("\nRoll Number : %d\n", s.rollNo);
    printf("Name        : %s\n", s.name);
    printf("Total       : %.2f\n", s.total);
    printf("Average     : %.2f\n", s.average);
    printf("Grade       : %c\n", s.grade);
}

int main()
{
    struct Student students[10];
    int n, i;

    printf("===== STUDENT RESULT MANAGEMENT =====\n");

    printf("Enter number of students (maximum 10): ");
    scanf("%d", &n);

    if(n <= 0 || n > 10)
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

        printf("Enter marks for 3 subjects:\n");

        for(int j = 0; j < 3; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }

        calculateResult(&students[i]);
    }

    printf("\n========== RESULT ==========\n");

    for(i = 0; i < n; i++)
        displayStudent(students[i]);

    return 0;
}
