#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	long long n;
	scanf("%d", &n);
	long long ans = 0;//long long�� ��Ϊ��int���ܳ��ܲ��ˡ� ��nΪ�������ʱ�ٳ�3���ܻ���int���ط�Χ�� 
	long long sum = 0;
	while(n != 1){
		if(n % 2 != 0){
			ans = n * 3 + 1;
			cout << n << "*3+1=" << ans << "\n";
			n = ans;
		}else{
			sum = n >> 1;
			cout << n << "/2=" << sum << "\n";
			n = sum;
		}
	}
	printf("End");
	return 0;
}
