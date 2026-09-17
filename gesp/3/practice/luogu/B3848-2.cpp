#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[100005];
	int count = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	int x;
	cin >> x;
	for(int i = 0;i<n;i++){
		if(x >= a[i]){
			count++;
			x -= a[i];
		}else{
			continue;
		}
	}
	cout << count;
	return 0;
}
