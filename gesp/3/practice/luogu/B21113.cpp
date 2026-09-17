#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	cin >> n;
	for(int i = 0;i<n.length();i++){
		int y = (int)n[i]+ (int)n[i+1];
		if(i==n.length()-1){
			y=(int)n[i]+(int)n[0];
			cout << (char)y;
			break;
		}
		cout << (char)y; 
	}
	return 0;	
}
