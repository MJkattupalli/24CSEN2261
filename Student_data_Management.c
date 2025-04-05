#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent(struct Student students[], int *count) {
    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNo);
    printf("Enter student name: ");
    getchar(); // To clear the newline character
    fgets(students[*count].name, 50, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0'; // Removing the newline character
    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
}

void displayAllStudents(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nStudent #%d\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

int main() {
    struct Student students[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayAllStudents(students, count);
                break;
            case 3:
                printf("Exiting system.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
