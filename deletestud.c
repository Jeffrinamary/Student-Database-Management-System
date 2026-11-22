#include "header.h"

void stud_del(void)
{
    ST *temp;
    ST *ptr;
    ST *previous = NULL;
    int roll;
    int found = 0;
    char option;
    char search_name[100];

    if (hptr == NULL)
    {
        printf("No Records Available\n");
        return;
    }

    printf("R/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
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

        printf("Enter Roll Number to Delete: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid Choice\n");
        return;
    }

    temp = hptr;
    while (temp != NULL && temp->id != roll)
    {
        previous = temp;
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("Roll Number Not Found\n");
        return;
    }

    if (option == 'N' || option == 'n')
    {
        if (strcmp(temp->student_name, search_name) != 0)
        {
            printf("That Roll Number Does Not Match the Given Name\n");
            return;
        }
    }

    if (previous == NULL)
        hptr = temp->link;
    else
        previous->link = temp->link;

    free(temp);
    printf("Record Deleted Successfully\n");
}
