#include <stdio.h.>
#include "saless.h"
#include <stdlib.h>

/*int samles(int a, int b){ // проверка на схожесть
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
}*/
int samles(int a, int b);
int main(){
  int flag, a, b;
  scanf("%d %d",&a,&b);
  flag= samles(a,b);
  printf("%d \t",flag);
  system("pause");
  return 0;
}




/*void bit(int arr[], int b){ // запись в массив
        //ввод в мссив элементов //проход строка
        int i=1;
        for (int j = 0; j < b; j++){ //проход столбец
            printf("[%d][%d]:",i,j);
             scanf("%d", &arr[j]);
            }
}
int main(){
        int a , b, c, d, flag ; //кол-во строк и столбцов
    printf("Vedite chislo ctrok:");
    scanf("%d",&a);
    printf("Vedite chislo stolbcov:");
    scanf("%d",&b);

    int arr[b];
    bit(arr,b);

        printf("\n ");
        for (int j = 0; j < b; j++){ //проход столбов
            printf("%d ", arr[j]);
            }
    return 0;
}
*/
