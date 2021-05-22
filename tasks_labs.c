#include <stdio.h>

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
        for(j=1;j<=m;j++){
        }
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
    printf("%lf", S);    

   return 0;
}