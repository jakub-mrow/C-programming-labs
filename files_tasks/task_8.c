#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f;
    f = fopen("input_task_8.txt", "rt");
    if (f == NULL)
        return 0;
    
    int columns = 0;
    int lines = 0;
    int c;

    int act = 0;
    char ch;  
    while(!feof(f)){
        ch = fgetc(f);
        if (ch == ' '){
            ++act;
            if (act > columns)
                columns = act;
        }
        else if (ch == '\n'){
            ++lines;
            act = 0;
        }
    }
    ++columns;
    ++lines;

    printf("%d %d\n", columns, lines);
    int tab[lines][columns];
    char check[lines][columns];

    for(int i = 0; i < lines; i++){
        for(int j = 0; j<columns; j++){
            tab[i][j] = 0;
        }
    }

    for(int i = 0; i < lines; i++){
        for(int j = 0; j<columns; j++){
            check[i][j] = 'u';
        }
    }

    fseek(f, 0, SEEK_SET);
    int x;
    int i = 0, j = 0;
    char t;
    
    while(fscanf(f,"%d", &x)==1){
        tab[i][j] = x;
        check[i][j] = 'x';
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

    for(int i = 0; i < lines; i++){
        for(int j = 0; j<columns; j++){
            printf("%c ", check[i][j]);
        }
        printf("\n");
    }

    printf("---------- Suma -----------\n");
    int sum;
    for(int i = 0; i < columns; i++){
        sum = 0;
        for(int j = 0; j < lines; j++){
            if (check[j][i] == 'x')
                sum = sum + tab[j][i];
        }
        printf("%d ", sum);
    }
    printf("\n");
    printf("--------- Srednia ---------\n");
    double sum_av;
    int count_lines;
    for(int i = 0; i < columns; i++){
        sum_av = 0;
        for(int j = 0; j < lines; j++){
            if (check[j][i] == 'x'){
                ++count_lines;
                sum_av = sum_av + tab[j][i];
            }
        }
        printf("%lf ", sum_av/count_lines);
        count_lines = 0;
    }
    
    fclose(f);
    return 0;
}
