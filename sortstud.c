#include "header.h"

void stud_sort(void)
{
    ST *temp;
    ST *ptr;
    ST *copy = NULL;
    ST *newnode;
    ST *current;
    int swap_id;
    char swap_name[100];
    float swap_marks;
    char option;

    if (hptr == NULL)
    {
        printf("No Records Available\n");
        return;
    }

    printf("N/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &option);

    if (option != 'N' && option != 'n' &&
        option != 'P' && option != 'p')
    {
        printf("Invalid Choice\n");
        return;
    }

    /* Make a separate copy so the original linked list stays unchanged. */
    for (temp = hptr; temp != NULL; temp = temp->link)
    {
        newnode = (ST *)malloc(sizeof(ST));

        if (newnode == NULL)
        {
            printf("Memory Not Allocated\n");
            while (copy != NULL)
            {
                temp = copy;
                copy = copy->link;
                free(temp);
            }
            return;
        }

        newnode->id = temp->id;
        strcpy(newnode->student_name, temp->student_name);
        newnode->marks = temp->marks;
        newnode->link = NULL;

        if (copy == NULL)
        {
            copy = newnode;
        }
        else
        {
            current = copy;
            while (current->link != NULL)
                current = current->link;
            current->link = newnode;
        }
    }

    /* Sort only the copied list. */
    for (temp = copy; temp != NULL; temp = temp->link)
    {
        for (ptr = temp->link; ptr != NULL; ptr = ptr->link)
        {
            if (((option == 'N' || option == 'n') &&
                 strcmp(temp->student_name, ptr->student_name) > 0) ||
                ((option == 'P' || option == 'p') &&
                 temp->marks > ptr->marks))
            {
                swap_id = temp->id;
                temp->id = ptr->id;
                ptr->id = swap_id;

                strcpy(swap_name, temp->student_name);
                strcpy(temp->student_name, ptr->student_name);
                strcpy(ptr->student_name, swap_name);

                swap_marks = temp->marks;
                temp->marks = ptr->marks;
                ptr->marks = swap_marks;
            }
        }
    }

    printf("\nSorted Records:\n");
    printf("------------------------------------------------\n");
    printf("%-12s %-20s %-12s\n", "Roll No", "Name", "Percentage");
    printf("------------------------------------------------\n");

    for (temp = copy; temp != NULL; temp = temp->link)
    {
        printf("%-12d %-20s %-12.2f\n",
               temp->id, temp->student_name, temp->marks);
    }

    printf("------------------------------------------------\n");

    while (copy != NULL)
    {
        temp = copy;
        copy = copy->link;
        free(temp);
    }

    printf("Original Records Not Modified\n");
}
