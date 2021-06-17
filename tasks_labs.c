#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void simple_tower(){
    // Zadanie 7.1.2
    printf("Zad 7.1.2\n");
    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=i;++j){
            printf("O");
        }
        printf("\n");
    }
}
void print_triangle(){
    // Zadanie 7.1.7
   printf("Zad 7.1.7\n");
   int i, space,k = 0, rows;
   printf("Prosze podac ilosc rzedow: \n");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i, k = 0) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("X ");
         ++k;
      }
      printf("\n");
   }
}

double sum(double a, int n){
    int i;
    double S = 0;
    for(i=1;i<=n;i++){
        S += (a*(i*i*i) - 7) / (i*i+1);
    }
    return S;
}

double sum_2(int n, int m){
    double mul;
    double R;
    int i,j;
    for(i=1;i<=n;i++){
        mul=1;
        for(j=1;j<=m;j++){
            mul*=(pow(i,2)+pow(j,2)-1)/(2*i+3*j+4);
        }
        R += mul;
    }
    return R;
}

int main(){
    // Zadanie 7.1.2
    simple_tower();

    //Zadanie 7.1.7
    print_triangle();

    //Zestaw Zadań 3 zadanie 1
    double S = sum(1,2);
    printf("%lf\n", S);
    double S_2 = sum_2(5,8);
    printf("%lf ", S_2);    

   return 0;
}