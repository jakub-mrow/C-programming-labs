#include <stdio.h>

int main(){
    int count = 0;
    char c;
    char check;
    FILE *file;

    printf("Jaki znak wyszukac? \n");
    scanf("%c", &check);

    file = fopen("text.txt", "r");

    while ((c = fgetc(file)) != EOF){
        if (check == c)
            count++;
    }
    fclose(file);
    printf("%d", count);

    return 0;
}