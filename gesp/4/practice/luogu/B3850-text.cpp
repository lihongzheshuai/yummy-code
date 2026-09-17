#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		long long a;
		cin >> a;
		int count = 0;
		for(int j = 1;; j++) {
			int h = a % 10;
			if(j % 2 != 0) {
				int b = h;
				int u = b * 7;
				if(u>9) { 
					for(int k = 0;; k++) {
						int ans = 0;
						while(u!=0) {
							ans+=u%10;
							u/=10;
						}
						if(ans<=9) {
							count+=ans;
							break;
						} else {
							u = ans;
						}
					}
				} else {
					count += u;
				}
				
			}else{
				count+=h;
			}
			a /= 10;
			if(a == 0){
				break;
			} 
		}
		if(count%8==0) {
			cout << "T" << "\n";
		} else {
			cout << "F" << "\n";
		}
	}
	return 0;
}
