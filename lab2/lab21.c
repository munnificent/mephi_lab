#include<stdio.h>
#include <math.h>


int lenth(double num){
    int i = -1;
    while(num<=1){
        num*=10;
        //printf("Len %lf\n", num);
        i++;
    }
    //printf("Len %d\n", i);
    return i;

}

double glava(int n, double rad){
    double fin= 0, sinkay = 0, power = 0, u=0;
    int i = 0;
    rad= (rad * M_PI)/180;
    //printf("%lf\n", rad);
    power = n*cos(rad);
    //printf("%lf\n", power);
    sinkay = n*sin(rad);
    //printf("%lf\n", sinkay);
    sinkay = cos(sinkay);
    //printf("%lf\n", sinkay);
    fin = exp(power);
    //printf("%lf\n", fin);
    fin*=sinkay;
    //printf("%.16lf\n", fin);
    return fin;

}


int main(){
    int road, n=0 ;
    double fin=0 ;
    int rad=0;
    double len=0;
    printf("Vedite chislo okruglenia \t");
    scanf("%lf",&len);
    printf("Vedite chislo prohodov \t");
    scanf("%d",&n);
    printf("Vedite  ugol \t");
    scanf("%d",&rad);
    fin = glava(n, rad);
    road = lenth(len);
    printf("Len2 %d\n", road);
    //fin = rounder(fin, len);
    printf("%.*lf",road, fin);
    //printf("%.15lf",fin);
    return 0;

}
