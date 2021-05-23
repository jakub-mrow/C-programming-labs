#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void perfect_numbers(){
    int a;
    printf("Prosze wprowadzic zakres wyszukiwania liczb doskonalych: \n");
    scanf("%d", &a);
    for(int i=1;i<=a;i++){
        int sum=0, tab[a], index=0;
        for(int j=1;j<i;j++){
            if (i%j == 0){
                sum+=j;
                tab[index++] = j;
            }        
        }
        if (sum == i){
            printf("%d\n", i);
            for(int k=0;k<index;k++){
                if (k== index-1)
                    printf("%d = %d\n", tab[k], i);
                else
                    printf("%d + ", tab[k]);
            }
        }
    }
}

void liczby_zaprzyjaznione(){
    int a;
    printf("Prosze wprowadzic zakres wyszukiwania liczb zaprzyjaznionych: \n");
    scanf("%d", &a);

    for(int i=1;i<=a;i++){
        int sum=0, tab[a], index=0;
        for(int j=1; j<i;j++){
            if (i%j == 0){
                sum+=j;
                tab[index++] = j;
            }
        }
        for(int k=1;k<i;k++){
            int sum2=0, tab2[a], index2=0;
            for(int l=1;l<k;l++){
                if (k%l == 0){
                    sum2+=l;
                    tab2[index2++] = l;
                }
            }
            if (sum2 == i && sum==k){
                printf("%d %d\n",i,k);
                for (int x=0;x<index;x++){
                    if (x==index-1)
                        printf("%d = %d", tab[x],k);
                    else
                        printf("%d + ", tab[x]);
                }
                printf("\n");
                for(int y=0;y<index2;y++){
                    if (y==index2-1)
                        printf("%d = %d", tab2[y],i);
                    else
                        printf("%d + ", tab2[y]);
                }
            }
        }
    }
}


int main(){
    //Zestaw Zadań 4

    perfect_numbers();
    liczby_zaprzyjaznione();

    return 0;
}