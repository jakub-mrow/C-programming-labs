#include<stdio.h>
#include<string.h>

int check(int num, int a){
    int square = num * num;
    while(num > a){
        if (num % 10 != square % 10)
            return 0;
        num = num / 10;
        square = square / 10;
    }
    return 1;

}


int main(){
    char liczba[100];
    int a,b;
    printf("Prosze wpisac wartosci graniczne przedzialu: \n");
    scanf("%d%d",&a,&b);

    for(int i=a;a<b;i++){
        if (i*i <= b)
            printf("%d%d\n", i, i*i);
    }

    return 0;
}