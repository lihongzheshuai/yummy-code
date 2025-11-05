#include<bits/stdc++.h>
using namespace std;
string a[105];
bool is_str_sorted(string str) {
	return is_sorted(str.begin(),str.end());
}
int main() {
	int t;
	cin >> t;
	for(int i = 0; i<t; i++) {
		int n;
		cin >> n;
		bool flag = true;
		for(int j = 0; j<n; j++) {
			cin >> a[j]; 	
		}
		for (int j = 0; j < n ; j++) {
			if (!is_str_sorted(a[j])) {
				flag = false;
			}
		}
		sort(a,a+n);
		for(int j = 0;j<n-1;j++){
			if(!(a[j][a[j].length()-1]<=a[j+1][0])){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "1"<<"\n";
		}else{
			cout << "0"<<"\n";
		}
	}
}
