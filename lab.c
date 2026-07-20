#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct Student students[5];
    struct Student readStudents[5];
    FILE *file;
    int i;

    printf("--- Enter Information for 5 Students ---\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%49s", students[i].name);   
        printf("Marks: ");
        scanf("%f", &students[i].marks);

        printf("\n");
    }

    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    for (i = 0; i < 5; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name,
                students[i].marks);
    }
    fclose(file);

    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    for (i = 0; i < 5; i++) {
        int result = fscanf(file, "%d %49s %f", &readStudents[i].id,
                             readStudents[i].name, &readStudents[i].marks);
        if (result != 3) {
            printf("Warning: Error reading record %d from file!\n", i + 1);
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    printf("\n--- Student Records from File ---\n");
    printf("------------------------------------------\n");
    printf("%-10s %-20s %-10s\n", "ID", "Name", "Marks");
    printf("------------------------------------------\n");
    for (i = 0; i < 5; i++) {
        printf("%-10d %-20s %-10.2f\n", readStudents[i].id,
               readStudents[i].name, readStudents[i].marks);
    }
    printf("------------------------------------------\n");

    return 0;
}