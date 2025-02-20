#include<iostream>
using namespace std;
int main(){
	long long x;
	cin >> x;
	for(long long i = x;i!=0;){
		long long j = i;
		while(j != 0){
			if((j%10==2&&(j/10)%10==6)||j%62==0){
				cout << "Yes";
				return 0;
			}
			j /= 10;
		}
		i/=10;
	}
	cout << "No";
	return 0;
}
