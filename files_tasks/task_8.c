#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f;
    f = fopen("input_task_8.txt", "r");
    if (f == NULL)
        return 0;
    
    int columns = 0;
    int lines = 0;
    int c;
    
    int n = 0,akt=0;
    char r;
    fscanf (f, "%d", &n);
    while (fscanf(f,"%d",&n)==1){  
        ++akt;
        fscanf (f, "%c", &r);
        if(r=='\0')
            break;
        if(r=='\n'){
            ++lines;
            if(akt>columns){
                columns=akt;
                akt=0;
            }
        }   
    }
    
    printf("%d %d\n", columns, lines);
    int tab[lines][columns];


    for(int i = 0; i < lines; i++){
        for(int j = 0; j<columns; j++){
            tab[i][j] = 0;
        }
    }

    fseek(f, 0, SEEK_SET);
    int x;
    int i = 0, j = 0;
    char t;
    while(fscanf(f,"%d", &x)==1){
        tab[i][j] = x;
        fscanf(f, "%c", &t);
        if (t==' ')
            ++j;
        if (t=='\0')
            break;
        if (t=='\n'){
            ++i;
            j=0;
        }
    }

    for(int i = 0; i < lines; i++){
        for(int j = 0; j<columns; j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("---------- Suma -----------\n");
    int sum;
    for(int i = 0; i < lines; i++){
        sum = 0;
        for(int j = 0; j < columns; j++){
            sum = sum + tab[j][i];
        }
        printf("%d ", sum);
    }
    printf("\n");
    printf("---------- Srednia -----------\n");
    double sum_av;
    for(int i = 0; i < lines; i++){
        sum_av = 0;
        for(int j = 0; j < columns; j++){
            sum_av = sum_av + tab[j][i];
        }
        printf("%lf ", sum_av/lines);
    }


    fclose(f);
    return 0;
}
