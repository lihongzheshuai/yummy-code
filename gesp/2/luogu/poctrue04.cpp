#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=ans;j++){
			cout << "*";
		}
		ans--;
		cout << endl;
	}
	return 0;
}
