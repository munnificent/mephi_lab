 #include <stdio.h>
 #include <stdlib.h>
 #define N 1000
int cmp(const void *b, const void *a) {
     return *(int*)a - *(int*)b;
 }
 int main() {
    int n, i,j;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(i = 0 ; i < n; i++) { // ������ ����
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp ); // ���������
    for(i = 0 ; i < n; i++) { // ������� ���������
        printf("%d ", arr[i]);
    }
    return 0;
 }
