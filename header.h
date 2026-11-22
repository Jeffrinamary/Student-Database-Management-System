#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int id;
    char student_name[100];
    float marks;
    struct student *link;
} ST;

extern ST *hptr;

void stud_add(void);
void stud_del(void);
void stud_show(void);
void stud_mod(void);
void stud_save(void);
void stud_load(void);
void stud_sort(void);

#endif
