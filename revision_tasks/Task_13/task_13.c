#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 50
#define M 50
#define K 50

void n_func(int num_of_stud, int num_of_prog, int num_of_py);
void a_func(int num_of_stud, int num_of_prog, int num_of_py);
struct Student{
    char surname[30];
    char name[20];
    int index_number;
}students[N];

struct programming{
    int index_number;
    int grade;
}prog[M];

struct physics{
    int index_number;
    int grade;
} py[K];

int main(){
    // Get data from students file
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

    // Get data from programming grades file
    FILE *programming_file;
    programming_file = fopen("Programming.txt", "rt");
    if (programming_file == NULL){
        return 1;
    }
    int prog_count = 0;
    while(!feof(programming_file)){
        fscanf(programming_file, "%d %d", &prog[prog_count].index_number, &prog[prog_count].grade);
        prog_count++;
    }
    int num = prog_count;
    for(int i = 0; i<num;i++){
        printf("%d %d\n", prog[i].index_number, prog[i].grade);
    }
    fclose(programming_file);

    // Get data from Physics grades file
    FILE *physics_file;
    physics_file = fopen("Fizyka.txt", "r");
    if (physics_file==NULL){
        return 1;
    }
    int py_count = 0;
    while(!feof(physics_file)){
        fscanf(physics_file, "%d %d", &py[py_count].index_number, &py[py_count].grade);
        py_count++;
    }

    //main loop with options
    bool check = true;
    while(check){
        char c;
        printf("Prosze wybrac operacje\n");
        printf("N - wyprowadzenie ocen z programowania i fizyki na podstawie Nazwiska\nA - wyprowadzenie ocen z programowania i fizyki na podstawie nr albumu\nQ - koniec programu\n");
        scanf("    %c", &c);
        switch(c & 0x5F){
            case 'N': 
                n_func(count, prog_count, py_count);
                break;
            case 'A':
                a_func(count, prog_count, py_count);
                break;
            case 'Q':
                check = false;
                break;
            default:
                printf("Wprowadzono zla opcje!\n");
        }
    }

    return 0;
}

void n_func(int num_of_stud, int num_of_prog, int num_of_py){
    char surn[30];
    int index;
    printf("Prosze podac nazwisko studenta\n");
    scanf("%s", surn);
    for(int i = 0;i<num_of_stud;i++){
        int value = strcmp(students[i].surname, surn);
        if (value == 0){
            printf("Student:\n");
            printf("%s %s\n", students[i].name, students[i].surname);
            index = students[i].index_number;
        }
    }
    for(int i = 0; i<num_of_prog;i++){
        if (index == prog[i].index_number){
            printf("Ocena z programowania: %d\n", prog[i].grade);
        }
    }
    for(int i = 0; i < num_of_py; i++){
        if (index == py[i].index_number){
            printf("Ocena z fizyki: %d\n", py[i].grade);
        }
    }
}

void a_func(int num_of_stud, int num_of_prog, int num_of_py){
    int id;
    printf("Prosze podac numer indeksu\n");
    scanf("%d", &id);

    for(int i = 0; i < num_of_stud; i++){
        if (id == students[i].index_number){
            printf("Student:\n");
            printf("%s %s\n", students[i].name, students[i].surname);
        }
    }
    for(int i = 0;i < num_of_prog; i++){
        if (id == prog[i].index_number){
            printf("Ocena z programowania: %d\n", prog[i].grade);
        }
    }
    for(int i = 0; i < num_of_py; i++){
        if (id == py[i].index_number){
            printf("Ocena z fizyki: %d\n", py[i].grade);
        }
    }
}