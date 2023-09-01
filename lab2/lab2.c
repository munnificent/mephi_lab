#include<stdio.h>
#include <math.h>

long lenth(double num){
    long i = -1;
    while(num<=1){
        num*=10;
        i++;
    }
    return i;

}

long long period(long long  num){
    long long clone = 1;
    for(int i = 1; i <= num; i++){
        clone*=i;
    }
    return clone;
}

long long power(long long top, long long num){
    long long i = 0, clone = 1;
    while(i != top){
        clone *= num;
        i++;
    }
    return clone;
}

double glava(long long n, double rad){
    long long first=0,  per=0;
    double sinkay= 0 , second= 0, fin = 1, third= 0;
    rad = (rad * M_PI)/180;
    for(int i = 1; i <= n; i++){
        first = power(i, i);
        per = period(i);
        second = i * rad;
        sinkay = cos(second);
        third = (first * sinkay) / per;
        fin += third;
    }
    return fin;


}

int main(){
    long road, n=0 ;
    double fin=0 ;
    long long rad=0;
    double len=0;
    printf("Vedite chislo okruglenia \t");
    scanf("%lf",&len);
    printf("Vedite chislo prohodov \t");
    scanf("%lld",&n);
    printf("Vedite  ugol \t");
    scanf("%lld",&rad);
    fin = glava(n, rad);
    road = lenth(len);
    printf("Len2 %ld\n", road);
    printf("%.*lf",road, fin);
    return 0;

}
