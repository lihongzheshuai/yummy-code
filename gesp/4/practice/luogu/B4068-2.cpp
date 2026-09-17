#include<bits/stdc++.h>
using namespace std;
int a[3005];
int main(){
	int n;
	cin >> n;
	int count = 2;
	int last = 1;
	cout << 1 << " ";
	a[1] = 1;
	for(int i = 2;i<=n;i++){
		
		
		
		if(last-i>0){
			bool flag = false;
			for(int j = 1;j<i;j++){
				if(last-i==a[j]){
					a[i] = last+i;
					flag = true;
				}
			}
			if(!flag){
				a[i] = last - i;
			}
		}else{
			a[i] = last + i;
		}
		last = a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 2;i<=n;i++){
		cout << a[i] << " "; 
	}
	return 0;
}
