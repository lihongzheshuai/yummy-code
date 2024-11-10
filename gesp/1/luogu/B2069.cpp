#include<cstdio>
int main(){
	int n;
	scanf("%d", &n);
	int a1 = 1;
	int a2 = 2;
	int b1, b2;
	b1 = 2;
	b2 = 3;
	double m;
	double z;
	double sum = 0;
	double s1 = (double)b1 / (double)a1;
	double s2 = (double)b2 / (double)a2 + s1;
	if(n == 1){
		printf("%.4f", s1);
	} else if(n == 2) {
		printf("%.4f", s2);
	} else{
		for(int i = 3;i <= n;i++){
		m = a2 + a1;
		a1 = a2;
		a2 = m;
		z = b2 + b1;
		b1 = b2;
		b2 = z;		
		sum += (double) z / m;
		}
		printf("%.4f", sum + s2);
	}	
	return 0; 
} 
