#include<stdio.h>

int main(){
    int a , b ; //���-�� ����� � ��������
    printf("Vedite chislo ctrok:");
    scanf("%d",&a);
    printf("Vedite chislo stolbcov:");
    scanf("%d",&b);
    int arr[a][b];
    for (int i = 0; i < a; i++){ //������ ������
        for (int j = 0; j < b; j++){ //������ �������
            printf("[%d][%d]:",i,j);
            scanf("%d", &arr[i][j]);
            }
    }
    for (int i = 0; i < a; i++){ //������ �����
        printf("\n");
        for (int j = 0; j < b; j++) //������ �������
            printf("%d ", arr[i][j]);

    }
}
