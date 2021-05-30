#include <stdio.h>
#include <stdlib.h>
#define MAX 10

double average(double m1, double m2, double m3, double m4);
double smallest(double m1, double m2, double m3, double m4);
double biggest(double m1, double m2, double m3, double m4);

struct data{
    int num_series;
    double measure1;
    double measure2;
    double measure3;
    double measure4;
    int code;
};

int main(){
    FILE *in;
    FILE *out;
    in = fopen("Pomiary.txt", "rt");
    out = fopen("Wyniki.txt", "w");

    double (*choose[])(double, double, double, double) = {average,biggest,smallest};

    while(!feof(in)){
        double ret;
        struct data d1;
        fscanf(in,"%d %lf %lf %lf %lf %d", &d1.num_series, &d1.measure1,&d1.measure2,&d1.measure3,&d1.measure4,&d1.code);
        ret = (*choose[d1.code])(d1.measure1,d1.measure2,d1.measure3,d1.measure4);
        fprintf(out, "%d %0.2lf %d\n", d1.num_series,ret, d1.code);
    }
    fclose(in);
    fclose(out);

    return 0;
}

double average(double m1, double m2, double m3, double m4){
    double ret;
    ret = (m1+m2+m3+m4)/4;
    return ret;
}
double smallest(double m1, double m2, double m3, double m4){
    double min = 999999999;
    double tab[] = {m1,m2,m3,m4};
    for(int i=0;i<4;i++){
        if (tab[i] < min)
            min = tab[i];
    }
    return min;
}
double biggest(double m1, double m2, double m3, double m4){
    double max = -999999999;
    double tab[] = {m1,m2,m3,m4};
    for(int i=0;i<4;i++){
        if (tab[i] > max)
            max = tab[i];
    }
    return max;
}

