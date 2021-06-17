#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    file = fopen("in_10.txt", "rt");
    if (file == NULL)
        return 0;

    char c;
    int lines;
    while(!feof(file)){
        c = fgetc(file);
        if (c == '\n'){
            ++lines;
        }
    }
    ++lines;
    fseek(file, 0, SEEK_SET);

    int tab[lines][3];
    int temp;
    int i=0,j=0;
    char ch;
    while(fscanf(file, "%d", &temp)==1){
        tab[i][j] = temp;
        fscanf(file, "%c", &ch);
        if (ch=='\n'){
            ++i;
            j=0;
        }
        else{
            j++;
        }
    }

    FILE *out;
    out = fopen("out_task_10.txt", "w");

    int sum;
    for(int i=0;i<lines;i++){
        sum = 0;
        for(int j=0;j<3;j++){
            sum += tab[i][j];
            fprintf(out, "|%d", tab[i][j]);
        }
        fprintf(out, "| %d\n", sum);
    }
    fclose(file);
    fclose(out);
}