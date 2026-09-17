#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	char a;
	int count = 0;
	for(int i = 0;i < n;i++){
		cin >> a;
		if(a <= 'z'&&a>='a'){
			count += a-('a'-1);
		}else{
			count -= a;
		}
	}
	cout << count;
	return 0;
}
