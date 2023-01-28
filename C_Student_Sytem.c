// Written by EMİN AYYILDIZ
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_STUDENTS 100

void add_student(void);
void add_student(void);
void display_student(void);
void delete_student(void);
void calculate_average(void);

struct student {
    char name[50];
    int school_number;
    float grades[3];
    char letter_grade[5];
};

struct student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("The string is full. Please delete student first.\n");
        return;
    }

    printf("Student Name: ");
    scanf(" %[^\n]s", students[student_count].name);
    printf("School Number: ");
    scanf("%d", &students[student_count].school_number);
    printf("Grades: ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &students[student_count].grades[i]);
    }
    student_count++;
}

void delete_student() {
    if (student_count == 0) {
        printf("Listede öğrenci yok.\n");
    }
    else{
        int school_number;
        printf("Enter the school number of the student to be deleted: ");
        scanf("%d", &school_number);
        
        for (int i = 0; i < student_count; i++) {
            if (students[i].school_number == school_number) {
                for (int j = i; j < student_count - 1; j++) {
                    students[j] = students[j + 1];
                }
                student_count--;
                printf("The student named %s is deleted from the list.... Please wait.\n",students[student_count].name);
                sleep(2);
                printf("Student deleted.\n");
                return;
            }
        }
        
        printf("Student not found.\n");
    }
}
void display_student() {
    if (student_count == 0) {
        printf("Student not found.\n");
    }
    else {
        printf("All Students are listed... Please wait. \n");
        sleep(2);
        for (int i = 0; i < student_count; i++) {
            float sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += students[i].grades[j];
            }
            float average = sum / 3;
            printf("Student Name : %s\nSchool Number: %d\nGrades: ", students[i].name, students[i].school_number);
            for (int j = 0; j < 3; j++) {
                printf("%.2f ", students[i].grades[j]);
            }
            printf("\nAverage: %.2f\n", average);
            char letter_grade[3];
            if (average >=85)
            {
                strcpy(letter_grade, "AA");
            }
            else if (average >=70)
            {
                strcpy(letter_grade, "BA");
            }
            else if (average >=55)
            {
                strcpy(letter_grade, "BB");
            }
            else if (average >=40)
            {
                strcpy(letter_grade, "CB");
            }
            else
            {
                strcpy(letter_grade, "CC");
            }
            printf("Letter Grade: %s\n", letter_grade);
            printf("**********\n");
            
        }
    }
    sleep(2);
}

int main(void) {
    int choice;
    while (1) {
        printf("****WELCOME****\n");
        printf("MENU\n");
        printf("1. Add Student\n");
        printf("2. Display all Student\n");
        printf("3. Delete Student\n");
        printf("4. EXIT\n");
        printf("-------> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_student();
                break;
            case 3:
                delete_student();
                break;

            case 4:
                printf("Exiting... Please wait...\n");
                sleep(1.5);
                printf("BYE BYE\n");
                return 0;
            default:
                printf("ınvalid chosen...\n");
        }
    }
    return 0;
}
