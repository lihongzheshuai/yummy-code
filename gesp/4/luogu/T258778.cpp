#include<iostream>
using namespace std;
int n;
bool zhishu(int num) {
	bool flag = true;
	for(int i = 2;i*i<=num;i++){
		if(num % i == 0){
			flag = false;
		}
	}
	return flag;
}

int main(){
	int count = 0;
	cin >> n;
	int ans = 0;
	for(int i = 2;i<=n;i++){
		bool flag = zhishu(i);
		if(flag){
			ans += i;
			if(ans <= n){
				cout << i << "\n";
				count++;
			}else{
				break;
			}
		}else{
		    continue;
		}
	}
	cout << count;
	return 0;
} 
