#ifndef LABER_H_INCLUDED
#define LABER_H_INCLUDED

void restart(int *capacity, int *fin, int **arr, int **arr1);
void dup(int ***arr, int **listLength);
void sorter(int ***list, int **listLength);
void del(int ***list, int i, int **listLength);
int len(int a);
void print_menu1();
void print_menu2();
int get_variant(int count);
void add_arr(int *capacity,int **arr);
void del_num(int *capacity, int **arr);
void add_num(int capacity, int **arr);
void print_arr(int capacity, int **arr);
int cmp(const void *b, const void *a);
void make_test(int capacity, int *fin, int **arr, int **arr1);
int samles(int a, int b);

#endif // LABER_H_INCLUDED
