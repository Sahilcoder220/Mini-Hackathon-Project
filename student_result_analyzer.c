#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade[3];
    int pass;
};

struct Student s[100];
int n = 0;

void inputStudents() {
    int i, j;
    
    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of students!\n");
        n = 0;
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf(" %49[^\n]", s[i].name);

        s[i].total = 0;
        s[i].pass = 1;

        for (j = 0; j < 5; j++) {
            do {
                printf("Enter marks of Subject %d: ", j + 1);
                scanf("%d", &s[i].marks[j]);

                if (s[i].marks[j] < 0 || s[i].marks[j] > 100) {
                    printf("Invalid marks! Enter 0 to 100.\n");
                }
            } while (s[i].marks[j] < 0 ||
                     s[i].marks[j] > 100);

            s[i].total += s[i].marks[j];

            if (s[i].marks[j] < 35) {
                s[i].pass = 0;
            }
        }

        s[i].percentage = s[i].total / 5.0;

        if (s[i].pass == 0) {
            s[i].grade[0] = 'F';
            s[i].grade[1] = '\0';
        }
        else if (s[i].percentage >= 90) {
            s[i].grade[0] = 'A';
            s[i].grade[1] = '+';
            s[i].grade[2] = '\0';
        }
        else if (s[i].percentage >= 80) {
            s[i].grade[0] = 'A';
            s[i].grade[1] = '\0';
        }
        else if (s[i].percentage >= 70) {
            s[i].grade[0] = 'B';
            s[i].grade[1] = '\0';
        }
        else if (s[i].percentage >= 60) {
            s[i].grade[0] = 'C';
            s[i].grade[1] = '\0';
        }
        else if (s[i].percentage >= 50) {
            s[i].grade[0] = 'D';
            s[i].grade[1] = '\0';
        }
        else {
            s[i].grade[0] = 'E';
            s[i].grade[1] = '\0';
        }
    }

    printf("\nStudent data entered successfully!\n");
}

void displayResults() {
    int i;

    if (n == 0) {
        printf("\nPlease enter student details first!\n");
        return;
    }

    printf("\n========== STUDENT RESULTS ==========\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Marks: %d/500", s[i].total);
        printf("\nPercentage: %.2f%%", s[i].percentage);
        printf("\nGrade: %s", s[i].grade);

        if (s[i].pass == 1) {
            printf("\nResult: PASS\n");
        }
        else {
            printf("\nResult: FAIL\n");
        }
    }
}

void classReport() {
    int i, topper = -1;
    int passed = 0, failed = 0;
    float sum = 0, average;

    if (n == 0) {
        printf("\nPlease enter student details first!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        sum += s[i].percentage;

        if (s[i].pass == 1) {
            passed++;

            if (topper == -1 ||
                s[i].total > s[topper].total) {
                topper = i;
            }
        }
        else {
            failed++;
        }
    }

    average = sum / n;

    printf("\n========== CLASS REPORT ==========\n");
    printf("\nTotal Students: %d", n);
    printf("\nPassed Students: %d", passed);
    printf("\nFailed Students: %d", failed);
    printf("\nClass Average: %.2f%%", average);
    printf("\nPass Percentage: %.2f%%",
           passed * 100.0 / n);

    if (topper != -1) {
        printf("\n\nClass Topper: %s", s[topper].name);
        printf("\nRoll Number: %d", s[topper].roll);
        printf("\nTotal Marks: %d/500", s[topper].total);
        printf("\nPercentage: %.2f%%\n",
               s[topper].percentage);
    }
    else {
        printf("\nNo student passed all subjects.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n\n===== STUDENT RESULT ANALYZER =====\n");
        printf("1. Enter Student Details\n");
        printf("2. Display Student Results\n");
        printf("3. Display Class Report\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {
            case 1:
                inputStudents();
                break;

            case 2:
                displayResults();
                break;

            case 3:
                classReport();
                break;

            case 4:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
