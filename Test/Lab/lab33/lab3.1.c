#include<stdio.h>

int samles(int a, int b){ // �������� �� ��������
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

int main(){
    int a, k, b, c, d, flag ; //���-�� ����� � ��������
    printf("Vedite chislo ctrok:");
    scanf("%d",&a);
    printf("Vedite chislo stolbcov:");
    scanf("%d",&b);

    int arr[b];
    int arr1[b];

    //���� � ����� ���������
    //������ ������
        for (int j = 0; j < b; j++){ //������ �������
            printf("[%d]:",j);
            scanf("%d", &arr[j]);
            }

        for (int j = 0; j < b; j++){
                c = arr[j];
                    for (int x = 0; x < b; x++){
                            d = arr[x];

                            flag = samles(c,d);
                            if(flag == 1){
                                arr1[k]=arr[j];
                                k++;
                            }
                            else{
                                break;
                            }
                    }
                }



    /*������ �������
    for (int i = 0; i < a; i++){ //������ �����*/
        printf("\n new mass \t ");
        for (int j = 0; j < k; j++){ //������ �������
            printf("%d ", arr1[j]);
            }
        return 0;


}
