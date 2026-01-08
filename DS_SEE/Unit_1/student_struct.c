#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student 
{
    char student_name[30];
    int RollNo;

    struct admission_date {
        int day;
        int month;
        int year;
    } date;

    char Dept[30];
} s[10];

void accept()
{
    for(int i=0; i<10; i++)
    {
        printf("enter student name: ");
        scanf("%s", s[i].student_name);

        printf("\nenter student rollno: ");
        scanf("%d", &s[i].RollNo);

        printf("\nenter student admission date: ");
        printf("\nenter admission day: ");
        scanf("%d", &s[i].date.day);
        printf("\nenter admission month: ");
        scanf("%d", &s[i].date.month);
        printf("\nenter admission year: ");
        scanf("%d", &s[i].date.year);

        printf("\nenter student department: ");
        scanf("%s", s[i].Dept);
    }
}

void display()
{
    char Dept[30];

    printf("enter the department to display: ");
    scanf("%s", Dept);

    printf("\nstudents of %s department: ", Dept);

    for(int i=0; i<10; i++)
    {
        if(strcmp(s[i].Dept, Dept) == 0)
        {
            printf("student name: %s", s[i].student_name);

            printf("\nstudent rollno: %d", s[i].RollNo);
            
            printf("\nstudent admission date: %d-%d-%d", s[i].date.day, s[i].date.month, s[i].date.year);

            printf("\nstudent department: %s \n", s[i].Dept);
        }
    }
}

int main()
{
    accept();
    display();
    return 0;
}
