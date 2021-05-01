#include <stdio.h>


void check(int num, int b){
    int sqr,t=0;
    sqr = num*num;
    int copy_num = num;
    int copy_sqr = sqr;
    while(num > 0){
        if(num%10!=sqr%10){
            t = 1;
            break;
        }
        num = num/10;
        sqr = sqr/10;
    }
    if ((t == 0) && (copy_sqr <= b)){
        printf("%d %d\n", copy_num, copy_sqr);
    }
}

int main(){
    int a,b;
    printf("Prosze podac wartosci krancowe przedzialu: \n");
    scanf("%d %d",&a,&b);

    for(int i=a;i<b;i++){
        check(i,b);

    }

    return 0;
}