#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		int m = 0;
		int t;
		cin >> t;
		int a[t];
		for(int j = 0;j<t;j++){
			cin >> a[j];
			if(a[j]>m){
				m = a[j];
			}
		}
		 bool flag = true;
		 for(int j = 0;j<t;j++){
		 	if(m % a[j] == 0){
		 		flag = true;
			 }else{
			 	flag = false;
			 	break;
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
