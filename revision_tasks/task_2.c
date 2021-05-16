#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double** calc(double **ret, int n, int m);
void print_matrix(double **tab, int n, int m);

int main(){
    int n,m;
    int i,j;
    int o;
    int row,col;
    double **tab;
    double **ret;

    printf("Prosze podac rozmiary macierzy: n x m\n");
    scanf("%d%d", &n,&m);
 
    //allocate memory for matrix
    tab = malloc(n * sizeof(double*));
    for(o=0;o<n;o++){
        tab[o] = malloc(m * sizeof(double));
    }

    printf("Prosze podac elementy macierzy\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%lf", &tab[i][j]);
        }
    }

    print_matrix(tab, n,m);
    ret = calc(tab,n,m);
    print_matrix(ret,n,m);

    return 0;
}

void print_matrix(double **tab, int n, int m){
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%0.2lf ", tab[i][j]);
        }
        printf("\n");
    }
}
double** calc(double **tab, int n, int m){
    double **ret;
    int i,j,l;
    double a;

    ret = malloc(n * sizeof(*ret));
    for(l=0;l<n;l++){
        ret[l] = malloc(m * sizeof(*ret[l]));
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            a = tab[i][j];
            if (a == -1)
                ret[i][j] = 3.31;
            else
                ret[i][j] = (sin(a) * sin(a)-3)/(sqrt(a+1));
        }
    }

    return ret;
}