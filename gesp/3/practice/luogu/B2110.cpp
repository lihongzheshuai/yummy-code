#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	int a[26]={0};
	cin >> n;
	int l = (int)'a'; 
	for(int i = 0;i<n.length();i++){
		int k = (int) n[i]; 
		a[k - l]++;
	}
	for(int i = 0;i<n.length();i++){
		int k = (int) n[i]; 
		if(a[k-l]==1){
			cout<<n[i];
			return 0;
		} 
	}
	cout << "no";
	return 0;
} 
