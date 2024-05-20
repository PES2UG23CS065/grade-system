#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades.h"

#define MAX_LINE_LENGTH 200
#define FILE_PATH "MARKS.csv"

typedef struct {
    int srn;
    char name[50];
    int isa1[6];
    int isa2[6];
    int isa3[6];
} Student;

void print_student_data(Student student) {
    printf("|------------------------------------------------------------------------|\n");
    printf("| SRN: %-64d |\n", student.srn);
    printf("| NAME: %-64s |\n", student.name);
    printf("|------------------------------------------------------------------------|\n");
    printf("| ISA1: PHYSICS | ELECTRICAL | COMPUTERSCIENCE | EVS | MATHS | MECHANICAL |\n");
    printf("|%12d\t|%12d|%17d|%5d|%7d|%12d|\n", student.isa1[0], student.isa1[1], student.isa1[2], student.isa1[3], student.isa1[4], student.isa1[5]);
    printf("|------------------------------------------------------------------------|\n");
    printf("| ISA2: PHYSICS | ELECTRICAL | CS | EVS | MATHS | MECHANICAL |\n");
    printf("|%12d\t|%12d|%17d|%5d|%7d|%12d|\n", student.isa2[0], student.isa2[1], student.isa2[2], student.isa2[3], student.isa2[4], student.isa2[5]);
    printf("|------------------------------------------------------------------------|\n");
    printf("| ISA3: PHYSICS | ELECTRICAL | CS | EVS | MATHS | MECHANICAL |\n");
    printf("|%12d\t|%12d|%17d|%5d|%7d|%12d|\n", student.isa3[0], student.isa3[1], student.isa3[2], student.isa3[3], student.isa3[4], student.isa3[5]);
    printf("|------------------------------------------------------------------------|\n");

    int total1 = 0, total2 = 0, total3 = 0;
    for (int i = 0; i < 6; i++) {
        total1 += student.isa1[i];
        total2 += student.isa2[i];
        total3 += student.isa3[i];
    }
    int cgpa = (total1 + total2 + total3) / 180;

    printf("| CGPA: %d                                                         |\n", cgpa);
    switch(cgpa)
{
    case 10: printf("\tGrade :S\n");
		break;
   case 9 : printf("\tGrade :A\n");
 		break;
   case 8: printf("\tGrade :B\n");
		break;
   case 7 : printf("\tGrade :C\n");
 		break;
   case 6: printf("\tGrade :D\n");
		break;
   case 5 : printf("\tGrade :E\n");
 		break;
   default: printf("\tGrade :F");
		break;
   }

    printf("|------------------------------------------------------------------------|\n");
}

void search_student(int SRN) {
    FILE *fp = fopen("MARKS.csv", "r"); // Open file in read mode
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH]; // Assuming each line in the CSV file is not longer than 200 characters
    Student student;
    int found = 0;

    // Skip header
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, ",");
        student.srn = atoi(token); // Assuming SRN is the first column in the CSV file

        if (student.srn == SRN) {
            // Parse the rest of the student data
            token = strtok(NULL, ",");
            strcpy(student.name, token);

            for (int i = 0; i < 6; i++) {
                student.isa1[i] = atoi(strtok(NULL, ","));
            }
            for (int i = 0; i < 6; i++) {
                student.isa2[i] = atoi(strtok(NULL, ","));
            }
            for (int i = 0; i < 6; i++) {
                student.isa3[i] = atoi(strtok(NULL, ","));
            }

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        print_student_data(student);
    } else {
        printf("Student with SRN %d not found.\n", SRN);
    }
}

void append_student() {
    FILE *fp = fopen("MARKS.csv", "a"); // Open in append mode
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    printf("Enter SRN: ");
    scanf("%d", &student.srn);
    printf("Enter Name: ");
    scanf("%s", student.name);

    printf("Enter ISA1 marks (Physics, Electrical, CS, EVS, Maths, Mechanical): ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &student.isa1[i]);
    }

    printf("Enter ISA2 marks (Physics, Electrical, CS, EVS, Maths, Mechanical): ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &student.isa2[i]);
    }

    printf("Enter ISA3 marks (Physics, Electrical, CS, EVS, Maths, Mechanical): ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &student.isa3[i]);
    }

    // Write to file
    fprintf(fp, "%d,%s", student.srn, student.name);
    for (int i = 0; i < 6; i++) {
        fprintf(fp, ",%d", student.isa1[i]);
    }
    for (int i = 0; i < 6; i++) {
        fprintf(fp, ",%d", student.isa2[i]);
    }
    for (int i = 0; i < 6; i++) {
        fprintf(fp, ",%d", student.isa3[i]);
    }
    fprintf(fp, "\n");

    fclose(fp);
    printf("Student information appended successfully.\n");
}

int main() {
    int choice;
    int SRN;

    printf("Enter 1 to search for a student, 2 to append a new student: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter your SRN:\n");
        scanf("%d", &SRN);
        search_student(SRN);
    } else if (choice == 2) {
        append_student();
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

