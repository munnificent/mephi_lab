#include<stdio.h>
void add(int*pa, int*pb, int*pc){
	*pa= *pa-*pc;
	*pb= *pb+*pc;
	printf("a=%d \t b=%d\n",*pa,*pb);
}
int main(){
	int a,b,c=10;
	scanf("%d %d",&a,&b);
	printf("a=%d \t b=%d\n",a,b);
	add(&a,&b,&c);
	printf("a=%d \tb=%d",a,b);
	return 0;
}
