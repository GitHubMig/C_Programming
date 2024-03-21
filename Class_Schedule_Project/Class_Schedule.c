#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int start_time;
} Class;

Class schedule[10];
int class_count = 0;

void add_class() {
    if (class_count >= 10) {
        printf("Cannot add more classes. Maximum of 10 classes reached.\n");
        return;
    }

    Class new_class;
    printf("Enter class name: ");
    scanf("%s", new_class.name);
    printf("Enter class start time (0700 to 2100): ");
    scanf("%d", &new_class.start_time);

    if (new_class.start_time < 700 || new_class.start_time > 2100) {
        printf("Invalid start time. Class not added.\n");
        return;
    }

    for (int i = 0; i < class_count; i++) {
        if (schedule[i].start_time == new_class.start_time) {
            printf("Time slot already occupied. Class not added.\n");
            return;
        }
    }

    schedule[class_count++] = new_class;
    printf("Class added successfully.\n");
}

void remove_class() {
    if (class_count == 0) {
        printf("No classes to remove.\n");
        return;
    }

    int class_no;
    printf("Enter class number to remove: ");
    scanf("%d", &class_no);

    if (class_no < 1 || class_no > class_count) {
        printf("Invalid class number.\n");
        return;
    }

    for (int i = class_no - 1; i < class_count - 1; i++) {
        schedule[i] = schedule[i + 1];
    }

    class_count--;
    printf("Class removed successfully.\n");
}

void view_schedule() {
    if (class_count == 0) {
        printf("No classes to view.\n");
        return;
    }

    printf("No. | Class Time Slot | Class Name\n");
    for (int i = 0; i < class_count; i++) {
        printf("%d   |   %04d - %04d   | %s\n", i + 1, schedule[i].start_time, schedule[i].start_time + 100, schedule[i].name);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Class\n2. Remove Class\n3. View Class Schedule\n4. Exit Program\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_class();
                break;
            case 2:
                remove_class();
                break;
            case 3:
                view_schedule();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
