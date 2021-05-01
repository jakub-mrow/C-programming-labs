#include <stdio.h>

void reverse_string(){
    char c;
    scanf("%c", &c);
    if (c!= '\n'){
        reverse_string();
        printf("%c", c);
    }
}

int main() {
    printf("Prosze podac ciag znakow: \n");
    reverse_string();
    return 0;
}