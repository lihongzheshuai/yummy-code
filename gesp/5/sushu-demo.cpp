#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool sushu(int x){
	bool flag = true;
	if(x==0||x==1){
		return false;
	}
	if(x==2){
		return true;
	}
	for(int i = 2;i<x;i++){
		if(x%i==0){
			flag = false;
		}
	}
	if(flag){
		return true;
	}else{
		return false;
	}
}
int main(){
	int n;
	cin >> n;
	cout << sushu(n) << endl;
	for(int i = 0;i<n;i++){
		a[i] = sushu(i);
	}
	for(int i = 0;i<n;i++){
		if(a[i] == 1){
			cout << i << " ";
		}
	}
	return 0;
} 
