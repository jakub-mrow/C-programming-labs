#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

struct computer{
    char *name;
    char *producent;
    double price;
};

void add(struct computer **computers, int *count){
    int i;
    for(i = 0;i < MAX; i++){
        if (computers[i] == NULL){
            computers[i] = (struct computer*)malloc(sizeof(struct computer));
            char a[30], a2[30];
            printf("Prosze podac nazwe komputera, nazwe producenta oraz cene: \n");
            scanf("%s%s%lf", a, a2, &computers[*count]->price);
            computers[i]->name = (char*)malloc((strlen(a)+1)*sizeof(char));
            computers[i]->producent = (char*)malloc((strlen(a2)+1)*sizeof(char));
            strcpy(computers[i]->name, a);
            strcpy(computers[i]->producent, a2);
            *count += 1;
            break;
        }
    }
}
void print_computers(struct computer **computers, int  *count){
    int i, j;
    for(i = 0,j = 1;j <= *count && i < MAX; i++,j++){
        if (computers[i] == NULL){
            continue;
        }
        printf("%d. ------------------------------------\n", j);
        printf("Nazwa: %s\n", computers[i]->name);
        printf("Producent: %s\n", computers[i]->producent);
        printf("Cena: %0.2lf\n", computers[i]->price);
    }
}
void search_computer(struct computer **computers, int *count){
    int i, value;
    char name[30];
    printf("Jaki komputer wyszukac? \n");
    scanf("%s", name);
    for (i=0;i <*count; i++){
        if (computers[i] == NULL){
            continue;
        }
        value = strcmp(computers[i]->name, name);
        if (value == 0){
            printf("Znaleziono komputer: %s\n", name);
            break;
        }
    }
}
void delete(struct computer **computers, int*count){
    int i, value;
    char name[30];
    printf("Prosze podac nazwe komputera do usuniecia: \n");
    scanf("%s", name);
    for (i=0; i<MAX; i++){
        if (computers[i] == NULL)
            continue;
        value = strcmp(computers[i]->name, name);
        if (value == 0){
            free(computers[i]);
            computers[i] = NULL;
            printf("\n");
            *count -= 1;
            break;
        }
    }
}
int main(){
    struct computer *computers[MAX];
    int count = 0, i;

    for (i=0; i<MAX; i++){
        computers[i] = NULL;
    }
    while(1){
        char c;
        printf("Prosze wybrac operacje: \n");
        printf("N | n  nowy komputer \nW | w  wyswietl wszystkie komputery \nS | s  szukaj komputera wedlug nazwy \nQ | q  koniec programu\nU | u  usun komputer wedlug nazwy \n");
        scanf("    %c", &c);

        if((c == 'n') || (c == 'N')){   
            add(computers, &count);
        }
        else if((c == 'W') || (c == 'w')){
            print_computers(computers, &count);
        }
        else if((c == 'S') || (c == 's')){
            search_computer(computers, &count);
        }
        else if((c == 'U') || (c == 'u')){
            delete(computers, &count);
        }
        else if((c == 'Q') || (c == 'q'))
            break;     
    }
    return 0;
}


