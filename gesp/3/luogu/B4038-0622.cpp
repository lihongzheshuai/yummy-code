#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		int a;
		cin >> a;
		int b[a];
		int count = 0;
		for(int j = 0;j<a;j++){
			cin >> b[j];
			count += b[j];
		}
		int y = b[0];
		bool flag = true;
		for(int j = 0;j<a;j++){
			int u = count - y;
			if(y == u){
				flag = true;
			}else{
				flag = false;
				y += b[j+1];
			}
		}
		if(flag){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
} 
