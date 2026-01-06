#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "TeacherLibrary.h"

Teacher *teacher_head = NULL;



void Add_Teacher_Record(Teacher **head) {
    Teacher *new_teacher = malloc(sizeof(Teacher));
    if (!new_teacher) return;

    printf("Enter teacher name: ");
    fgets(new_teacher->name, sizeof(new_teacher->name), stdin);
    new_teacher->name[strcspn(new_teacher->name, "\n")] = '\0';

    printf("Enter subject taught: ");
    fgets(new_teacher->subject, sizeof(new_teacher->subject), stdin);
    new_teacher->subject[strcspn(new_teacher->subject, "\n")] = '\0';

    new_teacher->next = *head;
    *head = new_teacher;
}

void Enter_Grade(Student *s, const char *subject, int grade) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(s->subjects[i], subject) == 0) {
            s->grades[i] = grade;
            return;
        }
    }
    printf("Subject not found for %s\n", s->name);
}

void Find_Teacher_By_Subject(const char *subject)
{
    Teacher *current = teacher_head;
    int found = 0;

    printf("\nTeacher who teaches %s:\n", subject);

    while (current != NULL)
    {
        if (strcmp(current->subject, subject) == 0)
        {
            printf("- %s\n", current->name);
            found = 1;
            break;  
        }
        current = current->next;
    }

    if (!found)
    {
        printf("No teacher found for this subject.\n");
    }
}