#include<iostream>
#include<string>
using namespace std;
int m[145];
int main(){
	int n;
	cin >> n;
	string k;
	cin >> k;
	for(int i = 0;i<k.length();i++){
		m[(int)(k[i])]++;
		if(m[(int)(k[i])]==n){
			cout << k[i];
			return 0;
		}
	}
	cout << "No";
	return 0;
} 
