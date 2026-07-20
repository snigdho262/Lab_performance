// leap year
#include<stdio.h>
int main(){
    int year;
    printf("Enter a year: ");
    scanf("%d" , &year);
    if(year%400 == 0 || (year%4 == 0 && year%100 != 0)){
        printf("leap year");
    } else{
        printf("not leap year");
    }

    return 0;
}

// Revarce number
#include<stdio.h>
int main(){
    int num, dig, rev = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num>0){
        for(int i = num; i!=0; i = i/10){
            dig = i%10;
            rev = rev*10 + dig;
        }
        printf("Reverse number = %d", rev);
    } else{
        printf("Error");
    }

    return 0;
}


// function
#include <stdio.h>

long long factorial(int n) {
    long long result = 1;
    int i = 1;

    while (i <= n) {
        result = result * i;
        i = i + 1;
    }

    return result;
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
    } else {
        long long ans = factorial(n);
        printf("Factorial = %lld\n", ans);
    }

    return 0;
}

// file
#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct Student list[5];
    int i;

    // ---- Take input for 5 students ----
    i = 0;
    while (i < 5) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &list[i].id);

        printf("Enter Name: ");
        scanf("%s", list[i].name);

        printf("Enter Marks: ");
        scanf("%f", &list[i].marks);

        i = i + 1;
    }

    FILE *fp = fopen("students.txt", "w");

    i = 0;
    while (i < 5) {
        fprintf(fp, "%d %s %.2f\n", list[i].id, list[i].name, list[i].marks);
        i = i + 1;
    }

    fclose(fp);

    // ---- Read all students back from file ----
    FILE *fp2 = fopen("students.txt", "r");

    i = 0;
    while (i < 5) {
        fscanf(fp2, "%d %s %f", &list[i].id, list[i].name, &list[i].marks);
        i = i + 1;
    }

    fclose(fp2);

    // ---- Display as a table ----
    printf("\nID\tName\tMarks\n");
    printf("--------------------\n");

    i = 0;
    while (i < 5) {
        printf("%d\t%s\t%.2f\n", list[i].id, list[i].name, list[i].marks);
        i = i + 1;
    }

    return 0;
}
