#include<stdio.h>
#include<stdlib.h>
int lnv(int n) {
			int r= 0, k=0;
			while(n!=0) {
				r=r*10;
				k=n%10;
				r=r+k;
				n=n/10;
			}
			return r;
		}
int pal(int n){
				int f =0,p=0;
				while(f==0){
					p=lnv(n);
					if (p==n){
						f=1;
					}
					else {
						n=n+p;


					}


				}
			}

int main() {
		int a;
		scanf("%d",&a);
		a = pal(a);
		printf("%d\n",a);
		system("pause");
		return 0;
}
	
		




		