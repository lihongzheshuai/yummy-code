#include<iostream>
using namespace std;
int main(){
	int n, d;
	cin >> n >> d; 
	int a[n];
	int b;
	int count = 0;
	for(int i = 0;i<n;i++){
		a[i] = 0;
	} 
	for(int i = 0;i<d;i++){
		count++;
		cin >> b;
		a[b]+=count;
	} 
	for(int i = 0;i<n;i++){
		cout << a[i]<<" ";
	}
	return 0;
}
