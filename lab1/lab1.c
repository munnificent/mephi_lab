#include<stdio.h>
int invert(int n){
 int r,k;
 while(n!=0){
    	r*=10;
	k= n%10;
        r+=k;
       n/=10;
  }
  return r;
}
int drob(int n, int b) {

      int r= 0, k=0;

      while(n!=0) {

        r=r*10;

        k=n%10;
	k +=b;
	k%=10;

        r=r+k;

        n=n/10;

      }
      r = invert(r);

      return r;

    }
int main() {
 int n,m;
 scanf("%ld/n", &n );
 scanf("%d/n", &m);
 n = drob(n, m);
 printf("%d",n);
 return 0;
}
