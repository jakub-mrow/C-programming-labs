#include <stdio.h>
#include <string.h>
#define MAX 100

struct computer{
    char name[20];
    char producent[20];
    double price;
};

void add(struct computer *computers, int *count){
    if (*count < MAX){
        printf("Prosze podac nazwe komputera, nazwe producenta oraz cene: \n");
        scanf("%s%s%lf", &computers[*count].name, &computers[*count].producent, &computers[*count].price);
        *count += 1;
    }
}
void print_computers(struct computer *computers, int  *count){
    int i;
    for(i=0; i<*count; i++){
        printf("Nazwa: %s\n", computers[i].name);
        printf("Producent: %s\n", computers[i].producent);
        printf("Cena: %lf\n", computers[i].price);
    }
}
void search_computer(struct computer *computers, int *count, char name[20]){
    int i, value;
    for (i=0;i <*count; i++){
        value = strcmp(computers[i].name, name);
        if (value == 0){
            printf("Znaleziono komputer: %s\n", name);
            break;
        }
    }
}
void delete(struct computer *computers, int*count, char name[20]){
    int i, value;

}



int main(){
    struct computer computers[MAX];
    int count = 0;

    while(1){
        char c;
        char name[20];
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
            scanf("%s", name);
            search_computer(computers, &count, name);
        }
        else if((c == 'U') || (c == 'u')){
            
        }
        else if((c == 'Q') || (c == 'q'))
            break;     
    }
    return 0;
}


