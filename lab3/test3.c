#include<stdio.h.>
void bit(int arr[], int b){
        //���� � ����� ��������� //������ ������
        int i=1;
        for (int j = 0; j < b; j++){ //������ �������
            printf("[%d][%d]:",i,j);
             scanf("%d", &arr[j]);
            }
}
int main(){
        int a , b, c, d, flag ; //���-�� ����� � ��������
    printf("Vedite chislo ctrok:");
    scanf("%d",&a);
    printf("Vedite chislo stolbcov:");
    scanf("%d",&b);

    int arr[b];
    bit(arr,b);

        printf("\n ");
        for (int j = 0; j < b; j++){ //������ �������
            printf("%d ", arr[j]);
            }
    return 0;
}
