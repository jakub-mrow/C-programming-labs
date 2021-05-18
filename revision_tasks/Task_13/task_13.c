#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 50
#define M 50
#define K 50

struct Student{
    char surname[30];
    char name[20];
    int index_number;
}students[N];

struct programming{
    int index_number;
    int grade;
}prog[M];

int main(){
    FILE *file;

    file = fopen("Studenci.txt", "r");
    if (file == NULL){
        return 1;
    }

    char buffer[200];
    fgets(buffer, 200, file);

    int i = 0;
    while(!feof(file)){
        struct Student *stud = students + i;
        sscanf(buffer, "%s %s %d", stud->surname, stud->name, &stud->index_number);
        fgets(buffer, 200, file);
        i++;
    }
    int count = i;
    for(int i = 0; i<count; i++){
        printf("%s %s %d \n", students[i].surname, students[i].name, students[i].index_number);
    }
    fclose(file);

    FILE *programming_file;
    programming_file = fopen("Programming.txt", "rt");
    if (programming_file == NULL){
        return 1;
    }
    int j = 0;
    while(!feof(programming_file)){
        fscanf(programming_file, "%d %d", &prog[j].index_number, &prog[j].grade);
        j++;
    }
    int num = j;
    for(int i = 0; i<num;i++){
        printf("%d %d\n", prog[i].index_number, prog[i].grade);
    }

    fclose(programming_file);

    return 0;
}
