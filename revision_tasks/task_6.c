#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **tab, int n, int m);
void calc_equal(int **a, int **b, int n, int m);
void calc_superior(int **a, int **b, int n, int m);

int main(){
    int **a;
    int **b;
    int n,m;

    printf("Prosze podac rozmiary macierzy: n x m\n");
    scanf("%d%d", &n,&m);
 
    //allocate memory for matrix
    a = malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        a[i] = malloc(m * sizeof(int));
    }

    b = malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        b[i] = malloc(m*sizeof(int));
    }

    printf("Prosze podac elementy macierzy A: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Prosze podac elementy macierzy B: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &b[i][j]);
        }
    }
    printf("Wpisana macierz A: \n");
    print_matrix(a,n,m);
    printf("Wpisana macierz B: \n");
    print_matrix(b,n,m);

    calc_equal(a,b,n,m);
    calc_superior(a,b,n,m);

    return 0;
}

void print_matrix(int **tab, int n, int m){
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void calc_equal(int **a, int **b, int n, int m){
    int **equal;
    equal = malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        equal[i] = malloc(m*sizeof(int));
    }

    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if (a[i][j] == b[i][j])
                equal[i][j] = 1;
            else
                equal[i][j] = 0;
        }
    }
    printf("Macierz rownosci: \n");
    print_matrix(equal, n, m);
}

void calc_superior(int **a, int **b, int n, int m){
    int **superior;
    superior = malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        superior[i] = malloc(m*sizeof(int));
    }

    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if (a[i][j] > b[i][j])
                superior[i][j] = 1;
            else
                superior[i][j] = 0;
        }
    }
    printf("Macierz rownosci: \n");
    print_matrix(superior, n, m);
}
