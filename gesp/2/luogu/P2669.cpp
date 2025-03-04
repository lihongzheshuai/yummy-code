#include<iostream>
using namespace std;
int main(){
	int k;
	cin >> k;
	long long sum = 0;
	int cur = 1;
	for(int i =1;i<=k;) {
		if(i+cur-1<=k){
			sum+=cur*cur;
		}else{
			sum+=cur*(k-i+1);
	}
	i+=cur;
	cur++;
}	
	cout << sum;
	return 0;
} 
