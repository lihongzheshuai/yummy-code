#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	string b;
	int c = 0;
	string g = {0};
	for(int i = 1;i<=n;i++){
		cin >> a >> b;
		if(a>c){
			g = b;
			c = a;
		}
	}
	cout << g;
	return 0;
} 
