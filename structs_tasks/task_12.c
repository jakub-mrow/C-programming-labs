#include <stdio.h>
#include <string.h>
#define MAX 50
#include <windows.h>

struct ware{
    char name[20];
    int amount;
    int price;
};

void add(struct ware *list_of_wares, int *count){
    if (*count < MAX){
        printf("Prosze podac nazwe towaru, liczbe sztuk oraz cene za 1 sztuke: \n");
        scanf("%s%d%d", &list_of_wares[*count].name, &list_of_wares[*count].amount, &list_of_wares[*count].price);
        *count += 1;
    }
}

void print_wares(struct ware *list_of_wares, int *count){
    int i;

    for(i=0; i<*count; i++){
        printf("Nazwa: %s\n", list_of_wares[i].name);
        printf("Liczba sztuk: %d\n", list_of_wares[i].amount);
        printf("Cena za 1 sztuke: %d\n", list_of_wares[i].price);
        printf("-----------------------------------\n");
    }
}

void count_sum(struct ware *list_of_wares, int *count){
    int i, sum=0;
    for (i=0; i<*count; i++){
        sum += (list_of_wares[i].price * list_of_wares[i].amount);
    }
    printf("Suma wartosci wszystkich towarow: %d\n", sum);
}

int main(){
    struct ware list_of_wares[MAX];

    int count = 0;
    //int *wsk_count = &count;

    while(1){
        char c;
        printf("Prosze wybrac operacje: \n");
        printf("N | n  nowy towar \nW | w  wyswietl wszystkie towary \nR | r  oblicz sume wartosci wszystkich towarow \nQ | q  koniec programu\n");
        scanf("    %c", &c);

        if((c == 'n') || (c == 'N')){   
            add(list_of_wares, &count);
        }
        else if((c == 'W') || (c == 'w')){
            print_wares(list_of_wares, &count);
        }
        else if((c == 'R') || (c == 'r')){
            count_sum(list_of_wares, &count);
        }
        else if((c == 'Q') || (c == 'q'))
            break;     
    }


    return 0;
}