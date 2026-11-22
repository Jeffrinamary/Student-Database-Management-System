#include "header.h"

void stud_mod(void)
{
    ST *temp;
    int roll;
    int found = 0;
    float percentage;
    char option;
    char field;
    char search_name[100];

    if (hptr == NULL)
    {
        printf("No Records Available\n");
        return;
    }

    printf("R/r : Search by Roll Number\n");
    printf("N/n : Search by Name\n");
    printf("P/p : Search by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &option);

    if (option == 'R' || option == 'r')
    {
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
    }
    else if (option == 'N' || option == 'n')
    {
        printf("Enter Student Name: ");
        scanf(" %99[^\n]", search_name);

        printf("\nMatching Records:\n");
        printf("%-12s %-20s %-12s\n", "Roll No", "Name", "Percentage");

        for (temp = hptr; temp != NULL; temp = temp->link)
        {
            if (strcmp(temp->student_name, search_name) == 0)
            {
                printf("%-12d %-20s %-12.2f\n",
                       temp->id, temp->student_name, temp->marks);
                found = 1;
            }
        }

        if (!found)
        {
            printf("Student Name Not Found\n");
            return;
        }

        printf("Enter Roll Number to Modify: ");
        scanf("%d", &roll);
    }
    else if (option == 'P' || option == 'p')
    {
        printf("Enter Percentage: ");
        scanf("%f", &percentage);

        printf("\nMatching Records:\n");
        printf("%-12s %-20s %-12s\n", "Roll No", "Name", "Percentage");

        for (temp = hptr; temp != NULL; temp = temp->link)
        {
            if (temp->marks == percentage)
            {
                printf("%-12d %-20s %-12.2f\n",
                       temp->id, temp->student_name, temp->marks);
                found = 1;
            }
        }

        if (!found)
        {
            printf("Percentage Not Found\n");
            return;
        }

        printf("Enter Roll Number to Modify: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid Choice\n");
        return;
    }

    for (temp = hptr; temp != NULL; temp = temp->link)
    {
        if (temp->id == roll)
            break;
    }

    if (temp == NULL)
    {
        printf("Roll Number Not Found\n");
        return;
    }

    if ((option == 'N' || option == 'n') &&
        strcmp(temp->student_name, search_name) != 0)
    {
        printf("Roll Number Does Not Match the Given Name\n");
        return;
    }

    if ((option == 'P' || option == 'p') && temp->marks != percentage)
    {
        printf("Roll Number Does Not Match the Given Percentage\n");
        return;
    }

    printf("N/n : Modify Name\n");
    printf("P/p : Modify Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &field);

    if (field == 'N' || field == 'n')
    {
        printf("Enter New Name: ");
        scanf(" %99[^\n]", temp->student_name);
        printf("Name Modified Successfully\n");
    }
    else if (field == 'P' || field == 'p')
    {
        printf("Enter New Percentage: ");
        scanf("%f", &temp->marks);
        printf("Percentage Modified Successfully\n");
    }
    else
    {
        printf("Invalid Choice\n");
    }
}
