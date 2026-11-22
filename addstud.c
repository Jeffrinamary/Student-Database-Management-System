#include "header.h"

void stud_add(void)
{
    ST *newnode;
    ST *temp;
    ST *ptr;
    int roll = 1;
    int found;

    newnode = (ST *)malloc(sizeof(ST));

    if (newnode == NULL)
    {
        printf("Memory Not Allocated\n");
        return;
    }

    printf("Enter Student Name: ");
    scanf(" %99[^\n]", newnode->student_name);

    printf("Enter Percentage: ");
    if (scanf("%f", &newnode->marks) != 1)
    {
        printf("Invalid Percentage\n");
        free(newnode);
        return;
    }

    /* Find the smallest available positive roll number. */
    while (1)
    {
        found = 0;
        for (temp = hptr; temp != NULL; temp = temp->link)
        {
            if (temp->id == roll)
            {
                found = 1;
                break;
            }
        }

        if (!found)
            break;

        roll++;
    }

    newnode->id = roll;
    newnode->link = NULL;

    if (hptr == NULL)
    {
        hptr = newnode;
    }
    else
    {
        ptr = hptr;
        while (ptr->link != NULL)
            ptr = ptr->link;

        ptr->link = newnode;
    }

    printf("Student Added Successfully. Roll Number: %d\n", roll);
}
