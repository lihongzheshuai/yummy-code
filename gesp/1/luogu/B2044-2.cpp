#include<iostream>
using namespace std;
int main(){
	int a;
	int ans = 0;
	for(int i = 1;i <= 3;i++){
		cin >> a;
		if(a < 60){
			ans += 1;
		}
	}
	if(ans == 1){
		cout << "1";
	}else{
		cout<< "0";
	}
	return 0;
}
