#include<bits/stdc++.h>
using namespace std;
int a[2005];
int b[2005];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	int m;
	cin >> m;
	int l;
	int count = 0;
	for(int i = 0;i<m;i++){
		cin >> l;
		int ans = 0;
		if(i==0){
			b[0] = a[l];
			cout << 0 << "\n";
			count++;
			continue;	
		}
		bool flag = true;
		int time = 1;
		for(int j = 1;j<count;j++){
			if(b[j]==b[j-1]){
				time++;
				continue;
			}
			flag = false;
			break;
		}
		if(flag&&time!=0){
			cout << 1 << "\n";
			b[count] = a[l];
			count++;
			sort(b,b+count); 
			continue;
		}
		for(int j = count-1;j>=0;j--){
			if(a[l]>=b[j]){
				cout << ans <<"\n";
				b[count] = a[l];
				count++;
				break;
			}else{
				ans++;
			}
			if(j==0){
				cout << ans << "\n";
				b[count] = a[l];
				count++;
			}
		}
		sort(b,b+count); 
	}
	return 0;
} 
