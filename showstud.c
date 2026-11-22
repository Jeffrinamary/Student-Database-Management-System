#include "header.h"

void stud_show(void)
{
    ST *temp;

    if (hptr == NULL)
    {
        printf("No Records Available\n");
        return;
    }

    printf("\n------------------------------------------------\n");
    printf("%-12s %-20s %-12s\n", "Roll No", "Name", "Percentage");
    printf("------------------------------------------------\n");

    for (temp = hptr; temp != NULL; temp = temp->link)
    {
        printf("%-12d %-20s %-12.2f\n",
               temp->id, temp->student_name, temp->marks);
    }

    printf("------------------------------------------------\n");
}
