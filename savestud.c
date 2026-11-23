#include "header.h"

void stud_save(void)
{
    FILE *fp;
    ST *temp;

    fp = fopen("student.dat", "w");

    if (fp == NULL)
    {
        printf("Unable to Open student.dat for Saving\n");
        return;
    }

    for (temp = hptr; temp != NULL; temp = temp->link)
    {
        
        fprintf(fp, "%d|%s|%.2f\n",
                temp->id, temp->student_name, temp->marks);
    }

    fclose(fp);
    printf("Records Saved Successfully\n");
}

void stud_load(void)
{
    FILE *fp;
    ST *newnode;
    ST *temp;
    int roll;
    float percentage;
    char name[100];
    char line[256];
    char *first;
    char *second;
    char *endptr;

    fp = fopen("student.dat", "r");

    if (fp == NULL)
        return; 

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        first = strchr(line, '|');
        if (first == NULL)
            continue;

        *first = '\0';
        second = strchr(first + 1, '|');
        if (second == NULL)
            continue;

        *second = '\0';

        roll = (int)strtol(line, &endptr, 10);
        if (*endptr != '\0' || roll <= 0)
            continue;

        if (strlen(first + 1) >= sizeof(name))
            continue;

        strcpy(name, first + 1);

        percentage = strtof(second + 1, &endptr);
        if (endptr == second + 1)
            continue;

        newnode = (ST *)malloc(sizeof(ST));
        if (newnode == NULL)
        {
            printf("Memory Not Allocated While Loading Records\n");
            break;
        }

        newnode->id = roll;
        strcpy(newnode->student_name, name);
        newnode->marks = percentage;
        newnode->link = NULL;

        if (hptr == NULL)
        {
            hptr = newnode;
        }
        else
        {
            temp = hptr;
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = newnode;
        }
    }

    fclose(fp);
}
