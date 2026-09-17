#include<bits/stdc++.h>
using namespace std;
int a[3005];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 0;i<n-1;i++){
		bool flag = false;
		for(int j = 0;j<n-i-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				flag = true;
			}
		}
		if(!flag){
			break;
		}
	}
	for(int i = 0;i<n;i++){
		cout << a[i] << " "; 
	}
	return 0;
}
