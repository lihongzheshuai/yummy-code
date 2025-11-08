#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long count = 0;
	for(int i = n;i>=1;i--){
		count+=i*i;
	}
	cout << count;
	return 0;
}
