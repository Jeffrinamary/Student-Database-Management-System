#include "header.h"

ST *hptr = NULL;

int main(void)
{
    char choice;
    char exit_choice;

    stud_load();

    while (1)
    {
        printf("\n**** STUDENT RECORD MENU ****\n");
        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n");
        printf("Enter Your Choice: ");

        scanf(" %c", &choice);

        switch (choice)
        {
            case 'A':
            case 'a':
                stud_add();
                break;

            case 'D':
            case 'd':
                stud_del();
                break;

            case 'S':
            case 's':
                stud_show();
                break;

            case 'M':
            case 'm':
                stud_mod();
                break;

            case 'V':
            case 'v':
                stud_save();
                break;

            case 'T':
            case 't':
                stud_sort();
                break;

            case 'E':
            case 'e':
                printf("\nS/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("Enter Your Choice: ");
                scanf(" %c", &exit_choice);

                if (exit_choice == 'S' || exit_choice == 's')
                    stud_save();
                else if (exit_choice != 'E' && exit_choice != 'e')
                    printf("Invalid Choice\n");

                while (hptr != NULL)
                {
                    ST *temp = hptr;
                    hptr = hptr->link;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
