// Lab 1
// Question 4
// Write a program to read name, rollno, address, and phone number of each student in your class using structure. Store the information in file so that you can recover the information later. While recovering the information from the file sort the information alphabetically according to the name.

#include <stdio.h>
#include <string.h>

struct Student
{
    char name[20];
    int roll;
    char address[20];
    char phoneNumber[10];
};

int storeInfo()
{
    FILE *fp = fopen("info.txt", "a");
    if (fp == NULL)
    {
        fprintf(stderr, "could not open the file");
        return -1;
    }
    struct Student s;
    char ans;
    do
    {
        printf("Enter the name of the student: ");
        scanf(" %s", s.name);
        printf("Enter the roll no: ");
        scanf(" %d", &s.roll);
        printf("Enter the address of the student: ");
        scanf(" %s", s.address);
        printf("Enter the phone no of the student: ");
        scanf(" %s", s.phoneNumber);
        fprintf(fp, "%s %d %s %s\n", s.name, s.roll, s.address, s.phoneNumber);
        printf("Press y to continue\n");
        // asking if user want to add another record
        scanf(" %c", &ans);
    } while (ans == 'y');
    fclose(fp);
}

void sortAlphabetically(struct Student a[], int n)
{
    struct Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i].name, a[j].name) > 0)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int retrieveInfo()
{
    struct Student s;
    int record = 0;
    FILE *fp = fopen("info.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "could not open the file");
        return -1;
    }
    while (1)
    {
        fscanf(fp, "%s %d %s %s\n", s.name, &s.roll, s.address, s.phoneNumber);
        record++;
        if (feof(fp))
            break;
    }
    // rewind file to beginning
    rewind(fp);
    struct Student students[record];
    for (int i = 0; i < record; i++)
    {
        fscanf(fp, "%s %d %s %s", students[i].name, &students[i].roll, students[i].address, students[i].phoneNumber);
    }
    fclose(fp);

    sortAlphabetically(students, record);
    printf("\nRetrieving data:\n");
    for (int i = 0; i < record; i++)
    {
        printf("Name = %s\n", students[i].name);
        printf("Roll = %d\n", students[i].roll);
        printf("Address = %s\n", students[i].address);
        printf("Phone no = %s\n", students[i].phoneNumber);
        printf("\n");
    }
}

int main()
{
    printf("What do you want to do:\n1. Store data\n2. Retrive data\n");
    int choice;
    printf("Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        storeInfo();
        break;
    case 2:
        retrieveInfo();
        break;
    default:
        printf("Invalid choice!");
        break;
    }
}