#include<stdio.h>
#include"saless.h"

int samles(int a, int b){ // проверка на схожесть
    int clone,flag=1,num1,num2;
  while (a!=0){
    if(flag == 1){
    num1=a%10;
    printf("q %d\n",num1);
    clone=b;
    printf("%d\n",clone);
    while (clone!=0){
      num2=clone%10;
      clone/=10;
      printf("w %d\n",num2);
      if(num1==num2){
        flag=1;
        printf("der 1\n");
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
}
