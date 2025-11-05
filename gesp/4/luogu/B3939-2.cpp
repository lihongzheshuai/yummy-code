#include<iostream>
using namespace std;

bool is_prime(int num) {
	bool flag = true;
	for(int i = num - 1;i>=2;i--){
		if(num % i ==0){
			flag = false;		
		}
	}
	return flag;
} 

bool is_abs_prime(int x) {
	bool flag = true;
		if(!is_prime(x))
			flag = false;// 判断x是不是素数 
	
	if(flag) {
		int c = x % 10;
		int d = x / 10;
		int e = c*10+d;
		if(!is_prime(e))
			flag = false;// 判断交换后的数是不是素数
		 
	}
		return flag;
}
int main() {
	int a1, b1;
	cin >> a1 >> b1;
	for(int i = a1;i <= b1;i++){
		if(is_abs_prime(i)){
			cout << i << endl;
		}
	}
	return 0;
}
