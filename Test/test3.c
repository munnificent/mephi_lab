#include <stdio.h.>
#include "saless.h"
#include <stdlib.h>
int cmp(const void *b, const void *a) {
     return *(int*)a - *(int*)b;
 }
int samles(int a, int b);

int len(int a){
    int i;
    for(i = 0; a != 0 ; i++)
        a/=10;
    return i;
}

int main(){
  int flag,k,a,b;
  int mass[7]={700,321.214,1,213,234,644,123};
  int mass1[7];
  qsort(mass, 7, sizeof(int), cmp );
  for(int i = 0; i <=7;i++){
    a = mass[i];
    for(int j=0;j<=7;j++){
        b=mass[j];
        printf("\n num %d \t %d \t",j,i);
        flag = samles(a,b);
        if(flag == 1){
                printf("\n %d \t %d \t %d",flag,a,b);
                mass1[k]=a;
                k++;
                break;
        }
        }
    }

  for(int i = 0; i <=k;i++){
        printf("[%d]",mass1[i]);
  }

  system("pause");
  return 0;
}

int samles(int a, int b){
    int temp,clone,flag=1,num1,num2;
  if(len(a)==len(b)){
  while (a!=0){
    if(flag == 1){
    num1=a%10; //123
    clone=b; //2
    while (clone!=0){
      num2=clone%10;
      clone/=10;
      if(num1==num2){
        flag=1;
        break;
      }
      else if(num1!=num2 && clone==0) {
        flag =-1;
        }
    }
    a/=10;
   }
   else {
     break;
   }
   }
   return flag;
} else{
    return 0;
}
}
