#include<stdio.h>

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
    int a, k, b, c, d, flag ; //���-�� ����� � ��������
    printf("Vedite chislo ctrok:");
    scanf("%d",&a);
    printf("Vedite chislo stolbcov:");
    scanf("%d",&b);

    int arr[a][b];
    int arr1[2*b];

    //���� � ����� ���������
    for (int i = 0; i < a; i++){ //������ ������
        for (int j = 0; j < b; j++){ //������ �������
            printf("[%d][%d]:",i,j);
            scanf("%d", &arr[i][j]);
            }
    }

    for (int i = 0; i < a; i++){ //������ ������
        for (int j = 0; j < b; j++){
                c = arr[i][j];
                c = bit(c);
                for (int z = 0; z < a; z++){ //������ ������
                    for (int x = 0; x < b; x++){
                            d = arr[z][x];
                            d = bit(d);
                            flag = c^d;
                            if(flag != 0){
                                arr1[k]=arr[z][x];
                                k++;
                            }
                    }
                }
        }
    }



    /*������ �������
    for (int i = 0; i < a; i++){ //������ �����
        printf("\n| ");*/
        for (int j = 0; j < k; j++){ //������ �������
            printf("%d ", arr1[j]);
            }
        return 0;


}
