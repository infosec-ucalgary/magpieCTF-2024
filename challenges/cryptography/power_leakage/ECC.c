#include <stdio.h>
#include <math.h>
// ECC reference from <<An Introduction to Mathematical Cryptography>>

struct coord{
	long x;
	long y;
};

struct EC{
	// y^2=x^3+ax+b
	long a;
	long b;
	// prime field
	long p;
};
// modulo inverse reference from https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
int mod_inverse(int base, int mod){
	int x, y;
	int g=extended_euclidean(base, mod, &x, &y);
	if(g!=1)
		return -1;

	return (x%mod+mod)%mod;
}
int extended_euclidean(int a, int b, int* x, int* y){
	if(a==0){
		*x=0, *y=1;
		return b;
	}
	int x1, y1;
	int gcd=extended_euclidean(b%a, a, &x1, &y1);

	*x = y1-(b/a)*x1;
	*y = x1;

	return gcd;
}
// Getting a positive modulo
int mod(int base, int mod){
	return (mod+(base%mod))%mod;
}
struct coord add(struct coord P1, struct coord P2, struct EC curve){
	struct coord res;
	if(P1.x==P1.y&& P1.x==0){
		res.x=mod(P2.x,curve.p);
		res.y=mod(P2.y,curve.p);

	}else if(P2.x==P2.y && P2.x==0){
		res.x=mod(P1.x,curve.p);
		res.y=mod(P1.y,curve.p);

	}else if(P1.x==P2.x && P1.y==-P2.y){
		res.x=0;
		res.y=0;
	}else{
		long numerator, denominator;
		if(P1.x!=P2.x && P1.y!=P2.y){
			numerator=mod(P1.y-P2.y,curve.p);
			denominator=mod(P1.x-P2.x,curve.p);
		}else{
			numerator=mod(3*(P1.x)*(P1.x)+curve.a,curve.p);
			denominator=mod(2*P1.y,curve.p);
		}
		long s;
		s=mod(numerator*mod_inverse(denominator, curve.p),curve.p);
		res.x=mod(s*s-P1.x-P2.x,curve.p);
		res.y=mod(s*(P1.x-res.x)-P1.y,curve.p);
	}
	return res;
}
struct coord mul(struct coord P1, int n, struct EC curve){
	struct coord P2, r;
	P2.x=P1.x;
	P2.y=P1.y;
	r.x=0;
	r.y=0;
	while(n>0){
		if(n%2==1){
			r=add(r,P2, curve);
		}
		P2=add(P2, P2, curve);
		n=n/2;
	}
	return r;

}
int main(){
	//struct coord P1, P2;
	struct EC curve;

	curve.a=497;
	curve.b=1768;
	curve.p=9739;
/*
	P1.x=5274;
	P1.y=2841;
	
	P2.x=8669;
	P2.y=740;
	struct coord res= add(P1,P2, curve);
	printf("(%d, %d)\n",res.x, res.y);*/

	struct coord P,res;
	P.x=5323;
	P.y=5438;
	res=mul(P, 1337, curve);
	printf("%d, %d", res.x, res.y);
	return 0;
}
