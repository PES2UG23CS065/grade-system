#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades.h"

void student(int SRN) {
    const char *names[] = {"Kiara", "Taniya", "Rinna", "Akash", "Jhanvi"};
    
    if (SRN >= 1 && SRN <= 5) {
        printf("-------------------YOUR SCORES---------------\n");
        printf("%s\n", names[SRN - 1]); // Adjust index for array
        printf("SEM - 2\n");

        const char *branches[] = {"CSE", "CSE", "CSE", "EC", "EC"};
        printf("Branch - %s\n", branches[SRN - 1]);

        grade(SRN);
    } else {
        printf("No data available\n");
    }
}

int main() {
    int SRN;
    printf("Enter your SRN:\n");
    scanf("%d", &SRN);
    student(SRN);
    return 0;
}
