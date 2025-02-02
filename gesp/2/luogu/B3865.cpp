#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int result = n;
	for(int i = 1;i <= n;i++){
		for(int j = n;j >= 1;j--){
			if(j == i || j == n - i + 1){
				cout << "+";
			}else{
				cout << "-";
			}
		}
		cout << endl;
	}
}
