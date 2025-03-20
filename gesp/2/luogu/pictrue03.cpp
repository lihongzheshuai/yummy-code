#include<iostream>
using namespace std;
int main(){
	int n;
	cin >>n;
	int ans = 1;
	for(int i = 1;i<=n;i++){
		for(int i = 1;i<=ans;i++){
			cout << "*";
		}
		ans++;
		cout << endl;
	}	 
	return 0;
} 
