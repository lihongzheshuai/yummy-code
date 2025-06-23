#include<iostream>
using namespace std;
int z[1000];
int main(){
	int n;
	cin >> n;
	int n_1 = n;
	int ans = 1;
	for(int i = 0;;i++){
		if(n == 1){
			break;
		}
		if(n % 2 != 0){
			n = n * 3 + 1; 
			z[i] = n;
		}else{
			n /= 2;
			z[i] = n;
		}
		ans++;
	}
	for(int i = ans - 2;i >= 0;i--){
		cout << z[i] << " ";
	}
	cout << n_1;
	return 0;
} 
