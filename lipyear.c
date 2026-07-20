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

