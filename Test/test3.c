#include<stdio.h.>
int bit(int a){
    int q=0, fin=0;
    while(a!=0){
        q=a%10;
        fin+=q;
        a/=10;
    }
    return fin;
}
int main(){
        int a , b, c, d, flag ; //���-�� ����� � ��������
    printf("Vedite chislo ctrok:");
    scanf("%d",&a);
    printf("Vedite chislo stolbcov:");
    scanf("%d",&b);
    a=2;
    b=5;

    int arr[2][5];

    //���� � ����� ���������
    for (int i = 0; i < a; i++){ //������ ������
        for (int j = 0; j < b; j++){ //������ �������
            printf("[%d][%d]:",i,j);
            scanf("%d", &arr[i][j]);
            }
    }

   arr[1][1]=arr[1][2];



    for (int i = 0; i <= a; i++){ //������ �����
        printf("\n| ");
        for (int j = 0; j < b; j++){ //������ �������
            printf("%d ", arr[i][j]);
            if(j == b-1){
                printf(" |");
            }
        }

    }
    return 0;
}
