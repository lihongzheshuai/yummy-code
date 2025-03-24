#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 1;
	int y = 1;
	for(int i = 1;i<=n;i++){
		ans+=2;
	}
	ans = (ans-1)/2-1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=ans;j++){
			cout << " ";
		}
		for(int g=1;g<=y;g++){
			cout << "*";
		}
		for(int u = 1;u<=ans;u++){
			cout << " ";
		}
		ans--;
		y+=2;
		cout << endl;
	}
	return 0; 
} 
