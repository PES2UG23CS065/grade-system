#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades.h"

void grade(int SRN) {
    const char *names[] = {"Ananya Shet", "Taniya", "Rinna", "Akash", "Jhanvi"};
    const char *subjects[] = {"Physics", "Maths", "EEE", "Mech", "C.S", "EVS"};
    int total_marks = 600; // Total marks for all subjects
    int total1, total2, total3;
    int cgpa;

    if (SRN >= 1 && SRN <= 5) {
        struct Marks *marks_data = (struct Marks *)malloc(5 * sizeof(struct Marks));
        if (marks_data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        marks_data[0] = (struct Marks){{87, 95, 64, 79, 78, 69}, {78, 89, 87, 90, 69, 70}, {80, 90, 86, 67, 95, 74}};
        marks_data[1] = (struct Marks){{78, 85, 84, 89, 88, 89}, {74, 89, 59, 67, 89, 89}, {90, 98, 87, 94, 95, 94}};
        marks_data[2] = (struct Marks){{67, 34, 89, 70, 88, 56}, {80, 49, 22, 58, 49, 50}, {90, 68, 45, 78, 46, 54}};
        marks_data[3] = (struct Marks){{100, 95, 89, 78, 90, 78}, {65, 89, 52, 67, 59, 46}, {50, 58, 89, 94, 95, 94}};
        marks_data[4] = (struct Marks){{45, 29, 69, 40, 37, 30}, {50, 37, 47, 57, 39, 50}, {12, 68, 39, 54, 25, 54}};

        total1 = total2 = total3 = 0;

        struct Marks student_marks = marks_data[SRN - 1]; // Adjust index for array

        for (int i = 0; i < 6; i++) {
            total1 += student_marks.marks1[i];
            total2 += student_marks.marks2[i];
            total3 += student_marks.marks3[i];
            printf("%s\t\t%d\t%d\t%d\n", subjects[i], student_marks.marks1[i], student_marks.marks2[i], student_marks.marks3[i]);
        }

        cgpa = (total1 + total2 + total3) / (200); // Assuming total marks for each subject is 100
        printf("Total\t\t%d\t%d\t%d\nCGPA:%d\n", total1, total2, total3, cgpa);

        // Print grade based on CGPA
        switch (cgpa) {
            case 10: printf("\t\tGRADE :- S\n"); break;
            case 9: printf("\t\tGRADE :- A\n"); break;
            case 8: printf("\t\tGRADE :- B\n"); break;
            case 7: printf("\t\tGRADE :- C\n"); break;
            case 6: printf("\t\tGRADE :- D\n"); break;
            case 5: printf("\t\tGRADE :- E\n"); break;
            default: printf("\t\tGRADE :- Fail\n"); break;
        }

        free(marks_data);
    } else {
        printf("NO DATA AVAILABLE\n");
    }
}
