#include <stdio.h>

int sum_of_digits(int num){
    if(num == 0)
        return 0;
    return ((num % 10) + sum_of_digits(num/10));
}

int main(){
    int num, sum;
    printf("Prosze podac liczbe: \n");
    scanf("%d", &num);

    sum = sum_of_digits(num);
    printf("Suma wszystkich cyfr wynosi: %d", sum);
    
    return 0;
}