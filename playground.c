#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int)*4);

    *(p+0) = 44;
    *(p+1) = 55;
    *(p+2) = 66;
    *(p+3) = 77;
    printf("%p\n", p);
    printf("%p\n", p+1);
    
    int *tab, n = -1, tabl[3];

    printf("Podaj rozmiar tablicy: \n");
    scanf("%d", &n);

    tab = (int*) malloc (n*sizeof(int));
    printf("Podaj elementy tablicy: \n");
    for (int i=0; i<n; ++i) scanf("%d", (tab+i));
    for(int i=0; i<n; ++i) printf("tab[%d] = %d\n", i, *(tab+i));
    free(tab);


    return 0; 
}